#include <stdlib.h>
#include <stdio.h>

#include "libasm.h"

t_list  *create_node(void *data);

void test_list_push_front() {
  t_list *lst = NULL;

  for (uint i = 0; i < 10; i++) {
    ft_list_push_front(&lst, create_node(*(void**)&i));
  }

  uint expected = 9;
  for (t_list *node = lst; node != NULL;) {
    t_list *next = node->next;

    uint actual = *(uint*)&node->data;
    if (actual != expected) {
      printf("expected %u, got %u\n", expected, actual);
    }

    free(node);
    node = next;
    expected -= 1;
  }
}
