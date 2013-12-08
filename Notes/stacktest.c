#include <stdio.h>
#include <string.h>//strlen()
#include "stack.h"

int stacktest(void);

int stacktest(void)
{
  STACK stack;
  char str[101];
  char *pos;

  printf("Enter a string: ");
  scanf("%s",str);

  //initilize the stack
  S_Init(&stack, strlen(str));

  //continues untill it finds a null \0
  for (pos = str; *pos != '\0'; pos++)
    {
      S_Push(&stack, *pos);
    }

  printf("\nPopped characters are: ");

  while (!S_Empty(&stack))
    {
      printf("%c", S_POP(&stack));
    }

  printf("\n");

  S_Destroy(&stack);

  return 0;
}
