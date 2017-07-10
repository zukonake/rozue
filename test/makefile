TARGET ?= test.out

BUILD_DIR := build
SRC_DIR := src

SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FILES := $(SRC_FILES:%.cpp=$(BUILD_DIR)/%.o)
EXT_OBJ_FILES := $(shell find .. -name "*.o")
DEP_FILES := $(OBJ_FILES:.o=.d)

CXX := clang++
INCLUDE_FLAGS := -I $(SRC_DIR) -I ../src
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

LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system -lUnitTest++
FLAGS := $(INCLUDE_FLAGS) $(WARNING_FLAGS) -MMD -MP -std=c++14 -pedantic -ferror-limit=5

.PHONY : clean run

$(TARGET) : $(OBJ_FILES)
	@echo "Linking..."
	@$(CXX) $(OBJ_FILES) -o $@ $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR)/%.o : %.cpp
	@echo "Building $@..."
	@mkdir -p $(dir $@)
	@$(CXX)  $(FLAGS) $(CXXFLAGS) -c $< -o $@

clean :
	@echo "Cleaning up..."
	@$(RM) -r $(TARGET) $(BUILD_DIR)

run : $(TARGET)
	@echo "Running tests..."
	@./$(TARGET)

-include $(DEP_FILES)
