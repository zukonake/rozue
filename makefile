SOURCE_DIR = src
OBJ_DIR = bin
DEPEND_DIR = depend
INCLUDE_DIR = include
LIB_DIR = lib

TEST_DIR = test

TARGET = rozue

CPP_FILES = $(shell find $(SOURCE_DIR) -type f -name "*.cpp" -printf '%p ')
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(patsubst %.cpp,%.o,$(notdir $(CPP_FILES))))

CXX = clang++
DEBUG_FLAGS = -g -O0 -DDEBUG
WARNING_FLAGS = -Wall -Wextra -ferror-limit=3
STD = -std=c++14 -pedantic
INCLUDES = -I $(SOURCE_DIR) -I $(INCLUDE_DIR)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS) -L $(LIB_DIR) $(LDLIBS)
CXXFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS)

.PHONY : clean test

$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(OBJ_FILES) -o $@

.SECONDEXPANSION:
$(OBJ_DIR)/%.o : $$(shell find $(SOURCE_DIR) -type f -name %.cpp)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEPEND_DIR)
	$(CXX) $(CXXFLAGS) -MM $< > $(DEPEND_DIR)/$*.d
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@sed -i '1s/^/$(OBJ_DIR)\//' $(DEPEND_DIR)/$*.d

clean :
	$(RM) -r $(OBJ_DIR) $(DEPEND_DIR) $(TARGET)
	$(MAKE) -C ./$(TEST_DIR) clean

test : $(OBJ_FILES)
	$(MAKE) -C ./$(TEST_DIR)

-include $(subst $(OBJ_DIR)/,$(DEPEND_DIR)/,$(patsubst %.o,%.d,$(OBJ_FILES)))
