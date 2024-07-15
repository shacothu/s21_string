#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *pdest = (char *)dest;
  char *psrc = (char *)src;
  for (unsigned long long x = 0; x < n; x += 1) {
    pdest[x] = psrc[x];
  }
  return dest;
}