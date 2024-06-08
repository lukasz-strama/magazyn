TARGET = Magazyn

SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Domyślny kompilator (GCC)
CC_gcc := g++
# Kompilator Clang dla systemu macOS
CC_clang := clang++
# Wybór kompilatora w zależności od systemu operacyjnego
ifeq ($(OS),Windows_NT)
    CC := $(CC_gcc)
    RM := del /Q
    MKDIR := mkdir
    RMDIR := rmdir /S /Q
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        CC := $(CC_clang)
        RM := rm -f
        MKDIR := mkdir -p
        RMDIR := rm -rf
    else
        CC := $(CC_gcc)
        RM := rm -f
        MKDIR := mkdir -p
        RMDIR := rm -rf
    endif
endif

CFLAGS = -g -Wall

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	cmd /c del /Q $(BUILD_DIR)\*.o
	cmd /c del /Q $(TARGET).exe
	cmd /c rmdir /S /Q $(BUILD_DIR)
else
	$(RM) $(wildcard $(BUILD_DIR)/*.o)
	$(RM) $(TARGET)
	$(RMDIR) $(BUILD_DIR)
endif