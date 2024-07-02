CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR := ./src
BUILD_DIR := build
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
EXEC_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(SRC_FILES))

all: $(EXEC_FILES)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ -lm

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
