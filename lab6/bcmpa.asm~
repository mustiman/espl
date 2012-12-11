
section .data

  romode db "r",0

section .text
	
	global main
	extern fopen
	extern old_main2
	
main:
	push ebp
	mov ebp,esp
	sub esp,12
	
	mov ebx,[ebp+12]		; ebx = argv[1]
	mov ebx,[ebx+4]
	
	push romode
	push ebx
	call fopen
	add esp, 8

	push eax	; mov [ebp-4],eax		;[ebp-4] = *fp1 

	mov ebx,[ebp+12]
	mov ebx,[ebx+8]			;ecx = argv[2] 

	push romode
	push ebx
	call fopen
	add esp, 8

	push eax

	call old_main2
	
	mov WORD[sep-4],0

	mov esp,ebp
	pop ebp
	ret