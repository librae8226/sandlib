CC := gcc

cFILES := \
	longjmp.c

OBJS:= $(cFILES:%.c=%.o)

all: longjmp

longjmp: $(OBJS)
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $^ -c -o $@

clean:
	rm -f *.o longjmp
