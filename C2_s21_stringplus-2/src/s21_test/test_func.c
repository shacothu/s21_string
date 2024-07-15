#include <check.h>
#include <string.h>

#include "../s21_string.h"
#include "../s21_string/s21_strerror.h"

// Тесты для s21_strlen
START_TEST(test_s21_strlen_empty) {
  ck_assert_uint_eq(s21_strlen(""), strlen(""));
}
END_TEST

START_TEST(test_s21_strlen_normal) {
  ck_assert_uint_eq(s21_strlen("hello"), strlen("hello"));
}
END_TEST

START_TEST(test_s21_strlen_spaces) {
  ck_assert_uint_eq(s21_strlen(" "), strlen(" "));
  ck_assert_uint_eq(s21_strlen("  "), strlen("  "));
  ck_assert_uint_eq(s21_strlen("hello world"), strlen("hello world"));
}
END_TEST

START_TEST(test_s21_strlen_control_chars) {
  ck_assert_uint_eq(s21_strlen("\n"), strlen("\n"));
  ck_assert_uint_eq(s21_strlen("\t"), strlen("\t"));
  ck_assert_uint_eq(s21_strlen("\n\t"), strlen("\n\t"));
  ck_assert_uint_eq(s21_strlen("hello\nworld"), strlen("hello\nworld"));
}
END_TEST

START_TEST(test_s21_strlen_unicode) {
  ck_assert_uint_eq(s21_strlen("привет"), strlen("привет"));
}
END_TEST

// Тесты для s21_strchr
START_TEST(test_s21_strchr_present) {
  ck_assert_ptr_eq(s21_strchr("hello", 'e'), strchr("hello", 'e'));
}
END_TEST

START_TEST(test_s21_strchr_not_present) {
  ck_assert_ptr_eq(s21_strchr("hello", 'z'), strchr("hello", 'z'));
}
END_TEST

START_TEST(test_s21_strchr_first_char) {
  ck_assert_ptr_eq(s21_strchr("hello", 'h'), strchr("hello", 'h'));
}
END_TEST

START_TEST(test_s21_strchr_last_char) {
  ck_assert_ptr_eq(s21_strchr("hello", 'o'), strchr("hello", 'o'));
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  ck_assert_ptr_eq(s21_strchr("", 'h'), strchr("", 'h'));
}
END_TEST

START_TEST(test_s21_strchr_null_char) {
  ck_assert_ptr_eq(s21_strchr("hello", '\0'), strchr("hello", '\0'));
}
END_TEST

// Тесты для s21_strcspn
START_TEST(test_s21_strcspn_present) {
  ck_assert_uint_eq(s21_strcspn("hello", "e"), strcspn("hello", "e"));
}
END_TEST

START_TEST(test_s21_strcspn_not_present) {
  ck_assert_uint_eq(s21_strcspn("hello", "xyz"), strcspn("hello", "xyz"));
}
END_TEST

START_TEST(test_s21_strcspn_first_char) {
  ck_assert_uint_eq(s21_strcspn("hello", "h"), strcspn("hello", "h"));
}
END_TEST

START_TEST(test_s21_strcspn_last_char) {
  ck_assert_uint_eq(s21_strcspn("hello", "o"), strcspn("hello", "o"));
}
END_TEST

START_TEST(test_s21_strcspn_empty_str1) {
  ck_assert_uint_eq(s21_strcspn("", "h"), strcspn("", "h"));
}
END_TEST

START_TEST(test_s21_strcspn_empty_str2) {
  ck_assert_uint_eq(s21_strcspn("hello", ""), strcspn("hello", ""));
}
END_TEST

START_TEST(test_s21_strcspn_both_empty) {
  ck_assert_uint_eq(s21_strcspn("", ""), strcspn("", ""));
}
END_TEST

// Тесты для s21_strncat
START_TEST(test_s21_strncat_basic) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  ck_assert_str_eq(s21_strncat(dest1, "World!", 3),
                   strncat(dest2, "World!", 3));
}
END_TEST

START_TEST(test_s21_strncat_full) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  ck_assert_str_eq(s21_strncat(dest1, "World!", 7),
                   strncat(dest2, "World!", 7));
}
END_TEST

START_TEST(test_s21_strncat_zero) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  ck_assert_str_eq(s21_strncat(dest1, "World!", 0),
                   strncat(dest2, "World!", 0));
}
END_TEST

START_TEST(test_s21_strncat_empty_src) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  ck_assert_str_eq(s21_strncat(dest1, "", 3), strncat(dest2, "", 3));
}
END_TEST

START_TEST(test_s21_strncat_empty_dest) {
  char dest1[20] = "";
  char dest2[20] = "";
  ck_assert_str_eq(s21_strncat(dest1, "World!", 3),
                   strncat(dest2, "World!", 3));
}
END_TEST

START_TEST(test_s21_strncat_dest_capacity) {
  char dest1[10] = "Hello";
  char dest2[10] = "Hello";
  ck_assert_str_eq(s21_strncat(dest1, "World", 2), strncat(dest2, "World", 2));
}
END_TEST

