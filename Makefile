CC=cc
CFLAGS=-Wall -Wextra -O2 `pkg-config --cflags libnm`
LDFLAGS=`pkg-config --libs libnm`

src=barc.c $(wildcard segments/*.c)
obj=$(src:.c=.o)

barc: $(obj)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) barc
