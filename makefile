TARGET ?= rozue

BUILD_DIR := build
TEST_DIR := test
SRC_DIR := src
BIN_DIR := bin

SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FILES := $(subst $(SRC_DIR)/,,$(SRC_FILES:%.cpp=$(BUILD_DIR)/%.o))
DEP_FILES := $(OBJ_FILES:.o=.d)

CXX := clang++
INCLUDE_FLAGS := -I $(SRC_DIR)
WARNING_FLAGS := \
	-Werror \
	-Wall \
	-Wextra \
	-Wwrite-strings \
	-Winit-self \
	-Wcast-align \
	-Wcast-qual \
	-Wold-style-cast \
	-Wpointer-arith \
	-Wstrict-aliasing \
	-Wformat=2 \
	-Wuninitialized \
	-Wmissing-declarations \
	-Woverloaded-virtual \
	-Wnon-virtual-dtor \
	-Wctor-dtor-privacy \
	-Wno-long-long \
	-Weffc++

LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system -pthread
FLAGS := $(INCLUDE_FLAGS) $(WARNING_FLAGS) -MMD -MP -std=c++14 -pedantic -ferror-limit=5 -g -O0

.PHONY : clean test

$(BIN_DIR)/$(TARGET) : $(OBJ_FILES)
	@echo "Linking..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(OBJ_FILES) -o $@ $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	@echo "Building $@..."
	@mkdir -p $(dir $@)
	@$(CXX)  $(FLAGS) $(CXXFLAGS) -c $< -o $@

clean :
	@echo "Cleaning up..."
	@$(RM) -r $(BIN_DIR) $(BUILD_DIR)
	@$(MAKE) -C ./$(TEST_DIR) clean

test : $(OBJ_FILES)
	@echo "Making tests..."
	@$(MAKE) -C ./$(TEST_DIR) run

-include $(DEP_FILES)
