#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libasm.h"

void test_strlen() {
  FILE    *fp;
  char    *line = NULL;
  size_t  len = 0;
  ssize_t read;

  printf("--- Testing ft_strlen ---\n");
  fp = fopen("test_strlen", "r");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }

  int passed = 0;
  int failed = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    int expected = strlen(line);
    int actual = ft_strlen(line);

    if (expected != actual) {
      printf("expected %d, got %d\n", expected, actual);
      failed += 1;
    } else {
      passed += 1;
    }
  }

  printf("%d passed, %d failed\n", passed, failed);
}

void test_strcpy() {
  FILE    *fp;
  char    *line = NULL;
  size_t  len = 0;
  ssize_t read;

  printf("--- Testing ft_strcpy ---\n");
  fp = fopen("test_strcpy", "r");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }

  int passed = 0;
  int failed = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    char *dst1 = malloc(sizeof(char) * (len + 1));
    char *dst2 = malloc(sizeof(char) * (len + 1));

    char *expected = strcpy(dst1, line);
    char *actual = ft_strcpy(dst2, line);

    if (strcmp(expected, actual) != 0) {
      printf("expected %s, got %s\n", expected, actual);
      failed += 1;
    } else {
      passed += 1;
    }

    free(dst1);
    free(dst2);
  }

  printf("%d passed, %d failed\n", passed, failed);
}

int main () {
  // test_strlen();
  test_strcpy();
  return (0);
}
