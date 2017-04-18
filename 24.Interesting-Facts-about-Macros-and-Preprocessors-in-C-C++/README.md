http://www.firmcodes.com/interesting-facts-macros-preprocessors-cc/

#include, 只做一件事,
就是把後面的檔案放進來,這個檔案內, 
差別只有<> , "" 這二種, 

前者是到環境變數的預設路徑去找, 後者是在此檔案的路徑去找.

#include
When we use #include directive, the contents of included header file (after preprocessing) are copied to the current file.




Macro expansion
The macro arguments are not evaluated before macro expansion. For example consider the following program.

1
2
3
4
5
6
7
8
9
10
11	#include <stdio.h>
 
#define MULTIPLY(a, b) a*b
 
int main()
{
    // The macro is expended as 2 + 3 * 3 + 5, not as 5*8
    printf("%d", MULTIPLY(2+3, 3+5));
    return 0;
}
// Output: 16
這裡是指, Macro function, 不會對傳入的變數 先做運算, 只會做擴展, 所以輸出會是16

Macro concatenation
The tokens passed to macros can be concatenated using operator ## called Token-Pasting operator.

1
2
3
4
5
6
7
8
9	#include <stdio.h>
 
#define merge(a, b) a##b
 
int main()
{
    printf("%d ", merge(12, 34));
}
// Output: 1234
 
這裡單純的說, ##是串運的符號而己, 要注意的是, 它是integer



Macro strings
A token passed to macro can be converted to a sting literal by using # before it.

1
2
3
4
5
6
7
8
9	#include <stdio.h>
 
#define get(a) #a
 
int main()
{
    printf("%s", get(firmcodes));
}
// Output: firmcodes

這裡就是字元.

Multiline Macros
The macros can be written in multiple lines using ‘\’. The last line doesn’t need to have ‘\’.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15	#include <stdio.h>
 
#define PRINT(i, limit) while (i < limit) \
                        { \
                            printf("firmcodes"); \
                            i++; \
                        }
 
int main()
{
    int i = 0;
    PRINT(i, 3);
    return 0;
}
// Output: firmcodes  firmcodes firmcodes

這裡只是說, 可以寫多行, 但換行, 要加\ 符號.

Macro Argument Problems
The macros with arguments should be avoided as they cause problems sometimes. And Inline functions should be preferred as there is type checking parameter evaluation in inline functions. From C99 onward, inline functions are supported by C language also. For example consider the following program. From first look the output seems to be 1, but it produces 36 as output.

1
2
3
4
5
6
7
8
9	#define square(x) x*x
 
int main()
{
  int x = 36/square(6); // Expended as 36/6*6
  printf("%d", x);
  return 0;
}
// Output: 36
 這裡就是之前說的, 它會先擴展, 所以 加減乘除中, 乘除是同等的處理順序, 

會被先除6再乘6, 所以值是36.


If we use inline functions, we get the expected output. Also the program given above can be corrected using inline functions.

1
2
3
4
5
6
7
8
9	inline int square(int x) { return x*x; }
 
int main()
{
  int x = 36/square(6);
  printf("%d", x);
  return 0;
}
// Output: 1

這裡要看的, 裡應是, inline function, 但inline function跟一班function有什麼差,

一般function是會放到stack再去做運算, 這裡inline, 理應該在complier時, 

就會先把值給算出來, 進而在memory layout時, 放到data section.

這裡放個inline function的優缺點來看:

The C++ inline function provides an alternative. With inline code, the compiler replaces the function call statement with the function code itself (this process is called expansion) and then compiles the entire code. Thus, with this the compiler doesn't have to do the long, time consuming process.

Advantage of Inline Functions : They save on overheads of a function call as it's not invoked, rather its code is replaced in the program.

Disadvantage of Inline Functions : With more function calls (for ex: in a loop), the repeated occurrences of same function code wastes memory space.



下面這一大塊, 我最不理解的就是  #if-else ??

我做了個實驗, 我知道, 

我在 test2 中, 把VERBOSE 的值設成大於2
      Test3 中, 設成小於2

可以看出, test2的size比較大, 因為夾在中間的printf有被放到 text section.

這裡我可以對Macro 下個結論, 它想把, 能在build time就先處理的東西, 

先處理好, 而結省後面的時間.

android@mec3:~$ gcc test2.c -o test2
android@mec3:~$ gcc test3.c -o test3
android@mec3:~$ size test2
   text    data     bss     dec     hex filename
   1375     504      16    1895     767 test2
android@mec3:~$ size test3
   text    data     bss     dec     hex filename
   1345     504      16    1865     749 test3
#if-else
Preprocessors also support if-else directives which are typically used for conditional compilation.

1
2
3
4
5
6
7
8	int main()
{
#if VERBOSE >= 2
 
    printf("Trace Message");
 
#endif
}
 
 #ifndef
A header file may be included more than one time directly or indirectly, this leads to problems of redeclaration of same variables/functions. To avoid this problem, directives like defined, ifdef and ifndef are used.

1
2
3
4
5
6
7
8	#ifndef __HEADERFILE_H
 
#define __HEADERFILE_H
 
//Do some coding stuff here
 
#endif
//This will check for if HEADERFILE.h not defined, then define HEADERFILE, and then do some coding stuff
 
Some standard MACROS
There are some standard macros which can be used to print program file (__FILE__), Date of compilation (__DATE__), Time of compilation (__TIME__) and Line Number in C code (__LINE__).

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16	#include <stdio.h>

int main()
{
   printf("Current File :%s\n", __FILE__ );
   printf("Current Date :%s\n", __DATE__ );
   printf("Current Time :%s\n", __TIME__ );
   printf("Line Number :%d\n", __LINE__ );
   return 0;
}

/* Output:
Current File :C:\Users\GfG\Downloads\deleteBST.c
Current Date :Feb 15 2014
Current Time :07:04:25
Line Number :8 */
 

這篇唸完, 我了解整個c program的架構,到 編成一個執行檔, 其執行檔的架構 section.

接下來, 要了解的, 可能是 function call , 以及 recursive 要怎麼在stack中運作.



