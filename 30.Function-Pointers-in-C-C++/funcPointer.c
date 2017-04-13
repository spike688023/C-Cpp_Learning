#include <stdio.h>
#include <string.h>

struct commands
{
  int (*fptr) ();
  int key;
};
typedef struct commands commands;


int do_a(void), do_b(void), do_c(void);


int do_a()      // do_b() do_c() 類似....
{
 printf("你按了 a 這個鍵\n");
   return 0;
}


int do_b()      // do_b() do_c() 類似....
{
 printf("你按了 b 這個鍵\n");
   return 0;
}


int do_c()      // do_b() do_c() 類似....
{
 printf("你按了 c 這個鍵\n");
   return 0;
}

int main()
{
  int key;
  char ch;

  commands commandlist[] =
  {
      do_a,       'a',
      do_b,       'b',
      do_c,       'c',
      NULL,       '\0'
    };
  commands *commandPtr;
  //printf( "Enter a value :");
  while ( ( ch = getchar() ) != EOF )
  {

      //ch = getch();
      //printf("你按了 %c 這個鍵\n", ch);
    //printf( "Enter a value :");
    //ch = getchar();
    //printf( "Enter a value :");
    //scanf("Enter a value :%c", &ch);

      //if (ch == 'q')
      //  break;

      commandPtr = commandlist;
      for (; key = commandPtr->key; commandPtr++){
        if (ch == key)
        {
                commandPtr->fptr();
                break;
        }
      }
  }

  return 0;

}
