section .text
	
global _start
global read
global write
global open
global close
global strlen

extern main
_start:
	call	main
	mov eax,esp
	add eax,4
	push eax
	push[esp+4]
        mov ebx,eax
	mov eax,1
	int 0x80


read:
	mov eax,3
	mov ebx , [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80 ;sys call
	ret
write:
 	mov eax,4
	mov ebx , [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80 ;sys call
	ret
open:
	mov eax,5
	mov ebx , [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80 ;sys call
	ret
close:
	mov eax,6
	mov ebx , [esp+4]
	mov ecx, [esp+8]
	mov edx, [esp+12]
	int 0x80 ;sys call
	ret
strlen:
	ret
