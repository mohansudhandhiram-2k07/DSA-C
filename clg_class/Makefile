CC := gcc
CFLAGS := -Wall -Wextra -g
BUILD_DIR := cbuild
SRC_DIRS := linked-lists stack queue tree 

# 1. Collect sources with paths
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# 2. Generate executable paths: cbuild/filename (no extension)
EXES := $(patsubst %.c,$(BUILD_DIR)/%,$(notdir $(SRCS)))

all: $(EXES)

# 3. Explicit rules for each directory to ensure correct mapping
define BOLD_RULE
$(BUILD_DIR)/%: $(1)/%.c
	@mkdir -p $$(BUILD_DIR)
	@echo "Compiling: $$< -> $$@"
	$$(CC) $$(CFLAGS) $$< -o $$@
endef

# Generate rules for every directory in SRC_DIRS
$(foreach dir,$(SRC_DIRS),$(eval $(call BOLD_RULE,$(dir))))

run: all
	@if [ -z "$(TARGET)" ]; then \
		echo "Usage: make run TARGET=stack_using_array"; \
	else \
		./$(BUILD_DIR)/$(TARGET); \
	fi

clean:
	@echo "Cleaning $(BUILD_DIR)..."
	@rm -rf $(BUILD_DIR)

.PHONY: all clean run