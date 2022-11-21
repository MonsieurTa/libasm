#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

void test_line_strcmp(char *line, int len, int *passed, int *failed)
{
  (void)len;
  char *str1 = NULL;
  char *str2 = NULL;

  str1 = strtok(line, ":");
  str2 = strtok(NULL, ":");

  str1[strcspn(str1, "\r\n")] = '\0';
  str2[strcspn(str2, "\r\n")] = '\0';

  int expected = strcmp(str1, str2);
  int actual = ft_strcmp(str1, str2);

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
