#include <stdlib.h>
#include <stdio.h>

#include "libasm.h"

t_list  *create_node(void *data) {
  t_list *node = (t_list*)malloc(sizeof(void*) + sizeof(t_list*));
  node->data = data;
  node->next = NULL;
  return node;
}

void print_node(t_list *node) {
  if (node == NULL) return;

  printf("ptr: %p\n", node);
  printf("data: %d\n", *(uint*)&node->data);
  printf("next: %p\n", node->next);
}

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
