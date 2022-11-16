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

int main () {
  test_strlen();
  return (0);
}
