#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *psrc = (char *)str;
  for (unsigned long long x = 0; x < n; x += 1) {
    psrc[x] = c;
  }
  return str;
}
