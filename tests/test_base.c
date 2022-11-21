#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void _test(char *test_name, char *filepath, void (*test_fn)(char *, int, int *, int *))
{
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  printf("--- Testing %s ---\n", test_name);
  fp = fopen(filepath, "r");
  if (fp == NULL)
  {
    exit(EXIT_FAILURE);
  }

  int passed = 0;
  int failed = 0;
  while ((read = getline(&line, &len, fp)) != -1)
  {
    test_fn(line, read, &passed, &failed);
    free(line);
    line = NULL;
  }
  close(fileno(fp));
  printf("%d passed, %d failed\n", passed, failed);
}
