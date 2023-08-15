# Makefile for compiling main.c and saving the output in the dist folder

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra
O=detect

# Directories
SRC_DIR := .
DIST_DIR := dist

# Source file
SRC := $(SRC_DIR)/main.c

# Output executable
EXE := $(DIST_DIR)/detect

# Targets and rules
.PHONY: all clean

all: $(EXE)

$(EXE): $(SRC) | $(DIST_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(DIST_DIR):
	mkdir -p $(DIST_DIR)

clean:
	rm -rf $(DIST_DIR)