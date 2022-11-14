CC = gcc 
CFLAGS = -g -MD  -Wall -Werror -Wextra -std=c11 -pedantic #-fsanitize=address
DIRS = core source  
LIB = s21_matrix.a
KERN = $(shell uname -s)

# -Icore/ 

OBJDIR = obj
SRC_FILES = $(foreach D, $(DIRS), $(wildcard $(D)/*.c))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
DEPS = $(patsubst %.o, %.d, $(OBJ_FILES))

TEST_FLAGS = $(shell pkg-config --libs --cflags check) 
TEST_DIRS = tests tests/suites
TEST_SRC_FILES = $(foreach D, $(TEST_DIRS), $(wildcard $(D)/*.c))
TEST_OBJ_FILES = $(patsubst %.c, %.o, $(TEST_SRC_FILES))

COVFLAGS = -fprofile-arcs -ftest-coverage

ifeq ($(KERN), Linux)
 CFLAGS += -lm
endif

all: test

test: $(LIB) 
	$(CC) $(CFLAGS) $(TEST_SRC_FILES) $(LIB) -o run_tests $(TEST_FLAGS) -I. -Itests
	./run_tests

gcov_report: 
	$(CC) $(CFLAGS) $(TEST_SRC_FILES) $(SRC_FILES) -o run_tests_for_coverage $(TEST_FLAGS) $(COVFLAGS)
	./run_tests_for_coverage
	@lcov -t "test_cov" -o report.info -c -d .
	@genhtml -o report report.info
	@rm *.gcno *.gcda *.d run_tests_for_coverage
	open report/index.html

# create dev.c for specific operation
dev: dev.c $(LIB)
	$(CC) dev.c $(LIB) $(CFLAGS) 
	./a.out

$(LIB): $(OBJ_FILES)
	ar -rc $(LIB) $(OBJ_FILES)

%.o:%.c
	$(CC) $(CFLAGS) -c $^  -o $@

codestyle: $(SRC_FILES) $(TEST_SRC_FILES)
	cp ../materials/linters/.clang-format .
	clang-format -n $^
	clang-format -n core/helpers.h s21_matrix.h tests/test_main.h 	
	rm .clang-format
	

leaks: test
	leaks -atExit -- ./run_tests

clean: 
	-rm -rf *.dSYM *.out $(OBJ_FILES) $(DEPS) *.d *.o *.a run_tests *.txt *.gcno *.gcda 
	-rm ./tests/suites/*.d
	-rm ./tests/suites/*.o # '-' to ignore mistake
	-rm ./tests/*.o # '-' to ignore mistake
	-rm ./tests/*.d # '-' to ignore mistake
	-rm -rf report* *.gcno *.gcda 

.SILENT: clean gcov_report test 

-include $(OBJ_FILES .o=.d)
