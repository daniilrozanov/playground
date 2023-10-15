#include "readcmd/buffer_list.h"
#include <readcmd/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
  while (1)
  {
    buffer_list* buf = readline("line: ");
    if (!buf)
      return 1;
    write(1, buf->buffer, strlen(buf->buffer));
    free(buf);
  }
}
