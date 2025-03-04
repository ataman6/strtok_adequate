PREFIX = $(HOME)/.local

example: example.c
	$(CC) -Wall -Wextra -Werror -Wpedantic -std=c99 -o $@ $<
install:
	mkdir -p $(PREFIX)/include
	cp -t $(PREFIX)/include strtok_adequate.h
uninstall:
	rm -f $(PREFIX)/include/strtok_adequate.h
clean:
	rm -f example
