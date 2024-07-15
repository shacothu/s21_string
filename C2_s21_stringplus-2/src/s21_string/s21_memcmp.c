#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int answer = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    const unsigned char *ptr1 = (const unsigned char *)str1;
    const unsigned char *ptr2 = (const unsigned char *)str2;
    
    for (s21_size_t i = 0; i < n; i++) {
      if (ptr1[i] > ptr2[i]) {
        answer = ptr1[i] - ptr2[i];
        break;
      }
      if (ptr1[i] < ptr2[i]) {
        answer = ptr1[i] - ptr2[i];
        break;
      }
    }
  }
  return answer;
}
