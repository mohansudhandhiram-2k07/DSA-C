# Define multiple source directories
SRC_DIRS := linked-lists stack
BUILD_DIR := cbuild

CC := gcc
CFLAGS := -Wall -Wextra -g 

# 1. Collect all .c files from all directories
SRCS := $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

# 2. Generate executable paths (e.g., linked-lists/main.c -> cbuild/linked-lists/main)
EXES := $(patsubst %.c, $(BUILD_DIR)/%, $(SRCS))

all: $(EXES)

# 3. The Pattern Rule
# Matches 'cbuild/dir/file' to 'dir/file.c'
$(BUILD_DIR)/%: %.c
	@mkdir -p $(dir $@)
	@echo "Building $@..."
	$(CC) $(CFLAGS) $< -o $@

# 4. The Run Command
# Usage: make run TARGET=stack/my_file
run: all
	@if [ -z "$(TARGET)" ]; then \
		echo "Error: Specify TARGET (e.g., make run TARGET=stack/filename)"; \
	else \
		echo "Executing $(BUILD_DIR)/$(TARGET)..."; \
		./$(BUILD_DIR)/$(TARGET); \
	fi

clean:
	@echo "Cleaning artifacts..."
	@rm -rf $(BUILD_DIR)

.PHONY: all clean run