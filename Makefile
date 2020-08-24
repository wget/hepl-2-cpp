.SILENT:
# If we define in the current directory a file named clean or mrproper, this
# will break this makefile as these target do not have any dependencies, the
# target will always be more recent and will never be evaluated. The PHONY
# directive avoids this issue.
.PHONY: clean mrproper debug prepare

################################################################################
# Custom makefile functions (GNU Make)
################################################################################
# If used like "make print-MYVAR", allow to print a target/variable directly
# when calling the Makfile
# src.: https://stackoverflow.com/a/25817631
print-%: ; @echo $* = $($*)
# Recursive wildcard because the default wildcard is not recursive
rwildcard = $(wildcard $1$2) $(foreach d, $(wildcard $1*), $(call rwildcard,$d/,$2))

################################################################################
# Compiler settings
################################################################################
CC = g++
# -MMD asks to create a list of rules corresponding to the local headers we
# need to specify without system headers.
# src.: https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
CFLAGS = -std=gnu++11 -W -Wall -I/usr/include -Isrc/lib/whereami/src/ -I. #-MMD
LDFLAGS = -lpthread -lSDL

################################################################################
# Gathering files
################################################################################
SRC_PATH = src
TEST_PATH = $(SRC_PATH)/tests
DIST_PATH = dist
OBJ_PATH = $(DIST_PATH)/obj

# Get all .cpp files recursively from the SRC_PATH
SRC := $(call rwildcard,$(SRC_PATH),*.cpp)
# Add to the sources all .c files recursively from the SRC_PATH
SRC := $(SRC) $(call rwildcard,$(SRC_PATH),*.c)
# Remove locations that shouldn't be in the sources (here, the source examples
# of the whereami lib)
SRC_EXCLUSIONS := $(call rwildcard,src/lib/whereami/example,*)
SRC := $(filter-out $(SRC_EXCLUSIONS), $(SRC))

# patsubst: $(patsubst pattern,replacement,text)
# 	  Finds whitespace-separated words in "text" that match "pattern" and
# 	  replaces them with "replacement"
# filter-out: $(filter-out pattern…,text)
#     Returns all whitespace-separated words in text that do not match any of
#     the pattern words, removing the words that do match one or more
EXECS = main
TESTS = test test1 test2 test3 test4 test5 test6 test7 testCalculator testWindow testWindowSDL testWindowCalculator main
# Prefix the paths with DIST_PATH
EXECS_WITH_PATH = $(patsubst %,$(DIST_PATH)/%, $(EXECS))
TESTS_WITH_PATH = $(patsubst %,$(DIST_PATH)/%, $(TESTS))

# Objects management
# Remove "src" path from sources
OBJ := $(SRC:$(SRC_PATH)/%=%)
# Remove .cpp suffix from sources
OBJ := $(patsubst %.cpp, %, $(OBJ))
# Remove .c suffix from sources
OBJ := $(patsubst %.c, %, $(OBJ))
# Remove execs from object files
OBJ := $(filter-out $(EXECS), $(OBJ))
# Remove tests to avoid multiple inclusions execs from object files
OBJ := $(filter-out tests/%, $(OBJ))
# Add .o extension to the naked filenames
OBJ := $(patsubst %, $(OBJ_PATH)/%.o, $(OBJ))

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
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	# Remove the heading OBJ_PATH from the current full filename
	echo "[+] Building $(subst $(OBJ_PATH)/,,$@)"
	# Create parent directory on the fly to store objects.
	# We are making use of make's internal variable $(@D), that means "the
	# directory the current target resides in". Needed to have our directory
	# hierarchy created.
	# src.: https://stackoverflow.com/a/1951111/3514658
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

dist/WindowSDL/%.o: $(SRC_PATH)/WindowSDL/%.cpp
	echo "[+] Building SDL $@"
	$(CC) $(CFLAGS) -c -o $@ $<

#dist/obj/lib/whereami/%.o: src/lib/whereami/src/whereami.c
#	@mkdir -p $(@D)
#	echo "[+] Building WhereAmI $@"
#	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -r $(OBJ_PATH)

mrproper: clean
	$(RM) $(EXECS_WITH_PATH) $(TESTS_WITH_PATH)
