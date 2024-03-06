INCLDIR = ./include
CC = gcc
CFLAGS = -O2 -I$(INCLDIR)
TARGET = 7oppgave4
OBJDIR = obj

# List of source files
SRCS = $(wildcard *.c)

# Generate list of object files from source files
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Rule to make target executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -L. -l_myalloc

# Rule to compile each source file into object files
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Rule to create the object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Rule to create library
lib: $(OBJS)
	ar rcs lib_myalloc.a $^

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(TARGET) lib_myalloc.a
