#ifndef BUFFER_LIST_H
#define BUFFER_LIST_H

typedef struct buffer_list
{
  struct buffer_list* next;
  char* buffer;
  int len;
} buffer_list;

int get_buffer_list_len(buffer_list* buf);

char* get_buffer_string(buffer_list* buf);

buffer_list* join_buffer_list(buffer_list* buf);

#endif  // !BUFFER_LIST_H
