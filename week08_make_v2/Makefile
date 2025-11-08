.PHONY: all basic_ops advanced_ops clean
PROJ=$(PWD)
SRC_DIR=$(PROJ)/src
OBJ_DIR=$(PROJ)/obj
BIN_DIR=$(PROJ)/bin
INC_DIR=$(PROJ)/include
LIB_DIR=$(PROJ)/lib
STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
CC=gcc
CFLAGS=-I$(INC_DIR) -lm
LDFLAGS=-L$(LIB_DIR) -lmybasic -lmyadvanced

all: basic_ops advanced_ops $(BIN_DIR)/myapp 

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(STATIC_LIBS)
	$(CC) $(OBJ_DIR)/myapp.o -o $@ $(LDFLAGS) 

$(OBJ_DIR)/myapp.o: $(SRC_DIR)/myapp.c
	$(CC) -c $^ -o $@ $(CFLAGS)

basic_ops:
	$(MAKE) -C basic_ops
advanced_ops:
	$(MAKE) -C advanced_ops

clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean