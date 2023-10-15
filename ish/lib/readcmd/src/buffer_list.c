#include <readcmd/buffer_list.h>
#include <stdlib.h>
#include <string.h>

int get_buffer_list_len(buffer_list* buf)
{
  int len = 0;
  do
  {
    len += buf->len;
  } while ((buf = buf->next));
  return len;
}

char* get_buffer_string(buffer_list* buf)
{
  int len = get_buffer_list_len(buf);
  char* str = malloc(len + 1);
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

buffer_list* join_buffer_list(buffer_list* buf)
{
  int len;
  char* str;
  int shift = 0, count = 0;
  buffer_list *first = buf, *next;

  if (buf == 0)
    return 0;
  if (buf->next == 0)
    return buf;
  len = get_buffer_list_len(buf);
  str = malloc(len + 1);
  do
  {
    memcpy(str + shift, buf->buffer, buf->len);
    shift += buf->len;
    next = buf->next;
    if (count++)
    {
      free(buf->buffer);
      free(buf);
    }
  } while ((buf = next));
  str[shift] = 0;
  first->buffer = str;
  first->len = len;
  first->next = 0;
  return first;
}
