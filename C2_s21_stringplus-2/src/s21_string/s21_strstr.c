#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t needle_len = s21_strlen(needle);
  if (needle_len == 0) {
    return (char *)haystack;
  }
  while (*haystack) {
    if (s21_strncmp(haystack, needle, needle_len) == 0) {
      return (char *)haystack;
    }
    haystack++;
  }
  return s21_NULL;
}
