TESTS = $(subst .c,,$(wildcard *.c))

CC := clang
CFLAGS = -I ../src
LFLAGS = -L ../build -ldsl

%: %.c
	@echo "\033[2m====>\033[0m Compiling test \033[32m$@\033[0m"
	@$(CC) -o $@ $< $(CFLAGS) $(LFLAGS)
	@echo "\033[2m====>\033[0m Running test \033[32m$@\033[0m"
	@LD_LIBRARY_PATH=../build ./$@

all: $(TESTS)

clean:
	rm -rf $(TESTS)
