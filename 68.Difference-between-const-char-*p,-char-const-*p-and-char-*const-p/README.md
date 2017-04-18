
char* p;
const char *p;
const char *const p;

這裡要考的就是const 是鎖那一個人，

鎖char的值，還是pointer的值，

我的想法很簡單，直接看const 離誰最近，當然*不能算。


而作者給了個很簡單的判別如下：

Another thumb rule is to check where const is:

    before *           => Can’t change pointed characters using pointer

    after *              => Can’t change pointer stored address
