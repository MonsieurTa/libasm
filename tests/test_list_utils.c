#include <stdlib.h>
#include <stdio.h>

#include "libasm.h"

t_list  *create_node(void *data) {
  t_list *node = (t_list*)malloc(sizeof(void*) + sizeof(t_list*));
  node->data = data;
  node->next = NULL;
  return node;
}

t_list *create_list(int n) {
  t_list *lst = NULL;

  for (int i = 0; i < n; i++) {
    ft_list_push_front(&lst, create_node(*(void**)&i));
  }
  return lst;
}
