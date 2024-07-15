CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LIBS =
GCOVFLAGS = -fprofile-arcs

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    GCOVFLAGS += -ftest-coverage
    LIBS += -lcheck
else
    GCOVFLAGS += --coverage
    LIBS += -lcheck -lm -lsubunit
endif

SOURCES = \
	./s21_string/s21_strchr.c \
	./s21_string/s21_strcspn.c \
	./s21_string/s21_strlen.c \
	./s21_string/s21_strncat.c \
	./s21_string/s21_strncmp.c \
	./s21_string/s21_strncpy.c \
	./s21_string/s21_memcpy.c \
	./s21_string/s21_memchr.c \
	./s21_string/s21_memcmp.c \
	./s21_string/s21_strpbrk.c \
	./s21_string/s21_strrchr.c \
	./s21_string/s21_strstr.c \
	./s21_string/s21_strtok.c \
	./s21_string/s21_memset.c \
	./s21_string/s21_strerror.c \
	./s21_string/s21_strcpy.c \
	./s21_string/s21_insert.c \
	./s21_string/s21_to_upper.c \
	./s21_string/s21_to_lower.c \
	./s21_string/s21_trim.c \
	./s21_string/s21_sprintf.c

HEADERS = \
	./s21_string.h \
	./s21_string/s21_strerror.h

OBJECTS = $(SOURCES:.c=.o)
GCNO = $(SOURCES:.c=.gcno)
GCDA = $(SOURCES:.c=.gcda)

all: s21_string.a

test: $(OBJECTS) $(SOURCES)
	$(CC) $(CFLAGS) $(OBJECTS) s21_test/test_func.c -o test.out $(LIBS)
	./test.out

gcov_report: ${SOURCES} $(GCDA)
	$(CC) $(GCOVFLAGS) $(CFLAGS) $(OBJECTS) s21_test/test_func.c -o test.out $(LIBS)
	./test.out
	lcov -t "test.out" -o s21_test.info -c -d . --rc lcov_branch_coverage=0
	genhtml -o report s21_test.info --rc lcov_branch_coverage=0
	open ./report/index.html

s21_string.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib s21_string.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

%.gcda: %.c
	$(CC) $(GCOVFLAGS) $(CFLAGS) -c $< -o $(@:.gcda=.o) 

style: ${SOURCES}
	cp ../materials/linters/.clang-format .
	clang-format -n ${SOURCES} ${HEADERS}
	clang-format -n ./s21_test/test_func.c

clean:
	rm -rf $(OBJECTS)
	rm -rf $(GCNO)
	rm -rf $(GCDA)
	rm -rf *.gcda *.gcno 
	rm -rf report
	rm -rf s21_string.a
	rm -rf test.out s21_test.info
