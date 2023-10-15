#include <readcmd/buffer_list.h>
#include <readcmd/readcmd.h>
#include <readcmd/readline.h>
#include <stdlib.h>
#include <unistd.h>

enum state : char
{
  READY = 0,
  QUOTE = 1 << 0,
  DQUOTE = 1 << 1,
  BACKSLASH = 1 << 2,
  BACKSLASH_IN_DQUOTE = 1 << 3,
  BACKSLASH_NL = 1 << 4,
};

static char* state_to_prompt(enum state state)
{
  switch (state)
  {
  case QUOTE: return "quote> ";
  case DQUOTE: return "dquote> ";
  default: return "> ";
  }
}

static void set_state(const char* str, enum state* state)
{
  if (str == 0)
    return;
  while (*str)
  {
    switch (*state)
    {
    case QUOTE:
      if (*str == '\'')
        *state = READY;
      break;
    case DQUOTE:
      if (*str == '"')
        *state = READY;
      else if (*str == '\\')
        *state = BACKSLASH_IN_DQUOTE;
      break;
    case BACKSLASH:
      if (*str == '\n')
        *state = BACKSLASH_NL;
      else
        *state = READY;
      break;
    case BACKSLASH_NL:
      if (*str == '\\')
        *state = BACKSLASH;
      else if (*str == '\'')
        *state = QUOTE;
      else if (*str == '"')
        *state = DQUOTE;
      break;
    case BACKSLASH_IN_DQUOTE: *state = DQUOTE; break;
    case READY:
      if (*str == '\'')
        *state = QUOTE;
      else if (*str == '"')
        *state = DQUOTE;
      else if (*str == '\\')
        *state = BACKSLASH;
      break;
    }
    str++;
  }
}

char* readcmd(const char* prompt)
{
  buffer_list *first_buf, *current_buf;
  char* cmd;
  int i = 0;
  enum state state = READY;

  current_buf = readline(prompt);
  first_buf = current_buf;
  if (current_buf == 0)
    return 0;
  for (set_state(current_buf->buffer, &state); state;)
  {
    current_buf = current_buf->next = readline(state_to_prompt(state));
    set_state(current_buf->buffer, &state);
  }
  join_buffer_list(first_buf);
  cmd = first_buf->buffer;
  free(first_buf);
  return cmd;
}
