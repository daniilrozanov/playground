#include <readcmd/readcmd.h>
#include <readcmd/readline.h>
#include <unistd.h>

enum states : char
{
  IN_LITERAL = 1 << 1,
  BACKSLASH_END = 1 << 2
};

char* readcmd(const char* prompt)
{
  char* command;
  char state = 0;

  do
  {
    char* line = readline(prompt);
  } while (is_in_literal);
  return 0;
}
