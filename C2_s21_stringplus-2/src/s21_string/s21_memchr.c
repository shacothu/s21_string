#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  if (str != s21_NULL) {
    const unsigned char *ptr = (const unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
      if (ptr[i] == (unsigned char)c) {
        return (void *)(ptr + i);
      }
    }
  }
  return s21_NULL;
}
