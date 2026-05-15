CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wshadow -Wconversion -O0 -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -DLOCAL
LDFLAGS := -fsanitize=address

SRC_DIR := .
OBJ_DIR := objs
BIN_DIR := bin

TARGET := $(BIN_DIR)/main
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	@$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

.PHONY: run
run:
	@make all
	@./$(TARGET) < in.txt > out.txt
	@cat out.txt


.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