// Тесты для s21_strncmp
START_TEST(test_s21_strncmp_equal) {
  ck_assert_int_eq(s21_strncmp("apple", "apple", 5),
                   strncmp("apple", "apple", 5));
  ck_assert_int_eq(s21_strncmp("banana", "banana", 6),
                   strncmp("banana", "banana", 6));
}
END_TEST

START_TEST(test_s21_strncmp_less) {
  ck_assert_int_eq(s21_strncmp("apple", "applesauce", 5),
                   strncmp("apple", "applesauce", 5));
  ck_assert_int_eq(s21_strncmp("apple", "applesauce", 6),
                   strncmp("apple", "applesauce", 6));
  ck_assert_int_eq(s21_strncmp("abc", "abcd", 4), strncmp("abc", "abcd", 4));
}
END_TEST

START_TEST(test_s21_strncmp_greater) {
  ck_assert_int_eq(s21_strncmp("applesauce", "apple", 5),
                   strncmp("applesauce", "apple", 5));
  ck_assert_int_eq(s21_strncmp("applesauce", "apple", 6),
                   strncmp("applesauce", "apple", 6));
  ck_assert_int_eq(s21_strncmp("abcd", "abc", 4), strncmp("abcd", "abc", 4));
}
END_TEST

START_TEST(test_s21_strncmp_partial) {
  ck_assert_int_eq(s21_strncmp("banana", "ban", 3),
                   strncmp("banana", "ban", 3));
  ck_assert_int_eq(s21_strncmp("banana", "ban", 2),
                   strncmp("banana", "ban", 2));
}
END_TEST

START_TEST(test_s21_strncmp_zero) {
  ck_assert_int_eq(s21_strncmp("apple", "applesauce", 0),
                   strncmp("apple", "applesauce", 0));
  ck_assert_int_eq(s21_strncmp("banana", "ban", 0),
                   strncmp("banana", "ban", 0));
}
END_TEST

START_TEST(test_s21_strncmp_empty) {
  ck_assert_int_eq(s21_strncmp("", "", 1), strncmp("", "", 1));
  ck_assert_int_eq(s21_strncmp("apple", "", 1), strncmp("apple", "", 1));
  ck_assert_int_eq(s21_strncmp("", "apple", 1), strncmp("", "apple", 1));
}
END_TEST

// Тесты для сравнения s21_strncpy и strncpy
START_TEST(test_s21_strncpy_comparison) {
  const char *src = "Hello, world!";
  char dest_s21[20], dest_std[20];

  s21_strncpy(dest_s21, src, 5);
  dest_s21[5] = '\0';

  strncpy(dest_std, src, 5);
  dest_std[5] = '\0';

  ck_assert_str_eq(dest_s21, dest_std);

  s21_strncpy(dest_s21, src, 3);
  dest_s21[3] = '\0';

  strncpy(dest_std, src, 3);
  dest_std[3] = '\0';

  ck_assert_str_eq(dest_s21, dest_std);

  s21_strncpy(dest_s21, src, 20);
  strncpy(dest_std, src, 20);

  ck_assert_str_eq(dest_s21, dest_std);
}
END_TEST
// hbhhk

// Тесты для s21_memcpy
START_TEST(test_s21_memcpy_normal) {
  char source1[] = "Hello World";
  char source2[] = "Hello World";
  char destination_my[6] = "";
  s21_memcpy(destination_my, source1, 5);
  char destination_true[6] = "";
  memcpy(destination_true, source2, 5);
  ck_assert_str_eq(destination_my, destination_true);
}
END_TEST

START_TEST(test_s21_memcpy_negative) {
  char source1[] = "Hello World";
  char source2[] = "Hell Worl";
  char destination_my[6] = "";
  s21_memcpy(destination_my, source1, 5);
  char destination_true[6] = "";
  memcpy(destination_true, source2, 5);
  ck_assert_str_ne(destination_my, destination_true);
}
END_TEST

START_TEST(test_s21_memcpy_empty) {
  char source1[200] = "";
  char source2[200] = "";
  char destination_my[200] = "";
  s21_memcpy(destination_my, source1, 199);
  char destination_true[200] = "";
  memcpy(destination_true, source2, 199);
  ck_assert_str_eq(destination_my, destination_true);
}
END_TEST

// Тесты для s21_memset

