#include <readcmd/readline.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
  while (1)
  {
    char* str = readline("line: ");
    if (!str)
      return 1;
    write(1, str, strlen(str));
    free(str);
  }
}
