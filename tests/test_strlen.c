#include <stdio.h>
#include <string.h>

#include "libasm.h"

void test_line_strlen(char *line, int len, int *passed, int *failed)
{
  (void)len;

  int expected = strlen(line);
  int actual = ft_strlen(line);

  if (expected != actual)
  {
    printf("expected %d, got %d\n", expected, actual);
    *failed += 1;
  }
  else
  {
    *passed += 1;
  }
}
