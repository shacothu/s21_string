#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

typedef struct {
  int plus, minus, precision, width, length;
} Format;

s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void parser_format(const char **fmt, Format *sing);
void handle_char(char **ptr, va_list args);
void handle_signed_int(char **ptr, int value, Format sing);
void handle_float(char **ptr, va_list args, Format sing);
void handle_string(char **ptr, va_list args);
void handle_unsigned_int(char **ptr, va_list args);
void handle_percent(char **ptr);
char *s21_strpbrk(const char *str, const char *ref);
char *s21_strrchr(const char *str, int f);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);
char *s21_strcpy(char *dest, const char *src);
char *s21_strerror(int error_num);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
char *s21_trim(const char *src, const char *trim_chars);
#endif  // S21_STRING_H