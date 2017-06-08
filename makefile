SOURCE_DIR = src
OBJ_DIR = bin
DEPEND_DIR = depend
INCLUDE_DIR = include
LIB_DIR = lib

TARGET = rozue

CPP_FILES = $(shell find $(SOURCE_DIR) -type f -name "*.cpp" -printf '%p ')
OBJ_FILES = $(subst $(SOURCE_DIR),$(OBJ_DIR),$(patsubst %.cpp,%.o,$(CPP_FILES)))

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
	-Wno-long-long
STD = -std=c++14 -pedantic
INCLUDES = -I $(SOURCE_DIR) -I $(INCLUDE_DIR)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS) -L $(LIB_DIR) $(LDLIBS)
CXXFLAGS = $(INCLUDES) $(STD) $(WARNING_FLAGS) $(DEBUG_FLAGS)

.PHONY : clean

$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(OBJ_FILES) -o $@

.SECONDEXPANSION:
$(OBJ_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@mkdir -p $(subst $(OBJ_DIR),$(DEPEND_DIR),$(dir $@))
	$(CXX) $(CXXFLAGS) -MM $< > $(DEPEND_DIR)/$*.d
	@sed -i "1s~^~$(dir $@)~" $(DEPEND_DIR)/$*.d
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) -r $(OBJ_DIR) $(DEPEND_DIR) $(TARGET)

-include $(subst $(OBJ_DIR),$(DEPEND_DIR),$(patsubst %.o,%.d,$(OBJ_FILES)))
