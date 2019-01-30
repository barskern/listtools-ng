DEST=build
FLAGS=-Wall -Wextra -std=c++11

TEST_DIR=tests
TEST_FLAGS=--durations yes

# Paths to all test files
TEST_SRCS=$(shell find $(TEST_DIR) -name '*.cpp')

EXAMPLE_DIR=examples
EXAMPLE_FLAGS=

# Paths to all example files
EXAMPLE_SRCS=$(shell find $(EXAMPLE_DIR) -name '*.cpp')
EXAMPLE_BINS=$(patsubst $(EXAMPLE_DIR)/%.cpp,$(DEST)/%,$(EXAMPLE_SRCS))

$(DEST)/test_bin: $(TEST_SRCS)
	@mkdir -p $(DEST)
	@echo -e "\n---------------\nCompiling tests\n---------------\n"
	$(CXX) $(FLAGS) -o $@ $^

$(DEST)/%: $(EXAMPLE_DIR)/%.cpp
	@mkdir -p $(DEST)
	@echo -e "\n------------------\nCompiling examples\n------------------\n"
	$(CXX) $(FLAGS) -o $@ $^

test: $(DEST)/test_bin
	@echo -e "\n-------------\nRunning tests\n-------------\n"
	$(DEST)/test_bin $(TEST_FLAGS)

examples: $(EXAMPLE_BINS)
	@echo -e "\n----------------\nRunning examples\n----------------\n"
	@$(foreach bin,$(EXAMPLE_BINS),echo "Running \"$(patsubst $(DEST)/%,%,$(bin))\""; $(bin) $(EXAMPLE_FLAGS); echo "---";)

docs:
	@echo -e "\n--------------\nCompiling docs\n--------------\n"
	doxygen doxyfile

clean:
	rm -rf $(DEST)

.PHONY: test clean docs examples
