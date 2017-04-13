
question6.c

這個例子,是在講二者的差別,

#define的概念是替換

typedef則是 別名 

用以增加可讀性,如下:

typedef int Apple;
typedef int Orange;
Apple coxes;
Orange jaffa;

處理它們的也不一樣:
#define is a preprocessor token: the compiler itself will never see it.
typedef is a compiler token: the preprocessor does not care about it.

還有一個差別是在這個例子裡:

charPtr_d 會被取代成 char*

使的　char *x,y;

也就是　x 才是指標，y 不是。

而charPtr_t 就不一樣了，它是把a b這二個變數，

都看成是指向char的指標。

所以這題的輸出，會是8 8 8 1。
