DEST=build
FLAGS=-Wall -Wextra -std=c++11

TEST_DIR=tests
TEST_BIN=$(DEST)/test_bin
TEST_FLAGS=--durations yes

# Paths to all test files
TEST_SRCS=$(shell find $(TEST_DIR) -name '*.cpp')

$(TEST_BIN): $(TEST_SRCS)
	@mkdir -p $(DEST)
	@echo -e "\n---------------\nCompiling tests\n---------------\n"
	$(CXX) $(FLAGS) -o $@ $^

test: $(TEST_BIN)
	@echo -e "\n-------------\nRunning tests\n-------------\n"
	$(TEST_BIN) $(TEST_FLAGS)

docs:
	@echo -e "\n--------------\nCompiling docs\n--------------\n"
	doxygen doxyfile

clean:
	rm -rf $(DEST)

.PHONY: test clean docs
