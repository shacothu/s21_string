#include "../s21_string.h"

char* s21_strpbrk(const char* str, const char* ref) {
  if (!(str == s21_NULL || ref == s21_NULL)) {
    for (int i = 0; str[i] != '\0'; i++) {
      for (int j = 0; ref[j] != '\0'; j++) {
        if (str[i] == ref[j]) {
          return (char*)&str[i];
        }
      }
    }
  }
  return s21_NULL;
}
