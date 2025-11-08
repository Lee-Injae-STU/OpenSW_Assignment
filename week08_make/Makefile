#! /bin/bash

MY_APP = bin/myapp
LIB = lib/libmybasic.a
INC = include
OBJ_MAIN = obj/main/myapp.o
SRC_MAIN = src/main/myapp.c
OBJO_DIR = obj/ops
SRCO_DIR = src/ops
SRC_OPS = $(wildcard $(SRCO_DIR)/*.c)
OBJ_OPS = $(subst $(SRCO_DIR), $(OBJO_DIR), $(SRC_OPS:.c=.o))

CC = gcc
ar = AR
rm = RM

.PHONY: clean basic

basic: $(MY_APP)

$(MY_APP): $(LIB) $(OBJ_MAIN)
	$(CC) $(OBJ_MAIN) -Llib -lmybasic -o $@

$(LIB): $(OBJ_OPS)
	$(AR) -rv $@ $^ 

$(OBJ_MAIN): $(SRC_MAIN)
	$(CC) -c $^ -o $@ -I$(INC)

$(OBJO_DIR)/%.o: $(SRCO_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC)

clean:
	$(RM) -rf $(OBJ_MAIN) $(OBJ_OPS) $(LIB) $(MY_APP)