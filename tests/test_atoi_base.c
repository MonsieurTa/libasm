#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

void test_atoi_base()
{
  int expected;
  int actual;
  int passed = 0;
  int failed = 0;

  printf("--- Testing ft_atoi_base ---\n");

  expected = 0;
  actual = ft_atoi_base(" \f\n\r\t\v", 10);

  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 4;
  actual = ft_atoi_base("4", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 10;
  actual = ft_atoi_base("A", 16);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  actual = ft_atoi_base("a", 16);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 255;
  actual = ft_atoi_base("FF", 16);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  actual = ft_atoi_base("ff", 16);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 2;
  actual = ft_atoi_base("10", 2);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 2048;
  actual = ft_atoi_base("2048", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  actual = ft_atoi_base("800", 16);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 0;
  actual = ft_atoi_base("/800", 16);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  actual = ft_atoi_base("[800", 16);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = -1;
  actual = ft_atoi_base("-1", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  actual = ft_atoi_base("    -1", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 1;
  actual = ft_atoi_base("+1", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  actual = ft_atoi_base("    +1", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = -2147483648;
  actual = ft_atoi_base("-2147483648", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }

  expected = 2147483647;
  actual = ft_atoi_base("2147483647", 10);
  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  printf("%d passed, %d failed\n", passed, failed);
}
