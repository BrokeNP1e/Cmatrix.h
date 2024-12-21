CFLAGS = -Wall -Wextra -Werror
CC = -gcc -std=c11
SOURCE = s21_*.c
TARGET = s21_matrix
TEST_SOURCE = tests/*.c

ifeq ($(shell uname -s),Linux)
	LIBS=-lm -lrt -lpthread -lcheck -lsubunit
endif

ifeq ($(shell uname -s),Darwin)
	LIBS=-lcheck
endif

all: s21_matrix.a

s21_matrix.a:
	$(CC) $(CFLAGS) $(SOURCE) -c $(LIBS)
	ar rc $(TARGET).a *.o
	@rm *.o

clean:
	@rm -rf *.o *.a *.gcno *.gcda coverage.info test_runner coverage_report a.out

test: clean s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_SOURCE) s21_matrix.a -o test_runner $(LIBS)
	-./test_runner

clang_format:
	clang-format -style=google -i *.c *.h
	clang-format -style=google -i tests/*.c tests/*.h

style:
	clang-format -style=google -n *.c *.h
	clang-format -style=google -n tests/*.c tests/*.h

valgrind: s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_SOURCE) s21_matrix.a -o test_runner $(LIBS)
	./test_runner
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test_runner

gcov_report: clean
	$(CC) --coverage $(CFLAGS) $(SOURCE) -c
	ar rc $(TARGET).a *.o
	@rm *.o
	ranlib s21_matrix.a
	$(CC) --coverage $(CFLAGS) $(TEST_SOURCE) s21_matrix.a -o test_runner $(LIBS)
	./test_runner
	lcov --capture --directory . --output-file coverage.info
	#lcov --remove coverage.info '/usr/*' --output-file coverage.info
	lcov --remove coverage.info 'src/tests/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
	open ./coverage_report/index.html


win:
	$(CC) $(CFLAGS) $(SOURCE) main.c -o test_main $(LIBS)
	./test_main

.PHONY: all clean
