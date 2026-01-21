
SRC_DIR := cproject
BUILD_DIR := cbuild

CC := gcc
CFLAGS := -Wall -Wextra -g
SRCS := $(wildcard $(SRC_DIR)/*.c)

EXES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRCS))

all: $(EXES)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "Building $@..."
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "Cleaning artifacts..."
	@rm -rf $(BUILD_DIR)/*

.PHONY: all clean