START_TEST(test_s21_memset_massive) {
  char str1[] = "School is cool";
  char str2[] = "School-21";
  char str3[] = "amogus";
  char str4[] = "This is a string!";
  char str5[] = "Shrek";
  char res1[] = "School is cool";
  char res2[] = "School-21";
  char res3[] = "amogus";
  char res4[] = "This is a string!";
  char res5[] = "Shrek";

  s21_memset(str1, '_', 5);
  s21_memset(str2, '_', 4);
  s21_memset(str3, 'M', 2);
  s21_memset(str4, '-', 1);
  s21_memset(str5, 'S', 1);

  memset(res1, '_', 5);
  memset(res2, '_', 4);
  memset(res3, 'M', 2);
  memset(res4, '-', 1);
  memset(res5, 'S', 1);

  ck_assert_msg(memcmp(str1, res1, sizeof(str1)) == 0,
                "1st memset test failed");
  ck_assert_msg(memcmp(str2, res2, sizeof(str2)) == 0,
                "2nd memset test failed");
  ck_assert_msg(memcmp(str3, res3, sizeof(str3)) == 0,
                "3rd memset test failed");
  ck_assert_msg(memcmp(str4, res4, sizeof(str4)) == 0,
                "4rth memset test failed");
  ck_assert_msg(memcmp(str5, res5, sizeof(str5)) == 0,
                "5rth memset test failed");
}
END_TEST

START_TEST(test_s21_memset_normal) {
  int c = 'a';
  char destination_my[6] = "";
  s21_memset(destination_my, c, 5);
  char destination_true[6] = "";
  memset(destination_true, c, 5);
  ck_assert_str_eq(destination_my, destination_true);
}
END_TEST

START_TEST(test_s21_memset_negative) {
  int c1 = 'a';
  int c2 = 'b';
  char destination_my[6] = "";
  s21_memset(destination_my, c1, 5);
  char destination_true[6] = "";
  memset(destination_true, c2, 5);
  ck_assert_str_ne(destination_my, destination_true);
}
END_TEST

// memchr
//  Тест: символ найден в начале строки
START_TEST(test_s21_memchr_found_at_start) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_memchr(s, 'h', 5), memchr(s, 'h', 5));
}
END_TEST

// Тест: символ найден в середине строки
START_TEST(test_s21_memchr_found_at_middle) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_memchr(s, 'l', 5), memchr(s, 'l', 5));
}
END_TEST

// Тест: символ найден в конце строки
START_TEST(test_s21_memchr_found_at_end) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_memchr(s, 'o', 5), memchr(s, 'o', 5));
}
END_TEST

// Тест: символ не найден
START_TEST(test_s21_memchr_not_found) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_memchr(s, 'x', 5), memchr(s, 'x', 5));
}
END_TEST

// Тест: поиск символа в нулевом байте
START_TEST(test_s21_memchr_zero_byte) {
  char s[] = "hello\0world";
  ck_assert_ptr_eq(s21_memchr(s, 'w', 11), memchr(s, 'w', 11));
}
END_TEST

// Тест: пустая строка
START_TEST(test_s21_memchr_empty_string) {
  char s[] = "";
  ck_assert_ptr_eq(s21_memchr(s, 'a', 0), memchr(s, 'a', 0));
}
END_TEST

