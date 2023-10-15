#include <printf.h>
#include <readcmd/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef ISH_BUFFER_LIST_SIZE
#define ISH_BUFFER_LIST_SIZE 8
#endif

buffer_list* readline(const char* prompt)
{
  buffer_list* start_buf = malloc(sizeof(buffer_list));
  buffer_list* current_buf = start_buf;
  int n;
  char not_nl_end;

  start_buf->next = 0;
  if (prompt != 0)
    write(1, prompt, strlen(prompt));
  do
  {
    current_buf->buffer = malloc(ISH_BUFFER_LIST_SIZE + 1);
    n = read(0, current_buf->buffer, ISH_BUFFER_LIST_SIZE);
    current_buf->len = n;
    current_buf->buffer[n] = 0;
    not_nl_end = current_buf->buffer[n - 1] != '\n';
    if (n == ISH_BUFFER_LIST_SIZE && not_nl_end)
      current_buf = current_buf->next = malloc(sizeof(buffer_list));
  } while (n == ISH_BUFFER_LIST_SIZE && not_nl_end);
  if (start_buf->len == 0)
  {
    free(start_buf->buffer);
    return 0;
  }
  if (current_buf == start_buf)
    return current_buf;
  return join_buffer_list(start_buf);
}
