NAME=u

# Directories
SRCD=./source
BLDD=./build
OBJD=$(BLDD)/objects
DIRS=.

# Files
SRCS=$(foreach D,$(DIRS),$(wildcard $(SRCD)/$(D)/*.cpp))
OBJS=$(patsubst $(SRCD)/%.cpp,$(OBJD)/%.obj,$(SRCS))
BIN=$(BLDD)/$(NAME).exe

# Build
CC=clang++
CFLGS=-std=c++20 -O3
WFLGS=-Wall -Wextra
FLGS=$(CFLGS) $(WFLGS)

all:$(BIN)

r:$(BIN)
	clear
	$(BIN)

$(BIN):$(OBJS)
	$(CC) $^ -o $@ $(FLGS)

$(OBJD)/%.obj:$(SRCD)/%.cpp
	$(CC) -c $^ -o $@ $(FLGS)

c:$(BLDD)
	rm -rf $(OBJS) $(BIN)

f:
	clang-format -i $(SRCS) $(foreach D,$(DIRS),$(wildcard $(SRCD)/$(D)/*.h)

.PHONY:all r c f