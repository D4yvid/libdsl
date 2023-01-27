TARGET = build/libdsl.so
SRC = $(wildcard src/*.c src/**/*.c)
OBJ = $(SRC:.c=.o)

CC := clang
CFLAGS = -ansi -Wall -Werror -Wpedantic -Wno-unused-parameter -Wno-unused-variable -Wno-incompatible-library-redeclaration -fPIC -nostdlib -I include
LFLAGS = -shared

%.o: %.c
	@echo "\033[2m==>\033[0m Building object $@"
	@$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	@echo "\033[2m==>\033[0m Linking dynamic library \033[32m$(TARGET)\033[0m"
	@mkdir -p build
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LFLAGS)

test:
	@$(MAKE) -C tests

clean:
	@echo "\033[2m==>\033[0m Cleaning up..."
	@rm -rf $(OBJ) $(TARGET)
	@$(MAKE) -C tests clean > /dev/null

all: build test
