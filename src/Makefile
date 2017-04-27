program_NAME := ../StratuxPay
CC = gcc
program_C_SRCS := $(wildcard *.c)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_OBJS := $(program_C_OBJS)
CFLAGS = -std=c99 -Wall -Wextra -pedantic

.PHONY: all clean distclean
all:    $(program_NAME)
$(program_NAME): $(program_OBJS)
	$(CC) $(program_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean