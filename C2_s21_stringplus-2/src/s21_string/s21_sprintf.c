#include <stdarg.h>
#include <string.h>

#include "../s21_string.h"

// Функция для обработки спецификатора 'c'
void handle_char(char **ptr, va_list args) {
  char c = (char)va_arg(args, int);
  **ptr = c;
  (*ptr)++;
}

// Функция для обработки спецификатора 'd' и 'i'
void handle_signed_int(char **ptr, int value, Format sing) {
  char buffer[20];
  int index = 0;

  // Обработка знака
  if (value < 0) {
    buffer[index++] = '-';
    value = -value;
  } else if (sing.plus) {
    buffer[index++] = '+';
  }

  // Преобразование числа в строку
  char temp[20];
  int temp_index = 0;
  do {
    temp[temp_index++] = (value % 10) + '0';
    value /= 10;
  } while (value > 0);

  // Переворот строки
  while (temp_index > 0) {
    buffer[index++] = temp[--temp_index];
  }

  buffer[index] = '\0';

  // Добавление пробелов для выравнивания
  int length = s21_strlen(buffer);
  if (sing.width > length && !sing.minus) {
    for (int i = 0; i < sing.width - length; i++) {
      **ptr = ' ';
      (*ptr)++;
    }
  }

  s21_strcpy(*ptr, buffer);
  *ptr += s21_strlen(buffer);

  if (sing.width > length && sing.minus) {
    for (int i = length; i < sing.width; i++) {
      **ptr = ' ';
      (*ptr)++;
    }
  }
}

// Функция для обработки спецификатора 'f'
void handle_float(char **ptr, va_list args, Format sing) {
  double value = va_arg(args, double);
  int int_part = (int)value;
  double frac_part = value - int_part;

  // Округление дробной части до указанного количества знаков
  int precision = (sing.precision >= 0) ? sing.precision : 6;
  double rounding = 0.5;
  for (int i = 0; i < precision; i++) {
    rounding /= 10.0;
  }
  frac_part += rounding;

  // Обработка целой части
  // Format int_sing = sing;
  // int_sing.precision = -1;
  handle_signed_int(ptr, int_part, sing);

  **ptr = '.';
  (*ptr)++;

  // Обработка дробной части
  for (int i = 0; i < precision; i++) {
    frac_part *= 10;
    int digit = (int)frac_part;
    frac_part -= digit;
    **ptr = digit + 48;
    (*ptr)++;
  }
}

// Функция для обработки спецификатора 's'
void handle_string(char **ptr, va_list args) {
  char *value = va_arg(args, char *);
  s21_strcpy(*ptr, value);
  *ptr += s21_strlen(value);
}

// Функция для обработки спецификатора 'u'
void handle_unsigned_int(char **ptr, va_list args) {
  unsigned int value = va_arg(args, unsigned int);
  char buffer[20];
  int index = 0;

  // Преобразование числа в строку
  char temp[20];
  int temp_index = 0;
  do {
    temp[temp_index++] = (value % 10) + '0';
    value /= 10;
  } while (value > 0);

  // Переворот строки
  while (temp_index > 0) {
    buffer[index++] = temp[--temp_index];
  }

  buffer[index] = '\0';
  s21_strcpy(*ptr, buffer);
  *ptr += s21_strlen(buffer);
}

// Функция для обработки спецификатора '%'
void handle_percent(char **ptr) {
  **ptr = '%';
  (*ptr)++;
}

void parser_format(const char **fmt, Format *sing) {
  sing->plus = 0;
  sing->minus = 0;
  sing->precision = -1;
  sing->width = 0;
  sing->length = '\0';

  // парсинг флагов
  while (**fmt == '+' || **fmt == '-') {
    if (**fmt == '+') sing->plus = 1;
    if (**fmt == '-') sing->minus = 1;
    (*fmt)++;
  }
  //парсинг ширины
  while (**fmt >= '0' && **fmt <= '9') {
    sing->width = sing->width * 10 + (**fmt - '0');
    (*fmt)++;
  }

  //парсинг точности
  if (**fmt == '.') {
    (*fmt)++;
    sing->precision = 0;
    while (**fmt >= '0' && **fmt <= '9') {
      sing->precision = sing->precision * 10 + (**fmt - '0');
      (*fmt)++;
    }
  }
  //парсинг длины
  if (**fmt == 'h' || **fmt == 'l') {
    sing->length = **fmt;
    (*fmt)++;
  }
}

// Основная функция s21_sprintf
int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  char *ptr = str;
  const char *fmt = format;

  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      Format sing;
      parser_format(&fmt, &sing);

      switch (*fmt) {
        case 'c':
          handle_char(&ptr, args);
          break;
        case 'd':
        case 'i':
          handle_signed_int(&ptr, va_arg(args, int), sing);
          break;
        case 'f':
          handle_float(&ptr, args, sing);
          break;
        case 's':
          handle_string(&ptr, args);
          break;
        case 'u':
          handle_unsigned_int(&ptr, args);
          break;
        case '%':
          handle_percent(&ptr);
          break;
      }
    } else {
      *ptr++ = *fmt;
    }
    fmt++;
  }

  *ptr = '\0';  // Завершение строки
  va_end(args);
  return ptr - str;  // Возвращаем длину строки
}
