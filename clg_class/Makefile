# Define multiple source directories
SRC_DIRS := linked-lists stack
BUILD_DIR := cbuild

CC := gcc
CFLAGS := -Wall -Wextra -g 

# 1. Collect all .c files using absolute-style wildcards
SRCS := $(wildcard linked-lists/*.c) $(wildcard stack/*.c)

# 2. Flatten the output names
# This turns 'stack/stack_using_array.c' into 'cbuild/stack_using_array'
EXES := $(addprefix $(BUILD_DIR)/, $(patsubst %.c,%,$(notdir $(SRCS))))

all: $(EXES)

# 3. Use VPATH so Make can find files inside the subdirectories
VPATH := $(SRC_DIRS)

# 4. Pattern Rule
# Note: we use $(notdir $<) to ensure the compiler gets the right filename from VPATH
$(BUILD_DIR)/%: %.c
	@mkdir -p $(BUILD_DIR)
	@echo "Building $@ from $<..."
	$(CC) $(CFLAGS) $< -o $@

# 5. Run Command
run: all
	@if [ -z "$(TARGET)" ]; then \
		echo "Error: Specify TARGET (e.g., make run TARGET=stack_using_array)"; \
	else \
		./$(BUILD_DIR)/$(TARGET); \
	fi

clean:
	@echo "Cleaning artifacts..."
	@rm -rf $(BUILD_DIR)

.PHONY: all clean run