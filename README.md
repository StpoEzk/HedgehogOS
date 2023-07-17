<p align="center">
<img src=https://github.com/StpoEzk/HedgehogOS/assets/40798676/86e7b988-17aa-4b56-b49e-92a6621f3c42" width="40%"/>
</p>

<p align="center">
<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white">
<img src="https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white">
<img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white">
</p>

<hr/>

__HedgehogOS__ is a Simple Open Source __Operating System__ under the __GPL__ license, written in __C__ language and Assembler(__NASM__). The purpose of the development is to understand the operating system device at a low level.

<hr/>

### Currently implemented:
1. Launch in long(__64bit__) mode
2. Simple CLI shell working through VGA text mode
3. The beginning for realization of PAE paging support
4. Small part of __libc__ implementation

<hr/>

## Other
If you want to start the project, you will need create a bootable device and use it on a 64-bit computer, or load iso in qemu64 _(you can use script)_.

If you want to build the project or, god forbid, work with it, you will need a cross-compiler, which you can either build yourself _(https://wiki.osdev.org/GCC_Cross_Compiler)_ or take an already built one _(https://mirrors.edge.kernel.org/pub/tools/crosstool/)_, and run command make.
