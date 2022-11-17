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

void test_strlen(char *line, int len, int *passed, int *failed) {
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

void test_strcpy(char *line, int len, int *passed, int *failed) {
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

void test_strcmp(char *line, int len, int *passed, int *failed) {
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

void test_write(char *line, int len, int *passed, int *failed) {
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
}

int main () {
  _test("ft_strlen", "./tests/assets/test_strlen", test_strlen);
  _test("ft_strcpy", "./tests/assets/test_strcpy", test_strcpy);
  _test("ft_strcmp", "./tests/assets/test_strcmp", test_strcmp);
  _test("ft_write", "./tests/assets/test_write", test_write);
  return (0);
}
