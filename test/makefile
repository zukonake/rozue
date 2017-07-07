SOURCE_DIR = src
OBJ_DIR = bin
DEPEND_DIR = depend
INCLUDE_DIR = include
EXTERNAL_DIR = ..
EXTERNAL_SOURCE_DIR = $(EXTERNAL_DIR)/src
EXTERNAL_OBJ_DIR = $(EXTERNAL_DIR)/bin
INCLUDE_DIR = $(EXTERNAL_DIR)/include
LIB_DIR = lib

TARGET = test.out

CPP_FILES = $(shell find $(SOURCE_DIR) -type f -name "*.cpp" -printf '%p ')
OBJ_FILES = $(subst $(SOURCE_DIR),$(OBJ_DIR),$(patsubst %.cpp,%.o,$(CPP_FILES)))
EXTERNAL_CPP_FILES = $(shell find $(EXTERNAL_SOURCE_DIR) -type f -name "*.cpp" -printf '%p ')
EXTERNAL_OBJ_FILES = $(subst $(EXTERNAL_SOURCE_DIR),$(EXTERNAL_OBJ_DIR),$(patsubst %.cpp,%.o,$(EXTERNAL_CPP_FILES)))

CXX = clang++
DEBUG_FLAGS = -g -O0
WARNING_FLAGS = \
	-ferror-limit=5 \
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
STD = -std=c++14 -pedantic
INCLUDES = -I $(SOURCE_DIR) -I $(INCLUDE_DIR)
LDLIBS = -lboost_unit_test_framework
LDFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS) -L $(LIB_DIR) $(LDLIBS)
CXXFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS)

.PHONY : clean

$(TARGET) : $(OBJ_FILES) $(EXTERNAL_OBJ_FILES)
	$(CXX) $(LDFLAGS) $(OBJ_FILES) $(EXTERNAL_OBJ_FILES) -o $@

$(OBJ_DIR)/%.o : $(SOURCE_DIR)/%.cpp $(DEPEND_DIR)/%.d
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIR)/$*.cpp -o $@

$(DEPEND_DIR)/%.d : $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MM $< > $@
	@sed -i "1s~^~$(subst $(DEPEND_DIR),$(OBJ_DIR),$(dir $@))~" $@

clean :
	$(RM) -r $(OBJ_DIR) $(DEPEND_DIR) $(TARGET)

ifneq ($(MAKECMDGOALS),clean)
-include $(subst $(OBJ_DIR),$(DEPEND_DIR),$(patsubst %.o,%.d,$(OBJ_FILES)))
endif
