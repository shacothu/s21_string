#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t lenght = 0;
  while (str[lenght] != '\0') {
    lenght++;
  }
  char *upper_str = (char *)malloc((lenght + 1) * sizeof(char));
  if (upper_str == s21_NULL) {
    return s21_NULL;
  }
  for (s21_size_t i = 0; i < lenght; i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      upper_str[i] = str[i] - 32;
    } else {
      upper_str[i] = str[i];
    }
  }
  upper_str[lenght] = '\0';
  return upper_str;
}
