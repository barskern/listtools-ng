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

# Get the modified files in feature branches
MODIFIED_SRCS=git diff master...HEAD --name-only --diff-filter=ACMRT listtools-ng.h examples/*.cpp tests/*.cpp

# Command which checks if all modified files are formatted correctly. This
# command will fail if any files are not formatted correctly. All filenames
# outputted from this command are NOT formatted correctly.
CHECK_FORMAT=$(MODIFIED_SRCS) | xargs -I {} sh -c 'clang-format -output-replacements-xml {} | grep -c "<replacement " >/dev/null && echo {}'

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

check-format:
	@echo -e "\n-------------------\nChecking formatting\n-------------------\n"
	@# If we get any files, some files are not formatted correctly so we exit 1
	@# within xargs.
	@$(CHECK_FORMAT) | xargs -I {} sh -c 'echo Filen er ikke formattert korrekt: {}; exit 1'

format:
	@echo -e "\n----------------------\nFormatting sourcefiles\n----------------------\n"
	clang-format -i $(EXAMPLE_SRCS) $(TEST_SRCS) listtools-ng.h

clean:
	rm -rf $(DEST)

.PHONY: test clean docs examples format check-format
