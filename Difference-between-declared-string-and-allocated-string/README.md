今天對下面的code,有個疑問, 就是用string陣列,
跟用pointer去接東西,要印出來,  為什麼用指標,就不行,
一定要malloc, 那用一些陣列的方式跟 malloc有什麼不同,
一個是stack一個是heap

1.	大小  stack 小,heap大
2.	生命週期跟回收,  heap要自己回收
#include <stdio.h>

int main()
{
    printf("Hello, World!\n");
    
    char string[256];
    const char *test2="fsdfsfas";
     char *test=malloc(256);
    printf("test2 = %s!\n",test2);
    
    
    scanf( "%s" , string );
    printf("Hello, World%s!\n",string);
    
    scanf( "%s" , test );
    printf("Hello, World%s!\n",test);
    return 0;
}

Difference between declared string and allocated string
http://stackoverflow.com/questions/16021454/difference-between-declared-string-and-allocated-string

為什麼, string 宣告的區塊是read-only

Difference between declaration and malloc

http://stackoverflow.com/questions/10575544/difference-between-declaration-and-malloc


Linker , Loader , object file 

https://en.wikipedia.org/wiki/Data_segment


https://en.wikipedia.org/wiki/Linker_(computing)

https://en.wikipedia.org/wiki/Loader_(computing)

最上面的問題，是變數存放到不同的地方　stack heap，

有不同的意思跟狀況，　無原無故就接到，程式怎麼放到memory中去執行，

執行前就扯到怎麼編，會用到complier linker loader,

Complier跟linker都是程式，complier是把程式變成object file,

Linker是把這些object file當成原料，　變成執行檔或是其它的library，

Loader 則是ＯＳ的一部份，它是負責把這些執行檔跟library放到memory中，

放到memory中，要能正常的執行，　我想就要看Linker做了什麼事，

理應該是linker有把相關的，放到memory中的offset等資訊給訂好，

我覺得Loader只是看著那些資訊做事，放到memory後，　才能正常運作。

Metadata: 原來就只是像引索data而己，　方便你找其它資料，

Const vs static：突然有個想法，　不同的宣告，　只是把你放到不同屬性的記憶體區塊而己，
　　　　　　　　　
　　　　　　　Static 跟 const是不一樣的，一個針對生命週期，一個是把資料變成read only


