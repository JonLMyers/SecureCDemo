CFLAGS = -std=c99 -Wall -Wextra -pedantic

all: input.c
	gcc $(CFLAGS) input.c -o StratuxPay.out