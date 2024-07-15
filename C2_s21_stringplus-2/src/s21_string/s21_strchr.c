#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  while (*str != '\0') {
    if (*str == c) {
      result = (char *)
          str;  // str имеет тип константы которую нельзя изменять. Возвращаемое
                // значение может изменяться если это необходимо, поэтому мы
                // приводим его к типу char указател
      break;
    }
    str++;
  }
  if (c == '\0') {  // проверка на 0 символ
    result = (char *)str;
  }
  return result;
}