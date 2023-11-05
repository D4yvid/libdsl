TARGET = build/libdsl.so
SRC = $(shell find src -type f -name '*.c')
OBJ = $(SRC:.c=.o)

CC := clang
CFLAGS += -Wall -Werror -Wpedantic -Wno-unused-parameter -Wno-unused-variable \
				  -Wno-incompatible-library-redeclaration -nostdlib -O2

LFLAGS += -shared

%.o: %.c
	@printf "\033[1m==>\033[0m Building object $@\n"
	@$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	@printf "\033[1m==>\033[0m Linking dynamic library \033[32m$(TARGET)\033[0m\n"
	@mkdir -p build
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LFLAGS)

test:
	@$(MAKE) -C tests

clean:
	@printf "\033[1m==>\033[0m Cleaning up...\n"
	@rm -rf $(OBJ) $(TARGET)
	@$(MAKE) -C tests clean > /dev/null

all: build test
