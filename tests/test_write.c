#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "test_libasm.h"
#include "libasm.h"

void test_line_write(char *line, int len, int *passed, int *failed)
{
  FILE *tmp_fd1 = tmpfile();
  FILE *tmp_fd2 = tmpfile();

  int expected = write(fileno(tmp_fd1), line, len);
  int actual = ft_write(fileno(tmp_fd2), line, len);

  if (expected != actual)
  {
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
  if (diff != 0)
  {
    printf("got diff");
    *failed += 1;
    return;
  }

  *passed += 1;
  close(fileno(tmp_fd1));
  close(fileno(tmp_fd2));
}

void test_write()
{
  _test("ft_write", "./tests/assets/test_read_write", test_line_write);

  printf("--- Testing ft_write#errno ---\n");
  int passed = 0;
  int failed = 0;

  write(-1, NULL, 0);
  int expected = errno;
  ft_write(-1, NULL, 0);
  int actual = errno;
  if (expected != actual)
  {
    failed += 1;
  }
  else
  {
    passed += 1;
  }
  printf("%d passed, %d failed\n", passed, failed);
}
