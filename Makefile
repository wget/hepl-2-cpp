.SILENT:
# If we define in the current directory a file named clean or mrproper, this
# will break this makefile as these target do not have any dependencies, the
# target will always be more recent and will never be evaluated. The PHONY
# directive avoids this issue.
.PHONY: clean mrproper debug test2

print-%: ; @echo $* = $($*)
SRC_PATH=src
TEST_PATH=$(SRC_PATH)/tests
DIST_PATH=dist
OBJ_PATH=$(DIST_PATH)/obj
# From all the cpp files we have, replace the cpp extension by hpp and remove
# the file main.hpp since it does not exist and make might complain there is no
# rule for this file.
# HEADERS=$(filter-out $(SRC_PATH)/main.hpp, $(SRC:.cpp=.hpp))
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
SRC := $(call rwildcard,$(SRC_PATH),*.cpp)
SRC_TEST=$(call rwildcard,$(TEST_PATH),*.cpp)
SRC := $(filter-out $(SRC_TEST), $(SRC))
HEADERS=$(call rwildcard,$(SRC_PATH),*.hpp)

CC=g++
CFLAGS=-W -Wall -I/usr/include -I.
LDFLAGS=-lpthread -lSDL

EXECS=main#  main
EXECS_WITH_PATH=$(patsubst %,$(DIST_PATH)/%, $(EXECS))
TESTS=test test1 test2 test3 test4 test5 test6 test7 testCalculator testWindow testWindowSDL testWindowCalculator
TESTS_WITH_PATH=$(patsubst %,$(DIST_PATH)/%, $(TESTS))

# TEST_DEBUG=$(SRC:$(SRC_PATH)/%.cpp=%)
HELLO_TEST=$(SRC)
OBJ=$(patsubst %, $(OBJ_PATH)/%.o, $(filter-out dist/obj/tests/%,$(filter-out $(EXECS),$(SRC:$(SRC_PATH)/%.cpp=%))))
#all: $(EXECS_WITH_PATH)
all: $(TESTS_WITH_PATH)

debug: CFLAGS+=-DWITH_DEBUG
debug: mrproper
debug: CC+=-ggdb
debug: all

# Instead of repeating dependencies over and over again, make does support the
# following shortcuts. These also allow to avoid burden when we want to change
# the destination name of executables/targets for example.
#$@ : Target name;
#$< : First dependency;
#$? : More recent dependencies than the target;
#$^ : All the dependencies;
#$* : All wildcard character, same as * but syntax interpreted by make
$(DIST_PATH)/main: $(OBJ_PATH)/main.o $(OBJ)
	echo "[+] Building $@"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test: $(TEST_PATH)/test.o $(OBJ)
	echo "[+] Building debug test file"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test1: $(TEST_PATH)/test1.o $(OBJ)
	echo "[+] Building test 1"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test2: $(TEST_PATH)/test2.o $(OBJ)
	echo "[+] Building test 2"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test3: $(TEST_PATH)/test3.o $(OBJ)
	echo "[+] Building test 3"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test4: $(TEST_PATH)/test4.o $(OBJ)
	echo "[+] Building test 4"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test5: $(TEST_PATH)/test5.o $(OBJ)
	echo "[+] Building test 5"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test6: $(TEST_PATH)/test6.o $(OBJ)
	echo "[+] Building test 6"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/test7: $(TEST_PATH)/test7.o $(OBJ)
	echo "[+] Building test 7"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/testCalculator: $(TEST_PATH)/testCalculator.o $(OBJ)
	echo "[+] Building test calculator"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/testWindow: $(TEST_PATH)/testWindow.o $(OBJ)
	echo "[+] Building test Window"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/testWindowSDL: $(TEST_PATH)/testWindowSDL.o $(OBJ)
	echo "[+] Building test Window SDL"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(DIST_PATH)/testWindowCalculator: $(TEST_PATH)/testWindowCalculator.o $(OBJ)
	echo "[+] Building test Window Calculator"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADERS)
	echo "[+] Building $@"
	$(CC) $(CFLAGS) -c -o $@ $<

dist/WindowSDL/%.o: $(SRC_PATH)/WindowSDL/%.cpp $(HEADERS)
	echo "[+] Building SDL $@"
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_PATH)/*.o $(OBJ_PATH)/*.gch $(TEST_PATH)/*.o

mrproper: clean
	$(RM) $(EXECS_WITH_PATH) $(TESTS_WITH_PATH)
