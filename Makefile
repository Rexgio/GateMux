CC := gcc

CFLAGS := -Wall -Wextra -Wpedantic -std=c17 -Iinclude
LDFLAGS :=
LDLIBS :=

TARGET := app

SRC := $(wildcard src/*.c)
OBJ := $(SRC:src/%.c=build/%.o)
DEP := $(OBJ:.o=.d)

.PHONY: all clean run debug rebuild

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -O0
debug: clean $(TARGET)

rebuild: clean all

clean:
	rm -rf build $(TARGET)
