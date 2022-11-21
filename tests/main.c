#include "test_libasm.h"

int main()
{
  _test("ft_strlen", "./tests/assets/test_strlen", test_line_strlen);
  _test("ft_strcpy", "./tests/assets/test_strcpy", test_line_strcpy);
  _test("ft_strcmp", "./tests/assets/test_strcmp", test_line_strcmp);
  test_write();
  test_read();
  _test("ft_strdup", "./tests/assets/test_read_write", test_line_strdup);
  test_atoi_base();
  return (0);
}
