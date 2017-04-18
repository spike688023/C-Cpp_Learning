1. What is Cross compilation ?
   Cross compilation是一個compile的動作，

　 多寫一個cross，代表說，當前操作的環境，跟目標要compile，

　 的東西，架構不一樣，像是用 windows環境，要編一個arm的binary出來，

　 這種動作就是cross compilation.

   Practical example :- A compiler that runs on a Windows-10 PC but generates code that runs on Android smart-phone is a process of cross compilation

   Building RISC binaries on a CISC CPU platform,
   OR 64-bit binaries on a 32-bit system.
   OR Building firmware intended to run on embedded devices 
   (perhaps using the ARM CPU architecture) on Intel PC-based OSs.

2. Difference between Native and Cross compiler ?

   Native compiler: 就是自己環境編的東西，只能自己用。

   A cross-compiler is one that compiles binaries for architectures other than its own.
 
   A “cross compiler” executes in one environment and generates code for another. A “native compiler” generates code for its own execution environment.


3. Why we use cross compilation:
   
   這裡舉了一個例子，像是raspberry pie which have 900 MHz frequency and less ram size.

   就效能不好　記憶也不大的裝置，編一些小東西給自己用還好，但是如果要編的source code很大，

　 又或者有緊急的需求，就馬上篇出來，那就只能用別台做了。


4. What is Tool-chain ?

   A Tool-chain is the set of compiler + linker + librarian + any other tools you need to produce the executable (+ shared libraries, etc) for the target.

   A debugger and/or IDE may also count as part of a Tool-chain.

5. Why we require ARM Tool-chain ?

   Tool-chain plays very important role in embedded system development.

   For example:- If you want to run your C program on your ARM based smart-phone, then you have to cross compile your C program and you need ARM compiler, linker, library, etc. In short you need tool-chain.

6. How to operate?

   我看例子是，把要的tool chain先下載下來，把gcc所在的位置放到環境變數中，

　 但gcc的名字，會改，但compile的動作，我想是大同小異，

　 最後還有提到個東西qemu,用這個能先跑起來看看，感覺有點像模擬器。

   I want to see it on my system before running on the target system.

7. Let’s understanding tool-chain.

   GCC is a popular, open source tool-chain that can generate code for a wide range of architectures including Intel’s x86, ARM v4/5/6/7, TI’s MSP, Atmel’s AVR, and many others.

   Note: when the host and target architectures are different, the tool-chain is also called a cross compiler.

8. Tool chain naming rule?

   [arch] – [vendor] – [os] – [abi]


9. What is ABI ? 
 
   跟API很像。

   Each architecture or architecture/os couple has an ABI. The ABI (Application binary Interface) describes how functions should be called, syscalls numbers, arguments passed, which registers can be used …

10. What is ELF?
   
   EABI stands for Embedded ABI, which is the definition of the Application Binary Interface for certain targets (e.g. PPC). ELF is the Executable and Linking Format which defines the ELF file format.









Reference: http://www.firmcodes.com/how-to-cross-compile-for-arm/


