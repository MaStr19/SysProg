SECTION .data

str:	db `Hello world!\n`
strlen:	equ $ - str

num:	dq 1337

numbuffer: times 20 db 0
bufferlen: equ $ - numbuffer

endl: db `\n`           
endllen: equ $ - endl

SECTION .text

global _start

_start:
    ; Hello World 

	mov rax, 1                          ;   Erster Syscall Parameter
	mov rdi, 1                          ;   Zweiter Syscall Parameter
	mov rsi, str                        ;   Dritter Syscall Parameter (Hello World\n)
	mov rdx, strlen                     ;   Vierter Syscall Parameter (Die Länger des Buffers)
	syscall                             ;   Syscall Aufruf

    ; Zahl in String umwandeln


    mov rax, [num]                      ;   untere hälfte mit der Nummer auffüllen
    mov rcx, 10                         ;   Divisor in ein Register laden
    mov rdi, numbuffer + bufferlen      ;   Zeiger vom Ende des Buffers wird in rdi gespeichert

.loop:
    mov rdx, 0                          ;   obere register mit 0 auffüllen
    div rcx                             ;   mit 10 dividieren -> Rest in rdx
    add dl, '0'                         ;   mit '0' (48) addieren um die richtige ASCII Nummer zu erhalten
    dec rdi                             ;   den Pointer von rdi um ein byte decrementieren
    mov [rdi], dl                       ;   den Wert aus rdx im Buffer zwischenspeichern
    cmp rax, 0                          ;   testen ob Zahl fertig ist -> Zero Flag enthät die Infos
    jne .loop                           ;   wiederholt die division falls Zero Flag noch 0 ist -> Quotient ist dann nicht 0


    ; Zahl ausgeben

    mov rax, 1                          ;   Erster Syscall Parameter
	mov rdi, 1                          ;   Zweiter Syscall Parameter
	mov rsi, numbuffer                  ;   Dritter Syscall Parameter (Die Zahl die ausgegeben werden soll)
	mov rdx, bufferlen                  ;   Vierter Syscall Parameter (Die Länger des Buffers)
	syscall                             ;   Syscall Aufruf

    ; Endline ausgeben

    mov rax, 1                          ;   Erster Syscall Parameter
	mov rdi, 1                          ;   Zweiter Syscall Parameter
	mov rsi, endl                       ;   Dritter Syscall Parameter (Das Endline Zeichen)
	mov rdx, endllen                    ;   Vierter Syscall Parameter (Die Länger des Buffers)
	syscall                             ;   Syscall Aufruf

    ; Programm beenden

	mov rax, 60                         ;   Erster Syscall Parameter
	mov rdi, 0                          ;   Zweiter Syscall Parameter
	syscall