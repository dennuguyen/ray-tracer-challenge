# Makefile pattern thanks to kebs
# Author: kebs
# Date: 25 May 2014
# License: CC BY-SA 3.0
# URL: https://stackoverflow.com/a/23859765/13133452

# Compiler Flags
CC      = g++
CFLAGS  = -Wall -Werror -g -Iinclude
LDFLAGS = -Llib

# Directories
SRC_DIR_EXE = main
SRC_DIR_LIB = src
OBJ_DIR_EXE = obj/exe
OBJ_DIR_LIB = obj/lib
BIN_DIR     = bin
HEAD_DIR    = include
TEST_DIR 	= test

# Files
SRC_FILES_EXE = $(wildcard $(SRC_DIR_EXE)/*.cpp)
SRC_FILES_LIB = $(wildcard $(SRC_DIR_LIB)/*.cpp)
TEST_FILES    = $(wildcard $(TEST_DIR)/*.cpp)
HEAD_FILES    = $(wildcard $(HEAD_DIR)/*.hpp)

# Objects
OBJ_FILES_EXE  = $(patsubst $(SRC_DIR_EXE)/%.cpp, $(OBJ_DIR_EXE)/%.o, $(SRC_FILES_EXE))
OBJ_FILES_LIB  = $(patsubst $(SRC_DIR_LIB)/%.cpp, $(OBJ_DIR_LIB)/%.o, $(SRC_FILES_LIB))
OBJ_FILES_TEST = $(addprefix $(OBJ_DIR_LIB)/, $(notdir $(patsubst %.cpp, %.o, $(TEST_FILES))))

# Executables
EXEC_FILES = $(patsubst $(SRC_DIR_EXE)/%.cpp, $(BIN_DIR)/%, $(SRC_FILES_EXE))

.PHONY: all directories exe lib bin show clean

all: clean directories exe lib bin

# Create directories
directories:
	@mkdir -p obj/exe
	@mkdir -p obj/lib
	@mkdir -p bin

# Compile exe
exe: $(OBJ_FILES_EXE)
$(OBJ_DIR_EXE)/%.o: $(SRC_DIR_EXE)/%.cpp $(HEAD_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)

# Compile lib
lib: $(OBJ_FILES_LIB) $(OBJ_FILES_TEST)
$(OBJ_DIR_LIB)/%.o: $(SRC_DIR_LIB)/%.cpp $(HEAD_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJ_DIR_LIB)/%.o: $(TEST_DIR)/%.cpp $(HEAD_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)

# Link
bin: $(EXEC_FILES)
$(BIN_DIR)/%: $(OBJ_DIR_EXE)/%.o
	$(CC) -o $@ -s $(subst $(BIN_DIR)/, $(OBJ_DIR_EXE)/,$@).o $(OBJ_FILES_LIB) $(OBJ_FILES_TEST) $(LDFLAGS)

show:
	@echo ""
	@echo "HEAD_FILES     = $(HEAD_FILES)"
	@echo "SRC_FILES_EXE  = $(SRC_FILES_EXE)"
	@echo "SRC_FILES_LIB  = $(SRC_FILES_LIB)"
	@echo "TEST_FILES     = $(TEST_FILES)"
	@echo ""
	@echo "OBJ_FILES_EXE  = $(OBJ_FILES_EXE)"
	@echo "OBJ_FILES_LIB  = $(OBJ_FILES_LIB)"
	@echo "OBJ_FILES_TEST = $(OBJ_FILES_TEST)"
	@echo ""
	@echo "EXEC_FILES     = $(EXEC_FILES)"
	@echo ""

clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR_EXE)/*.o
	rm -rf $(OBJ_DIR_LIB)/*.o
