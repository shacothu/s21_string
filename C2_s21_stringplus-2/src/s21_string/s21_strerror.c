#include "s21_strerror.h"

#include "../s21_string.h"

char *s21_strerror(int error_num) {
  static char result[MAX_ERRLIST] = {'\0'};
  if (error_num <= MIN_ERRLIST || error_num >= MAX_ERRLIST) {
    s21_sprintf(result, "Unknown error: %d", error_num);
  } else {
    s21_strcpy(result, ((char *)error_list[error_num]));
  }

  return result;
}