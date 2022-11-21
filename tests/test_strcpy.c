#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

void test_line_strcpy(char *line, int len, int *passed, int *failed)
{
  char *dst1 = malloc(sizeof(char) * (len + 1));
  char *dst2 = malloc(sizeof(char) * (len + 1));

  char *expected = strcpy(dst1, line);
  char *actual = ft_strcpy(dst2, line);

  if (strcmp(expected, actual) != 0)
  {
    printf("expected %s, got %s\n", expected, actual);
    *failed += 1;
  }
  else
  {
    *passed += 1;
  }

  free(dst1);
  free(dst2);
}
