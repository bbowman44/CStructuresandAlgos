CC      := gcc
CFLAGS  := -std=c17 -Wall -Wextra -Wpedantic -Werror -g
SAN     := -fsanitize=address,undefined
INCLUDE := -Ilib
LIB_SRCS := $(wildcard lib/*.c)
EXAMPLE_SRCS := $(wildcard examples/*.c)
BINS := $(patsubst examples/%.c,build/%,$(EXAMPLE_SRCS))

all: $(BINS)

build/%: examples/%.c $(LIB_SRCS) | build
	$(CC) $(CFLAGS) $(SAN) $(INCLUDE) examples/$*.c $(LIB_SRCS) -o $@

build:
	mkdir -p build

run-%: build/%
	./build/$*

clean:
	rm -rf build

.PHONY: all clean