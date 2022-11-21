#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

void test_line_strdup(char *line, int len, int *passed, int *failed)
{
  (void)len;
  char *expected = strdup(line);
  char *actual = ft_strdup(line);

  if (strcmp(expected, actual) != 0)
  {
    printf("expected %s, got %s\n", expected, actual);
    *failed += 1;
  }
  else
  {
    *passed += 1;
  }

  free(expected);
  free(actual);
}
