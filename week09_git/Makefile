SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
BIN_DIR=bin
OPS=$(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
LIB_FILE=libmyops.so
SHARED=$(LIB_DIR)/$(LIB_FILE).1.0
SL_1=$(LIB_DIR)/$(LIB_FILE).1
SL=$(LIB_DIR)/$(LIB_FILE)
CFLAGS=-Iinclude
LDFLAGS=-L$(LIB_DIR) -lmyops
SFLAGS=-shared -soname=libmyops.so.1

.PHONY: clean all

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(SHARED)
	gcc $< $(LDFLAGS) -o $@

$(SHARED): $(OPS)
	ld $(SFLAGS) $^ -o $@ -lc
	ln -s libmyops.so.1.0 $(SL_1)
	ln -s libmyops.so.1 $(SL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/*.so* $(BIN_DIR)/*