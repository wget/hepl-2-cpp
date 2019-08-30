.SILENT:
# If we define in the current directory a file named clean or mrproper, this
# will break this makefile as these target do not have any dependencies, the
# target will always be more recent and will never be evaluated. The PHONY
# directive avoids this issue.
.PHONY: clean mrproper debug prepare

# Custom makefile functions
# If used like "make print-MYVAR", allow to print a target/variable directly
# when calling the Makfile
# src.: https://stackoverflow.com/a/25817631
print-%: ; @echo $* = $($*)
# Recursive wildcard because the default wildcard is not recursive
rwildcard = $(wildcard $1$2) $(foreach d, $(wildcard $1*), $(call rwildcard,$d/,$2))

SRC_PATH = src
TEST_PATH = $(SRC_PATH)/tests
DIST_PATH = dist
OBJ_PATH = $(DIST_PATH)/obj
SRC := $(call rwildcard,$(SRC_PATH),*.cpp)
SRC_TEST = $(call rwildcard,$(TEST_PATH),*.cpp)
SRC := $(filter-out $(SRC_TEST), $(SRC))

CC = g++
# -MMD asks to create a list of rules corresponding to the local headers we
# need to specify without system headers.
# src.: https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
CFLAGS = -std=gnu++11 -W -Wall -I/usr/include -I. #-MMD
LDFLAGS = -lpthread -lSDL

# patsubst: $(patsubst pattern,replacement,text)
# 	  Finds whitespace-separated words in "text" that match "pattern" and
# 	  replaces them with "replacement"
# filter-out: $(filter-out pattern…,text)
#     Returns all whitespace-separated words in text that do not match any of
#     the pattern words, removing the words that do match one or more
EXECS = main
TESTS = test test1 test2 test3 test4 test5 test6 test7 testCalculator testWindow testWindowSDL testWindowCalculator main
EXECS_WITH_PATH = $(patsubst %,$(DIST_PATH)/%, $(EXECS))
TESTS_WITH_PATH = $(patsubst %,$(DIST_PATH)/%, $(TESTS))
OBJ = $(patsubst %, $(OBJ_PATH)/%.o, $(filter-out dist/obj/tests/%, $(filter-out $(EXECS), $(SRC:$(SRC_PATH)/%.cpp=%))))

# Force execution of the "prepare" rule defined below in order to make sure
# dist obj directories are created before looking into other dependencies
all: prepare $(TESTS_WITH_PATH)

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
	echo "[+] Building main"
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

# Note: It would be possible to simplify even further with such a rule:
#$(OBJ): $(SRC)
#    $(CC) $(CFLAGS) -c $< -o $@
# Where obj is an array whose items are iterated and the rules executed for
# each iteration. There isn't any correspondance between the current OBJ
# iterated and the SRC. The SRC will always contain the same array and we
# cannot change its content depending on the value of the current obj target.
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp 
	# Remove the heading OBJ_PATH from the current full filename
	echo "[+] Building $(subst $(OBJ_PATH)/,,$@)"
	$(CC) $(CFLAGS) -c -o $@ $<

dist/WindowSDL/%.o: $(SRC_PATH)/WindowSDL/%.cpp
	echo "[+] Building SDL $@"
	$(CC) $(CFLAGS) -c -o $@ $<

prepare:
	@mkdir -p dist/obj/WindowSDL

clean:
	$(RM) $(OBJ_PATH)/*.o $(OBJ_PATH)/*.gch $(TEST_PATH)/*.o

mrproper: clean
	$(RM) $(EXECS_WITH_PATH) $(TESTS_WITH_PATH)
