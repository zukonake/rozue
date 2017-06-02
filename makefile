SOURCE_DIR = src
OBJ_DIR = bin
DEPEND_DIR = depend
INCLUDE_DIR = include
LIB_DIR = lib

TEST_DIR = test

TARGET = rozue

CPP_FILES = $(shell find $(SOURCE_DIR) -type f -name "*.cpp" -printf '%p ')
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(patsubst %.cpp,%.o,$(subst $(SOURCE_DIR)/,,$(CPP_FILES))))

DEBUG_FLAGS = -g -O0 -DDEBUG
WARNING_FLAGS = -Wall -Wextra -fmax-errors=3
STD = -std=c++1z -pedantic
INCLUDES = -I $(SOURCE_DIR) -I $(INCLUDE_DIR)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS) -L $(LIB_DIR) $(LDLIBS)
CXXFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS)

.PHONY : clean test

$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(OBJ_FILES) -o $@

.SECONDEXPANSION:
$(OBJ_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@mkdir -p $(subst $(OBJ_DIR),$(DEPEND_DIR),$(dir $@))
	$(CXX) $(CXXFLAGS) -c $< -o $@
	$(CXX) $(CXXFLAGS) -MM $< > $(subst $(OBJ_DIR),$(DEPEND_DIR),$*.d)
	@sed -i '1s/^/$(OBJ_DIR)\//' $(subst $(OBJ_DIR),$(DEPEND_DIR),$*.d)

clean :
	$(RM) -r $(OBJ_DIR) $(DEPEND_DIR) $(TARGET)
	$(MAKE) -C ./$(TEST_DIR) clean

test : $(OBJ_FILES)
	$(MAKE) -C ./$(TEST_DIR)

ifneq ("$(wildcard $(DEPEND_DIR))","")
	include $(subst $(OBJ_DIR),$(DEPEND_DIR),$(patsubst %.o,%.d,$(OBJ_FILES)))
endif
