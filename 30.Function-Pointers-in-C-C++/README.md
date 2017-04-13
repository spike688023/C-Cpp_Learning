
http://www.firmcodes.com/basics-function-pointers-cc/


Function pointer怎麼讓我覺得,有點像多型的感覺.

因為要使用function pointer的前提, 是它指向的function 參數跟回傳值, 要跟它原本定義的一樣.

我個人最常的使用時機（同時符合才行）： 1. 具有一樣輸入輸出但是動作不同的functions 2. 這些functions有共同的使用時機及規範 便會考慮用function pointer將這些不同的動作封裝起來。

 A function name (label) is converted to a pointer to itself. This means that function names can be used where function pointers are required as input.


Reference:

The function pointer tutorial
http://www.newty.de/fpt/index.html



