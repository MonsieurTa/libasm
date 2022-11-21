#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "libasm.h"

void test_read()
{
  FILE *fp1;
  FILE *fp2;
  char buffer[43];
  int passed = 0;
  int failed = 0;
  int expected;
  int actual;

  printf("--- Testing ft_read ---\n");
  fp1 = fopen("./tests/assets/test_read_write", "r");
  fp2 = fopen("./tests/assets/test_read_write", "r");
  if (fp1 == NULL || fp2 == NULL)
  {
    exit(EXIT_FAILURE);
  }

  buffer[42] = 0;

  while ((expected = read(fileno(fp1), buffer, 42)) > 0 && (actual = ft_read(fileno(fp2), buffer, 42)) > 0)
  {
    if (expected != actual)
    {
      printf("expected: %d, got: %d\n", expected, actual);
      failed += 1;
    }
    else
    {
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
  if (expected != actual)
  {
    printf("expected: %d, got: %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  close(fileno(fp1));
  close(fileno(fp2));
  printf("%d passed, %d failed\n", passed, failed);
}
