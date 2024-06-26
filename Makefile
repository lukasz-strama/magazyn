TARGET = Magazyn

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CC_gcc := g++ # 🪟
CC_clang := clang++ # 🍏

# wybór kompilatora w zależności od systemu operacyjnego
ifeq ($(OS),Windows_NT)
	CC := $(CC_gcc)
	RM := del /Q
	MKDIR := mkdir
	RMDIR := rmdir /S /Q
else
	UNAME_S := $(shell uname -s)
	CC := $(if $(filter $(UNAME_S),Darwin),$(CC_clang),$(CC_gcc))
	RM := rm -f
	MKDIR := mkdir -p
	RMDIR := rm -rf
endif

CFLAGS = -g -Wall -I$(INCLUDE_DIR) -std=c++17

all: $(BUILD_DIR) $(TARGET)
	@$(info Compilation successful)

$(BUILD_DIR):
	@$(info Creating build directory)
	@$(MKDIR) $(BUILD_DIR)

$(TARGET): $(OBJS)
	@$(info Linking executable)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(info Compiling $<)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(info Cleaning...)
	@$(info Deleting object files)
	@FOR %%f IN ($(BUILD_DIR)\*.o) DO @IF EXIST %%f DEL /Q %%f
	@$(info Deleting executable)
	@IF EXIST $(TARGET).exe DEL /Q $(TARGET).exe
	@$(info Removing directory)
	@RMDIR $(BUILD_DIR) 2>nul || echo No build directory found.