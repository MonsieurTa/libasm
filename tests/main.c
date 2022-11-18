#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "libasm.h"

void _test(char *test_name, char *filepath, void (*test_fn)(char*, int, int*, int*)) {
  FILE    *fp;
  char    *line = NULL;
  size_t  len = 0;
  ssize_t read;

  printf("--- Testing %s ---\n", test_name);
  fp = fopen(filepath, "r");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }

  int passed = 0;
  int failed = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    test_fn(line, read, &passed, &failed);
    free(line);
    line = NULL;
  }
  close(fileno(fp));
  printf("%d passed, %d failed\n", passed, failed);
}

void test_line_strlen(char *line, int len, int *passed, int *failed) {
  (void)len;

  int expected = strlen(line);
  int actual = ft_strlen(line);

  if (expected != actual) {
    printf("expected %d, got %d\n", expected, actual);
    *failed += 1;
  } else {
    *passed += 1;
  }
}

void test_line_strcpy(char *line, int len, int *passed, int *failed) {
  char *dst1 = malloc(sizeof(char) * (len + 1));
  char *dst2 = malloc(sizeof(char) * (len + 1));

  char *expected = strcpy(dst1, line);
  char *actual = ft_strcpy(dst2, line);

  if (strcmp(expected, actual) != 0) {
    printf("expected %s, got %s\n", expected, actual);
    *failed += 1;
  } else {
    *passed += 1;
  }

  free(dst1);
  free(dst2);
}

void test_line_strcmp(char *line, int len, int *passed, int *failed) {
  (void)len;
  char *str1 = NULL;
  char *str2 = NULL;

  str1 = strtok(line, ":");
  str2 = strtok(NULL, ":");

  str1[strcspn(str1, "\r\n")] = '\0';
  str2[strcspn(str2, "\r\n")] = '\0';

  int expected = strcmp(str1, str2);
  int actual = ft_strcmp(str1, str2);

  if (expected != actual) {
    printf("expected %d, got %d\n", expected, actual);
    *failed += 1;
  } else {
    *passed += 1;
  }
}

void test_line_write(char *line, int len, int *passed, int *failed) {
  FILE *tmp_fd1 = tmpfile();
  FILE *tmp_fd2 = tmpfile();

  int expected = write(fileno(tmp_fd1), line, len);
  int actual = ft_write(fileno(tmp_fd2), line, len);

  if (expected != actual) {
    printf("expected %d, got %d\n", expected, actual);
    *failed += 1;
    return;
  }

  char *buffer1 = NULL;
  char *buffer2 = NULL;
  size_t len1;
  size_t len2;

  getdelim(&buffer1, &len1, '\0', tmp_fd1);
  getdelim(&buffer2, &len2, '\0', tmp_fd2);

  int diff = strcmp(buffer1, buffer2);
  if (diff != 0) {
    printf("got diff");
    *failed += 1;
    return;
  }

  *passed += 1;
  close(fileno(tmp_fd1));
  close(fileno(tmp_fd2));
}

void test_write() {
  _test("ft_write", "./tests/assets/test_read_write", test_line_write);

  printf("--- Testing ft_write#errno ---\n");
  int passed = 0;
  int failed = 0;

  write(-1, NULL, 0);
  int expected = errno;
  ft_write(-1, NULL, 0);
  int actual = errno;
  if (expected != actual) {
    failed += 1;
  } else {
    passed += 1;
  }
  printf("%d passed, %d failed\n", passed, failed);
}

void test_read() {
  FILE    *fp1;
  FILE    *fp2;
  char    buffer[43];
  int     passed = 0;
  int     failed = 0;
  int     expected;
  int     actual;

  printf("--- Testing ft_read ---\n");
  fp1 = fopen("./tests/assets/test_read_write", "r");
  fp2 = fopen("./tests/assets/test_read_write", "r");
  if (fp1 == NULL || fp2 == NULL) {
    exit(EXIT_FAILURE);
  }

  buffer[42] = 0;

  while ((expected = read(fileno(fp1), buffer, 42)) > 0
  && (actual = ft_read(fileno(fp2), buffer, 42)) > 0) {
    if (expected != actual) {
      printf("expected: %d, got: %d\n", expected, actual);
      failed += 1;
    } else {
      passed += 1;
    }
  }
  printf("%d passed, %d failed\n", passed, failed);

  printf("--- Testing ft_read#errno ---\n");
  passed = 0;
  failed = 0;

  read(-1, buffer, 42);
  expected = errno;
  ft_read(-1, buffer, 42);
  actual = errno;
  if (expected != actual) {
    printf("expected: %d, got: %d\n", expected, actual);
    failed += 1;
  } else {
    passed += 1;
  }

  close(fileno(fp1));
  close(fileno(fp2));
  printf("%d passed, %d failed\n", passed, failed);
}

void test_line_strdup(char *line, int len, int *passed, int *failed) {
  (void)len;
  char *expected = strdup(line);
  char *actual = ft_strdup(line);

  if (strcmp(expected, actual) != 0) {
    printf("expected %s, got %s\n", expected, actual);
    *failed += 1;
  } else {
    *passed += 1;
  }

  free(expected);
  free(actual);
}

void test_atoi_base() {
  int expected;
  int actual;

  // expected = 0;
  // actual = ft_atoi_base(" \f\n\r\t\v", 10);

  // printf("expected %d, got %d\n", expected, actual);

  expected = 4;
  actual = ft_atoi_base("4", 10);
  printf("expected %d, got %d\n", expected, actual);

  expected = 10;
  actual = ft_atoi_base("A", 16);
  printf("expected %d, got %d\n", expected, actual);
  actual = ft_atoi_base("a", 16);
  printf("expected %d, got %d\n", expected, actual);

  expected = 2;
  actual = ft_atoi_base("10", 2);
  printf("expected %d, got %d\n", expected, actual);

  expected = 2048;
  actual = ft_atoi_base("2048", 10);
  printf("expected %d, got %d\n", expected, actual);
  actual = ft_atoi_base("800", 16);
  printf("expected %d, got %d\n", expected, actual);
}

int main () {
  // _test("ft_strlen", "./tests/assets/test_strlen", test_line_strlen);
  // _test("ft_strcpy", "./tests/assets/test_strcpy", test_line_strcpy);
  // _test("ft_strcmp", "./tests/assets/test_strcmp", test_line_strcmp);
  // test_write();
  // test_read();
  // _test("ft_strdup", "./tests/assets/test_read_write", test_line_strdup);
  test_atoi_base();
  return (0);
}
