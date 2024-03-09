CC = gcc
CFLAGS = -g -Wall
BINS = trees

all: $(BINS)

%: %.c 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(BINS)