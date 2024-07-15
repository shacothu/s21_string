#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest_con = dest;
  while (*dest_con != '\0') {  // перемешаемся к концу строки проходимся по
                               // hello дальше конкатенация
    dest_con++;
  }
  while (n-- > 0 && *src != '\0') {  // мы начинаем условно с 5 и идем к 0
    *dest_con = *src;  // эта строка выполняет копирование значенияб на которое
                       // указывает *src, в место на которое указывает *dest_con
    dest_con++;
    src++;
  }
  *dest_con = '\0';
  return dest;
}
