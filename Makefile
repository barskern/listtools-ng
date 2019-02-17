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

# Combine all cpp files into a single variable
ALL_SRCS=$(TEST_SRCS) $(EXAMPLE_SRCS) listtools-ng.h

$(DEST)/test_bin: $(TEST_SRCS)
	@mkdir -p $(DEST)
	@echo "---------------"
	@echo "Compiling tests"
	@echo "---------------"
	$(CXX) $(FLAGS) -o $@ $^

$(DEST)/%: $(EXAMPLE_DIR)/%.cpp
	@mkdir -p $(DEST)
	@echo "------------------"
	@echo "Compiling examples"
	@echo "------------------"
	$(CXX) $(FLAGS) -o $@ $^

test: $(DEST)/test_bin
	@echo "-------------"
	@echo "Running tests"
	@echo "-------------"
	$(DEST)/test_bin $(TEST_FLAGS)

examples: $(EXAMPLE_BINS)
	@echo "----------------"
	@echo "Running examples"
	@echo "----------------"
	@$(foreach bin,$(EXAMPLE_BINS),echo "Running \"$(patsubst $(DEST)/%,%,$(bin))\""; $(bin) $(EXAMPLE_FLAGS); echo "---";)

docs:
	@echo "--------------"
	@echo "Compiling docs"
	@echo "--------------"
	doxygen Doxyfile

check-format:
	@echo "-------------------"
	@echo "Checking formatting"
	@echo "-------------------"
	@for f in $(ALL_SRCS); do \
		echo "clang-format $$f" ; \
		clang-format -output-replacements-xml "$$f" | grep -c "<replacement " >/dev/null ; \
		if [ $$? -ne 1 ]; then \
			echo "Error: Filen '$$f' har ikke riktig formattering" ; \
			exit 1 ; \
		fi \
	done

format:
	@echo "----------------------"
	@echo "Formatting sourcefiles"
	@echo "----------------------"
	clang-format -i $(EXAMPLE_SRCS) $(TEST_SRCS) listtools-ng.h

clean:
	rm -rf $(DEST)

.PHONY: test clean docs examples format check-format
