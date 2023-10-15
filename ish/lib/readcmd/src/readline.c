#include <printf.h>
#include <readcmd/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef ISH_BUFFER_LIST_SIZE
#define ISH_BUFFER_LIST_SIZE 8
#endif

typedef struct buffer_list
{
  struct buffer_list* next;
  char* buffer;
  int len;
} buffer_list;

static int get_buffer_list_len(buffer_list* buf)
{
  int len = 0;
  do
  {
    len += buf->len;
  } while ((buf = buf->next));
  return len;
}

static char* get_buffer_string(buffer_list* buf)
{
  char* str = malloc(get_buffer_list_len(buf) + 1);
  int shift = 0;
  int count = 0;
  buffer_list* next;

  do
  {
    memcpy(str + shift, buf->buffer, buf->len);
    shift += buf->len;
    next = buf->next;
    free(buf->buffer);
    if (count++)
      free(buf);
  } while ((buf = next));
  str[shift] = 0;
  return str;
}

char* readline(const char* prompt)
{
  buffer_list start_buf;
  buffer_list* current_buf = &start_buf;
  int n;

  start_buf.next = 0;
  write(1, prompt, strlen(prompt));
  do
  {
    current_buf->buffer = malloc(ISH_BUFFER_LIST_SIZE + 1);
    n = read(0, current_buf->buffer, ISH_BUFFER_LIST_SIZE);
    current_buf->len = n;
    current_buf->buffer[n] = 0;
    if (n == ISH_BUFFER_LIST_SIZE)
      current_buf = current_buf->next = malloc(sizeof(buffer_list));
  } while (n == ISH_BUFFER_LIST_SIZE);
  if (start_buf.len == 0)
  {
    free(start_buf.buffer);
    return 0;
  }
  if (current_buf == &start_buf)
    return current_buf->buffer;
  return get_buffer_string(&start_buf);
}
