#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index > src_len) {
    return s21_NULL;
  }

  char *new_str = (char *)malloc((src_len + str_len + 1) * sizeof(char));
  if (new_str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t len = src_len + str_len;
  s21_size_t last = start_index + str_len;
  s21_size_t j = 0;
  for (s21_size_t i = 0; i < len; i++) {  // идем по всей строке
    if (i < start_index) {
      new_str[i] = src[i];  // пока не дошли до индекса, выводим src
    } else if (i < last) {
      new_str[i] = str[j];  // когда дошли до индекса выводим новую строку
      j++;
    } else {
      new_str[i] =
          src[i -
              str_len];  // если i равен или больше индекса, выводим остальное
    }
  }
  new_str[len] = '\0';
  return new_str;
}
