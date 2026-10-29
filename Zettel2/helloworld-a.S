SECTION .data

str:	db `Hello world!\n`
strlen:	equ $ - str

num:	dq 1337

SECTION .text

global _start

_start:
	; Hello World 

	mov rax, 1                          ;   Erster Syscall Parameter
	mov rdi, 1                          ;   Zweiter Syscall Parameter
	mov rsi, str                        ;   Dritter Syscall Parameter (Hello World\n)
	mov rdx, strlen                     ;   Vierter Syscall Parameter (Die Länger des Buffers)
	syscall                             ;   Syscall Aufruf

	; Programm beenden

	mov rax, 60                         ;   Erster Syscall Parameter
	mov rdi, 0                          ;   Zweiter Syscall Parameter
	syscall
