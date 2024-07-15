#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *current_token = s21_NULL;
  char *token;

  if (str) current_token = str;
  if (current_token == s21_NULL) return s21_NULL;

  while (*current_token && s21_strchr(delim, *current_token)) {
    current_token++;
  }
  if (*current_token == '\0') {
    current_token = s21_NULL;
    return s21_NULL;
  }

  token = current_token;

  while (*current_token && !s21_strchr(delim, *current_token)) {
    current_token++;
  }
  if (*current_token) {
    *current_token = '\0';
    current_token++;
  }

  return token;
}
