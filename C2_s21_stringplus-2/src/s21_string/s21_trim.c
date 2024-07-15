#include "../s21_string.h"

int is_trim_char(char ch, const char *trim_chars) {
  while (*trim_chars) {
    if (ch == *trim_chars) {
      return 1;
    }
    trim_chars++;
  }
  return 0;
}

char *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) {
    return s21_NULL;
  }

  const char *start = src;
  const char *end = src + s21_strlen(src) - 1;

  while (*start && is_trim_char(*start, trim_chars)) {
    start++;
  }

  while (end >= start && is_trim_char(*end, trim_chars)) {
    end--;
  }
  s21_size_t new_len = end - start + 1;

  char *trimmed_str = (char *)malloc(new_len + 1);
  if (trimmed_str == s21_NULL) {
    return s21_NULL;
  }
  char *ptr = trimmed_str;
  while (new_len--) {
    *ptr++ = *start++;
  }
  *ptr = '\0';

  return trimmed_str;
}
