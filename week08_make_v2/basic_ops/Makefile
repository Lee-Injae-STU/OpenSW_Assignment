.PHONY: basic_ops clean
LIB = ../lib/libmybasic.a
SRC_DIR = src
OBJ_DIR = obj
CC = gcc
AR = ar
RM = rm
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
CFLAGS = -I../include

basic_ops: $(LIB)

$(LIB): $(OBJS)
	$(AR) -rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) -f $(OBJ_DIR)/*.o $(LIB)