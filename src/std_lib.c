#include "std_lib.h"

int div(int a, int b) {
  int res = 0;
  int neg = 0;
  if (a < 0) { a = -a; neg = !neg; }
  if (b < 0) { b = -b; neg = !neg; }
  while (a >= b) { a -= b; res++; }
  return neg ? -res : res;
}

int mod(int a, int b) {
  int neg = 0;
  if (a < 0) { a = -a; neg = 1; }
  if (b < 0) b = -b;
  while (a >= b) a -= b;
  return neg ? -a : a;
}

bool strcmp(char *a, char *b) {
  while (*a && *b) {
    if (*a != *b) return false;
    a++; b++;
  }
  return *a == *b;
}

int strncmp(char *a, char *b, int n) {
  int i = 0;
  while (i < n) {
    if (a[i] != b[i] || a[i] == '\0' || b[i] == '\0') return 0;
    i++;
  }
  return 1;
}

void strcpy(char *dst, char *src) {
  while (*src) {
    *dst = *src;
    dst++; src++;
  }
  *dst = '\0';
}

void clear(byte *buf, unsigned int size) {
  unsigned int i;
  for (i = 0; i < size; i++) {
    buf[i] = 0;
  }
}

void atoi(char *str, int *num) {
  int sign = 1, res = 0, i = 0;
  if (str[0] == '-') { sign = -1; i++; }
  while (str[i] >= '0' && str[i] <= '9') {
    res = res * 10 + (str[i] - '0');
    i++;
  }
  *num = res * sign;
}

void itoa(int num, char *str) {
  int i = 0, neg = 0;
  int j, k;

  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return;
  }
  if (num < 0) {
    neg = 1;
    num = -num; // Pastikan num positif untuk pemrosesan
  }
  while (num != 0) {
    str[i++] = mod(num, 10) + '0'; // Diubah: Gunakan fungsi mod()
    num = div(num, 10);          // Diubah: Gunakan fungsi div()
  }
  if (neg) str[i++] = '-';
  str[i] = '\0';

  // Reverse string
  j = 0;
  k = i - 1;
  while (j < k) {
    char tmp = str[j];
    str[j] = str[k];
    str[k] = tmp;
    j++;
    k--;
  }
}
