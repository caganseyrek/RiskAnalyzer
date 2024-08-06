# Compiler and flags
COMPILER = g++
COMPILER_FLAGS = -Wall -Wextra -std=c++17 -Iincludes

# Source Directory and Files
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Targets
RiskAnalyzer: $(SRC_FILES)
	$(COMPILER) $(COMPILER_FLAGS) -o RiskAnalyzer $^