// memcmp
//  Тест: строки равны
START_TEST(test_s21_memcmp_equal) {
  char s1[] = "hello";
  char s2[] = "hello";
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

// Тест: первая строка меньше
START_TEST(test_s21_memcmp_first_less) {
  char s1[] = "hello";
  char s2[] = "world";
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

// Тест: первая строка больше
START_TEST(test_s21_memcmp_first_greater) {
  char s1[] = "world";
  char s2[] = "hello";
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

// Тест: строки равны, но сравнивается меньше байтов
START_TEST(test_s21_memcmp_partial_equal) {
  char s1[] = "hello";
  char s2[] = "hello";
  ck_assert_int_eq(s21_memcmp(s1, s2, 3), memcmp(s1, s2, 3));
}
END_TEST

// Тест: строки разные, но сравнивается меньше байтов
START_TEST(test_s21_memcmp_partial_different) {
  char s1[] = "hello";
  char s2[] = "hezlo";
  ck_assert_int_eq(s21_memcmp(s1, s2, 3), memcmp(s1, s2, 3));
}
END_TEST

// Тест: пустые строки
START_TEST(test_s21_memcmp_empty) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(s21_memcmp(s1, s2, 0), memcmp(s1, s2, 0));
}
END_TEST

// return 0;
START_TEST(test_s21_memcmp_null_pointer) {
  // Тестовый случай, когда str1 равенs21_NULL
  ck_assert_int_eq(s21_memcmp(NULL, "test", 4), 0);

  // Тестовый случай, когда str2 равенs21_NULL
  ck_assert_int_eq(s21_memcmp("test", s21_NULL, 4), 0);

  // Тестовый случай, когда оба указателя равныs21_NULL
  ck_assert_int_eq(s21_memcmp(NULL, s21_NULL, 4), 0);
}
END_TEST

// strpbk
//  Тест: символ найден в начале строки
START_TEST(test_s21_strpbrk_found_at_start) {
  char s[] = "hello";
  char accept[] = "h";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// Тест: символ найден в середине строки
START_TEST(test_s21_strpbrk_found_at_middle) {
  char s[] = "hello";
  char accept[] = "l";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// Тест: символ найден в конце строки
START_TEST(test_s21_strpbrk_found_at_end) {
  char s[] = "hello";
  char accept[] = "o";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// Тест: символ не найден
START_TEST(test_s21_strpbrk_not_found) {
  char s[] = "hello";
  char accept[] = "x";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// Тест: несколько символов в accept, один найден
START_TEST(test_s21_strpbrk_multiple_accept_one_found) {
  char s[] = "hello";
  char accept[] = "xyzl";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// Тест: несколько символов в accept, ни один не найден
START_TEST(test_s21_strpbrk_multiple_accept_none_found) {
  char s[] = "hello";
  char accept[] = "xyz";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// Тест: пустая строка
START_TEST(test_s21_strpbrk_empty_string) {
  char s[] = "";
  char accept[] = "a";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// Тест: пустая строка accept
START_TEST(test_s21_strpbrk_empty_accept) {
  char s[] = "hello";
  char accept[] = "";
  ck_assert_ptr_eq(s21_strpbrk(s, accept), strpbrk(s, accept));
}
END_TEST

// strrchr
//  Тест: символ найден в начале строки
START_TEST(test_s21_strrchr_found_at_start) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_strrchr(s, 'h'), strrchr(s, 'h'));
}
END_TEST

// Тест: символ найден в середине строки
START_TEST(test_s21_strrchr_found_at_middle) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_strrchr(s, 'l'), strrchr(s, 'l'));
}
END_TEST

// Тест: символ найден в конце строки
START_TEST(test_s21_strrchr_found_at_end) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_strrchr(s, 'o'), strrchr(s, 'o'));
}
END_TEST

// Тест: символ не найден
START_TEST(test_s21_strrchr_not_found) {
  char s[] = "hello";
  ck_assert_ptr_eq(s21_strrchr(s, 'x'), strrchr(s, 'x'));
}
END_TEST

// Тест: символ найден несколько раз
START_TEST(test_s21_strrchr_multiple_occurrences) {
  char s[] = "hello hello";
  ck_assert_ptr_eq(s21_strrchr(s, 'l'), strrchr(s, 'l'));
}
END_TEST

// Тест: символ найден в нулевом байте
START_TEST(test_s21_strrchr_zero_byte) {
  char s[] = "hello\0world";
  ck_assert_ptr_eq(s21_strrchr(s, '\0'), strrchr(s, '\0'));
}
END_TEST

// Тест: пустая строка
START_TEST(test_s21_strrchr_empty_string) {
  char s[] = "";
  ck_assert_ptr_eq(s21_strrchr(s, 'a'), strrchr(s, 'a'));
}
END_TEST

// strsrt
//  Тест: подстрока найдена в начале
START_TEST(test_s21_strstr_found_at_start) {
  char haystack[] = "hello world";
  char needle[] = "hello";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест: подстрока найдена в середине
START_TEST(test_s21_strstr_found_at_middle) {
  char haystack[] = "hello world";
  char needle[] = "world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест: подстрока найдена в конце
START_TEST(test_s21_strstr_found_at_end) {
  char haystack[] = "hello world";
  char needle[] = "world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест: подстрока не найдена
START_TEST(test_s21_strstr_not_found) {
  char haystack[] = "hello world";
  char needle[] = "goodbye";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест: пустая подстрока
START_TEST(test_s21_strstr_empty_needle) {
  char haystack[] = "hello world";
  char needle[] = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест: пустая строка и пустая подстрока
START_TEST(test_s21_strstr_empty_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест: подстрока больше строки
START_TEST(test_s21_strstr_needle_longer_than_haystack) {
  char haystack[] = "hello";
  char needle[] = "hello world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// strtok
//  Тест: разделение строки по одному разделителю
START_TEST(test_s21_strtok_single_delim) {
  char str1[] = "hello world";
  char str2[] = "hello world";
  char delim[] = " ";
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  while (token1 != s21_NULL && token2 != s21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(NULL, delim);
    token2 = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

// Тест: разделение строки по нескольким разделителям
START_TEST(test_s21_strtok_multiple_delims) {
  char str1[] = "hello, world! this is; a test";
  char str2[] = "hello, world! this is; a test";
  char delim[] = " ,;!";
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  while (token1 != s21_NULL && token2 != s21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(NULL, delim);
    token2 = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

// Тест: строка начинается с разделителей
START_TEST(test_s21_strtok_leading_delims) {
  char str1[] = "   hello world";
  char str2[] = "   hello world";
  char delim[] = " ";
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  while (token1 != s21_NULL && token2 != s21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(NULL, delim);
    token2 = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

// Тест: строка с пустыми токенами между разделителями
START_TEST(test_s21_strtok_empty_tokens) {
  char str1[] = "hello,,world";
  char str2[] = "hello,,world";
  char delim[] = ",";
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  while (token1 != s21_NULL && token2 != s21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(NULL, delim);
    token2 = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

// Тест: строка полностью состоит из разделителей
START_TEST(test_s21_strtok_all_delims) {
  char str1[] = ";;;;";
  char str2[] = ";;;;";
  char delim[] = ";";
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

// Тест: пустая строка
START_TEST(test_s21_strtok_empty_string) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = ",";
  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

//Добавление тестов sprintf
// Функция для сравнения двух строк и их длин
void compare_strings(char *str1, char *str2, int len1, int len2) {
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(str1, str2);
}

// Тест для спецификатора 'c'
START_TEST(test_char) {
  char buffer1[100];
  char buffer2[100];
  char ch = 'A';
  int len1 = s21_sprintf(buffer1, "Char: %c", ch);
  int len2 = sprintf(buffer2, "Char: %c", ch);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификаторов 'd' и 'i'
START_TEST(test_signed_int) {
  char buffer1[100];
  char buffer2[100];
  int num = -123;
  int len1 = s21_sprintf(buffer1, "Signed Int: %d", num);
  int len2 = sprintf(buffer2, "Signed Int: %d", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификаторов 'd' и 'i'
START_TEST(test_signed_int_1) {
  char buffer1[100];
  char buffer2[100];
  int num = 123;
  int len1 = s21_sprintf(buffer1, "Signed Int: %+d", num);
  int len2 = sprintf(buffer2, "Signed Int: %+d", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

START_TEST(test_signed_int_2) {
  char buffer1[100];
  char buffer2[100];
  int num = 123;
  int len1 = s21_sprintf(buffer1, "Signed Int: %-d", num);
  int len2 = sprintf(buffer2, "Signed Int: %-d", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

START_TEST(test_signed_int_3) {
  char buffer1[100];
  char buffer2[100];
  int num = 12;
  int len1 = s21_sprintf(buffer1, "Signed Int: %3d", num);
  int len2 = sprintf(buffer2, "Signed Int: %3d", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

START_TEST(test_signed_int_4) {
  char buffer1[100];
  char buffer2[100];
  int num = -12;
  int len1 = s21_sprintf(buffer1, "Signed Int: %4d", num);
  int len2 = sprintf(buffer2, "Signed Int: %4d", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

START_TEST(test_signed_int_5) {
  char buffer1[100];
  char buffer2[100];
  int num = -12;
  int len1 = s21_sprintf(buffer1, "Signed Int: %-4d", num);
  int len2 = sprintf(buffer2, "Signed Int: %-4d", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора 'f'
START_TEST(test_float) {
  char buffer1[100];
  char buffer2[100];
  double num = 456.789;
  int len1 = s21_sprintf(buffer1, "Float: %.6f", num);
  int len2 = sprintf(buffer2, "Float: %.6f", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора 's'
START_TEST(test_string) {
  char buffer1[100];
  char buffer2[100];
  char *str = "Hello";
  int len1 = s21_sprintf(buffer1, "String: %s", str);
  int len2 = sprintf(buffer2, "String: %s", str);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора 'u'
START_TEST(test_unsigned_int) {
  char buffer1[100];
  char buffer2[100];
  unsigned int num = 123456;
  int len1 = s21_sprintf(buffer1, "Unsigned Int: %u", num);
  int len2 = sprintf(buffer2, "Unsigned Int: %u", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора '%'
START_TEST(test_percent) {
  char buffer1[100];
  char buffer2[100];
  int len1 = s21_sprintf(buffer1, "Percent: %%");
  int len2 = sprintf(buffer2, "Percent: %%");
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора 'h'
START_TEST(test_short_int) {
  char buffer1[100];
  char buffer2[100];
  short int num = -12345;
  int len1 = s21_sprintf(buffer1, "Short Int: %hd", num);
  int len2 = sprintf(buffer2, "Short Int: %hd", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора 'l'
START_TEST(test_long_int) {
  char buffer1[100];
  char buffer2[100];
  long int num = 1234567890;
  int len1 = s21_sprintf(buffer1, "Long Int: %ld", num);
  int len2 = sprintf(buffer2, "Long Int: %ld", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора 'h' с unsigned
START_TEST(test_unsigned_short_int) {
  char buffer1[100];
  char buffer2[100];
  unsigned short int num = 65535;
  int len1 = s21_sprintf(buffer1, "Unsigned Short Int: %hu", num);
  int len2 = sprintf(buffer2, "Unsigned Short Int: %hu", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// Тест для спецификатора 'l' с unsigned
START_TEST(test_unsigned_long_int) {
  char buffer1[100];
  char buffer2[100];
  unsigned long int num = 1234567890UL;
  int len1 = s21_sprintf(buffer1, "Unsigned Long Int: %lu", num);
  int len2 = sprintf(buffer2, "Unsigned Long Int: %lu", num);
  compare_strings(buffer1, buffer2, len1, len2);
}
END_TEST

// strerror
START_TEST(test_s21_strerror_valid_errors) {
  for (int i = 0; i < MAX_ERRLIST; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_s21_strerror_invalid_negative) {
  int error_num = MIN_ERRLIST - 1;
  char expected[512];
  sprintf(expected, "Unknown error: %d", error_num);
  ck_assert_str_eq(s21_strerror(error_num), expected);
}
END_TEST

START_TEST(test_s21_strerror_invalid_positive) {
  int error_num = MAX_ERRLIST + 1;
  char expected[512];
  sprintf(expected, "Unknown error: %d", error_num);
  ck_assert_str_eq(s21_strerror(error_num), expected);
}
END_TEST

START_TEST(test_s21_strerror_boundary_min) {
  int error_num = MIN_ERRLIST;
  char expected[512];
  sprintf(expected, "Unknown error: %d", error_num);
  ck_assert_str_eq(s21_strerror(error_num), expected);
}
END_TEST

START_TEST(test_s21_strerror_boundary_max) {
  int error_num = MAX_ERRLIST - 1;
  ck_assert_str_eq(s21_strerror(error_num), strerror(error_num));
}
END_TEST

// Тесты для s21_to_upper
START_TEST(test_s21_to_upper_norm) {
  char str1[] = "big letters";
  char str2[] = "BIG LETTERS";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_empty) {
  char *str1 = s21_NULL;
  char *str2 = s21_NULL;
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_s21_to_upper_cifer) {
  char str1[] = "567";
  char str2[] = "567";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_upper_different) {
  char str1[] = "DiFferenT";
  char str2[] = "DIFFERENT";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_upper_numblett) {
  char str1[] = "123numbers";
  char str2[] = "123NUMBERS";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_upper_sings) {
  char str1[] = "!,";
  char str2[] = "!,";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_upper_bigletters) {
  char str1[] = "BIG LETTERS";
  char str2[] = "BIG LETTERS";
  char *res = s21_to_upper(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

// Тесты для s21_to_lower

START_TEST(s21_to_lower_signs) {
  char str1[] = "!,";
  char str2[] = "!,";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_lower_norm) {
  char str1[] = "SMALL LETTERS";
  char str2[] = "small letters";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_lower_empty) {
  char *str1 = s21_NULL;
  char *str2 = s21_NULL;
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_lower_mumbers) {
  char str1[] = "567";
  char str2[] = "567";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_lower_different) {
  char str1[] = "DiFferenT";
  char str2[] = "different";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_lower_numbletter) {
  char str1[] = "123NUMBERS";
  char str2[] = "123numbers";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_to_lower_smallletters) {
  char str1[] = "small letters";
  char str2[] = "small letters";
  char *res = s21_to_lower(str1);
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

// тесты на insert

START_TEST(s21_insert_norm) {
  char *src = "See soon";
  char *str1 = "you ";
  s21_size_t start_index = 4;
  char *res = s21_insert(src, str1, start_index);
  char *str2 = "See you soon";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_insert_empty) {
  char *src = "What";
  char *str1 = "";
  s21_size_t start_index = 4;
  char *res = s21_insert(src, str1, start_index);
  char *str2 = "What";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_insert_space) {
  char *src = " ";
  char *str1 = " ";
  s21_size_t start_index = 4;
  char *res = s21_insert(src, str1, start_index);
  char *str2 = s21_NULL;
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_insert_tipanull) {
  char *src = s21_NULL;
  char *str1 = " ";
  s21_size_t start_index = 0;
  char *res = s21_insert(src, str1, start_index);
  char *str2 = s21_NULL;
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_insert_index0) {
  char *src = " are you";
  char *str1 = "How";
  s21_size_t start_index = 0;
  char *res = s21_insert(src, str1, start_index);
  char *str2 = "How are you";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_insert_test1) {
  char *src = " ";
  char *str1 = " ";
  s21_size_t start_index = 0;
  char *res = s21_insert(src, str1, start_index);
  char *str2 = "  ";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_insert_nullprobel) {
  char *src = " ";
  char *str1 = "s21_NULL";
  s21_size_t start_index = 0;
  char *res = s21_insert(src, str1, start_index);
  char *str2 = "s21_NULL ";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

// test trim

START_TEST(s21_trim_test1) {
  char *src = "!No stress!";
  char *str1 = "!";
  char *res = s21_trim(src, str1);
  char *str2 = "No stress";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_trim_test2) {
  char *src = s21_NULL;
  char *str1 = " ";
  char *res = s21_trim(src, str1);
  char *str2 = s21_NULL;
  ck_assert_pstr_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_trim_test3) {
  char *src = "?!!No stress!??";
  char *str1 = "?!";
  char *res = s21_trim(src, str1);
  char *str2 = "No stress";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_trim_test4) {
  char *src = " No stress ";
  char *str1 = " ";
  char *res = s21_trim(src, str1);
  char *str2 = "No stress";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_trim_test5) {
  char *src = "stress1";
  char *str1 = "Stress2";
  char *res = s21_trim(src, str1);
  char *str2 = "1";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_trim_test6) {
  char *src = " ";
  char *str1 = "Stress2 ";
  char *res = s21_trim(src, str1);
  char *str2 = "";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

START_TEST(s21_trim_test7) {
  char *src = "456";
  char *str1 = "what";
  char *res = s21_trim(src, str1);
  char *str2 = "456";
  ck_assert_str_eq(str2, res);
  if (res) free(res);
}
END_TEST

// Функция создания набора тестов
Suite *s21_string_suite_create(void) {
  Suite *suite = suite_create("s21_string");
  TCase *tcase_core = tcase_create("Core");

  // Добавление тестов для s21_strlen
  tcase_add_test(tcase_core, test_s21_strlen_empty);
  tcase_add_test(tcase_core, test_s21_strlen_normal);
  tcase_add_test(tcase_core, test_s21_strlen_spaces);
  tcase_add_test(tcase_core, test_s21_strlen_control_chars);
  tcase_add_test(tcase_core, test_s21_strlen_unicode);

  // Добавление тестов для s21_strchr
  tcase_add_test(tcase_core, test_s21_strchr_present);
  tcase_add_test(tcase_core, test_s21_strchr_not_present);
  tcase_add_test(tcase_core, test_s21_strchr_first_char);
  tcase_add_test(tcase_core, test_s21_strchr_last_char);
  tcase_add_test(tcase_core, test_s21_strchr_empty_string);
  tcase_add_test(tcase_core, test_s21_strchr_null_char);

  // Добавление тестов для s21_strcspn
  tcase_add_test(tcase_core, test_s21_strcspn_present);
  tcase_add_test(tcase_core, test_s21_strcspn_not_present);
  tcase_add_test(tcase_core, test_s21_strcspn_first_char);
  tcase_add_test(tcase_core, test_s21_strcspn_last_char);
  tcase_add_test(tcase_core, test_s21_strcspn_empty_str1);
  tcase_add_test(tcase_core, test_s21_strcspn_empty_str2);
  tcase_add_test(tcase_core, test_s21_strcspn_both_empty);

  // Добавление тестов для s21_strncat
  tcase_add_test(tcase_core, test_s21_strncat_basic);
  tcase_add_test(tcase_core, test_s21_strncat_full);
  tcase_add_test(tcase_core, test_s21_strncat_zero);
  tcase_add_test(tcase_core, test_s21_strncat_empty_src);
  tcase_add_test(tcase_core, test_s21_strncat_empty_dest);
  tcase_add_test(tcase_core, test_s21_strncat_dest_capacity);

  // Добавление тестов для s21_strncmp
  tcase_add_test(tcase_core, test_s21_strncmp_equal);
  tcase_add_test(tcase_core, test_s21_strncmp_less);
  tcase_add_test(tcase_core, test_s21_strncmp_greater);
  tcase_add_test(tcase_core, test_s21_strncmp_partial);
  tcase_add_test(tcase_core, test_s21_strncmp_zero);
  tcase_add_test(tcase_core, test_s21_strncmp_empty);

  // Добавление теста сравнения для s21_strncpy и strncpy
  tcase_add_test(tcase_core, test_s21_strncpy_comparison);

  // Добавление тестов для s21_memcpy
  tcase_add_test(tcase_core, test_s21_memcpy_normal);
  tcase_add_test(tcase_core, test_s21_memcpy_negative);
  tcase_add_test(tcase_core, test_s21_memcpy_empty);

  // Добавление тестов для s21_memset
  tcase_add_test(tcase_core, test_s21_memset_normal);
  tcase_add_test(tcase_core, test_s21_memset_negative);
  tcase_add_test(tcase_core, test_s21_memset_massive);

  // Добавление тестов s21_memchr
  tcase_add_test(tcase_core, test_s21_memchr_found_at_start);
  tcase_add_test(tcase_core, test_s21_memchr_found_at_middle);
  tcase_add_test(tcase_core, test_s21_memchr_found_at_end);
  tcase_add_test(tcase_core, test_s21_memchr_not_found);
  tcase_add_test(tcase_core, test_s21_memchr_zero_byte);
  tcase_add_test(tcase_core, test_s21_memchr_empty_string);

  // memcmp
  tcase_add_test(tcase_core, test_s21_memcmp_equal);
  tcase_add_test(tcase_core, test_s21_memcmp_first_less);
  tcase_add_test(tcase_core, test_s21_memcmp_first_greater);
  tcase_add_test(tcase_core, test_s21_memcmp_partial_equal);
  tcase_add_test(tcase_core, test_s21_memcmp_partial_different);
  tcase_add_test(tcase_core, test_s21_memcmp_empty);
  tcase_add_test(tcase_core, test_s21_memcmp_null_pointer);

  // strpbk
  tcase_add_test(tcase_core, test_s21_strpbrk_found_at_start);
  tcase_add_test(tcase_core, test_s21_strpbrk_found_at_middle);
  tcase_add_test(tcase_core, test_s21_strpbrk_found_at_end);
  tcase_add_test(tcase_core, test_s21_strpbrk_not_found);
  tcase_add_test(tcase_core, test_s21_strpbrk_multiple_accept_one_found);
  tcase_add_test(tcase_core, test_s21_strpbrk_multiple_accept_none_found);
  tcase_add_test(tcase_core, test_s21_strpbrk_empty_string);
  tcase_add_test(tcase_core, test_s21_strpbrk_empty_accept);

  // strrchr
  tcase_add_test(tcase_core, test_s21_strrchr_found_at_start);
  tcase_add_test(tcase_core, test_s21_strrchr_found_at_middle);
  tcase_add_test(tcase_core, test_s21_strrchr_found_at_end);
  tcase_add_test(tcase_core, test_s21_strrchr_not_found);
  tcase_add_test(tcase_core, test_s21_strrchr_multiple_occurrences);
  tcase_add_test(tcase_core, test_s21_strrchr_zero_byte);
  tcase_add_test(tcase_core, test_s21_strrchr_empty_string);

  // strstr
  tcase_add_test(tcase_core, test_s21_strstr_found_at_start);
  tcase_add_test(tcase_core, test_s21_strstr_found_at_middle);
  tcase_add_test(tcase_core, test_s21_strstr_found_at_end);
  tcase_add_test(tcase_core, test_s21_strstr_not_found);
  tcase_add_test(tcase_core, test_s21_strstr_empty_needle);
  tcase_add_test(tcase_core, test_s21_strstr_empty_haystack_and_needle);
  tcase_add_test(tcase_core, test_s21_strstr_needle_longer_than_haystack);

  // strtok
  tcase_add_test(tcase_core, test_s21_strtok_single_delim);
  tcase_add_test(tcase_core, test_s21_strtok_multiple_delims);
  tcase_add_test(tcase_core, test_s21_strtok_leading_delims);
  tcase_add_test(tcase_core, test_s21_strtok_empty_tokens);
  tcase_add_test(tcase_core, test_s21_strtok_all_delims);
  tcase_add_test(tcase_core, test_s21_strtok_empty_string);

  // sprintf
  tcase_add_test(tcase_core, test_char);
  tcase_add_test(tcase_core, test_signed_int);
  tcase_add_test(tcase_core, test_signed_int_1);
  tcase_add_test(tcase_core, test_signed_int_2);
  tcase_add_test(tcase_core, test_signed_int_3);
  tcase_add_test(tcase_core, test_signed_int_4);
  tcase_add_test(tcase_core, test_signed_int_5);
  tcase_add_test(tcase_core, test_float);
  tcase_add_test(tcase_core, test_string);
  tcase_add_test(tcase_core, test_unsigned_int);
  tcase_add_test(tcase_core, test_percent);
  tcase_add_test(tcase_core, test_short_int);
  tcase_add_test(tcase_core, test_long_int);
  tcase_add_test(tcase_core, test_unsigned_short_int);
  tcase_add_test(tcase_core, test_unsigned_long_int);

  // error
  tcase_add_test(tcase_core, test_s21_strerror_valid_errors);
  tcase_add_test(tcase_core, test_s21_strerror_invalid_negative);
  tcase_add_test(tcase_core, test_s21_strerror_invalid_positive);
  tcase_add_test(tcase_core, test_s21_strerror_boundary_min);
  tcase_add_test(tcase_core, test_s21_strerror_boundary_max);

  // Добавление тестов для s21_to_upper

  tcase_add_test(tcase_core, test_s21_to_upper_norm);
  tcase_add_test(tcase_core, test_s21_to_upper_empty);
  tcase_add_test(tcase_core, test_s21_to_upper_cifer);
  tcase_add_test(tcase_core, s21_to_upper_different);
  tcase_add_test(tcase_core, s21_to_upper_numblett);
  tcase_add_test(tcase_core, s21_to_upper_sings);
  tcase_add_test(tcase_core, s21_to_upper_bigletters);

  // Добавление тестов для s21_to_lower
  tcase_add_test(tcase_core, s21_to_lower_signs);
  tcase_add_test(tcase_core, s21_to_lower_norm);
  tcase_add_test(tcase_core, s21_to_lower_empty);
  tcase_add_test(tcase_core, s21_to_lower_mumbers);
  tcase_add_test(tcase_core, s21_to_lower_different);
  tcase_add_test(tcase_core, s21_to_lower_numbletter);
  tcase_add_test(tcase_core, s21_to_lower_smallletters);

  // insert test

  tcase_add_test(tcase_core, s21_insert_norm);
  tcase_add_test(tcase_core, s21_insert_empty);
  tcase_add_test(tcase_core, s21_insert_space);
  tcase_add_test(tcase_core, s21_insert_tipanull);
  tcase_add_test(tcase_core, s21_insert_index0);
  tcase_add_test(tcase_core, s21_insert_test1);
  tcase_add_test(tcase_core, s21_insert_nullprobel);

  // trim

  tcase_add_test(tcase_core, s21_trim_test1);
  tcase_add_test(tcase_core, s21_trim_test2);
  tcase_add_test(tcase_core, s21_trim_test3);
  tcase_add_test(tcase_core, s21_trim_test4);
  tcase_add_test(tcase_core, s21_trim_test5);
  tcase_add_test(tcase_core, s21_trim_test6);
  tcase_add_test(tcase_core, s21_trim_test7);

  // Добавление группы тестов в тестовый набор
  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  int failed_count;
  Suite *suite = s21_string_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  // Сигнализируем о том, что тестирование прошло неудачно
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
