TARGET_EXEC ?= planner.out

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

CXX := g++

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

CXXFLAGS := $(shell wx-config --cxxflags) -std=c++11
WX_LIBS := $(shell wx-config --libs)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(WX_LIBS)


# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

run:
	./build/$(TARGET_EXEC)

-include $(DEPS)

MKDIR_P ?= mkdir -p