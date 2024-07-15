#include "../s21_string.h"

char* s21_strrchr(const char* str, int f) {
  const char* result = s21_NULL;

  if (!(str == s21_NULL)) {
    int found = 0;
    for (int i = 0; str[i] != '\0'; i++) {
      if ((int)str[i] == f) found++;
    }
    if (found > 0) {
      int comp = 0;
      for (int i = 0; str[i] != '\0'; i++) {
        if ((int)str[i] == f) {
          comp++;
          if (comp == found) result = (char*)&str[i];
        }
      }
    }
  }
  if (f == '\0') {
    while (*str != '\0') {
      str++;
    }
    return (char*)str;
  } else {
    return (char*)result;
  }
}