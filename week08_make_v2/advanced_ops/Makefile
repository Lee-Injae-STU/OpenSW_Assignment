.PHONY: advanced_ops clean
LIB=../lib/libmyadvanced.a
SRC_DIR = src
OBJ_DIR = obj
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o) )
CC=gcc
AR=ar
RM=rm
CFLAGS = -I../include

advanced_ops: $(LIB)

$(LIB): $(OBJS)
	$(AR) -rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) -f $(OBJ_DIR)/*.o $(LIB)