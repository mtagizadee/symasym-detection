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

# Targets and rules
.PHONY: all clean

main: $(SRC) | $(DIST_DIR)
	gcc main.c bmp/bmp.c ${CFLAGS} -o $(DIST_DIR)/$(O)

$(DIST_DIR):
	mkdir -p $(DIST_DIR)

clean:
	rm -rf $(DIST_DIR)