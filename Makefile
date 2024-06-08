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
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    CC := $(CC_clang)
else
    CC := $(CC_gcc)
endif

CFLAGS = -g -Wall

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)
	rm -rf $(BUILD_DIR)
