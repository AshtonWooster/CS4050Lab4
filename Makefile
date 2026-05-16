
##############################################################################
# Makefile for A4 - "Bad Scantron"
# CMP_SC 4050
# Fall 2024
# By Jim Ries (RiesJ@missouri.edu)
##############################################################################

# Macros
CC = gcc
CPP = g++
CFLAGS = -Wall -Werror -c -g -std=c11 -I.
CPPFLAGS = -Wall -Werror -c -g -I.
LDFLAGS = -lm -L.

# Rules
%.o : %.c 
	@echo Compiling $^ 
	@$(CC) $(CFLAGS) $^

# Default target
default: grade

# Other targets
debug: CFLAGS += -DDEBUG
debug: clean gs

grade : main.o grade.o
	@echo Linking $@ 
	@$(CC) $^ $(LDFLAGS) -o $@

clean : 
	@rm -rf *.o
	@rm -rf grade
	@echo All Clean!
