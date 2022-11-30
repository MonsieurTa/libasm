#include <stdlib.h>
#include <stdio.h>

#include "libasm.h"

t_list  *create_node(void *data);
t_list *create_list(int n);

void clear_list(t_list *head) {
  t_list *node = head;
  t_list *next = NULL;

  while (node != NULL) {
    next = node->next;
    free(node);
    node = next;
  }
}

void test_list_size() {
  int expected = 1;
  t_list *lst = create_list(expected);
  int actual = ft_list_size(lst);

  if (actual != expected) {
    printf("expected %d, got %d\n", expected, actual);
  }
  clear_list(lst);

  expected = 10;
  lst = create_list(expected);
  actual = ft_list_size(lst);

  if (actual != expected) {
    printf("expected %d, got %d\n", expected, actual);
  }
  clear_list(lst);

  expected = 100;
  lst = create_list(expected);
  actual = ft_list_size(lst);

  if (actual != expected) {
    printf("expected %d, got %d\n", expected, actual);
  }
  clear_list(lst);
}
