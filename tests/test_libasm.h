void _test(char *test_name, char *filepath, void (*test_fn)(char *, int, int *, int *));
void test_line_strlen(char *line, int len, int *passed, int *failed);
void test_line_strcpy(char *line, int len, int *passed, int *failed);
void test_line_strcmp(char *line, int len, int *passed, int *failed);
void test_write();
void test_read();
void test_line_strdup(char *line, int len, int *passed, int *failed);
void test_atoi_base();
void test_list_push_front();
