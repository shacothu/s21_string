#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  while (*str1) {
    const char *r = str2;
    int found = 0;  // логическая перемен для контроля цикла
    while (*r) {
      if (*str1 == *r) {
        found = 1;
        // break;
      }
      r++;
    }
    if (!found) {
      count++;  // увел счетчик если символ найден
    } else {
      break;
    }
    str1++;
  }
  return count;
}