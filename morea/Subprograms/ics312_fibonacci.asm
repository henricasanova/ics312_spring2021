; This simple program takes 10 integers from the user and
; counts how many of these integers are odd

%include "asm_io.inc"

segment .data
	msg1		db	"Enter n: ", 0
	msg2		db	"The result is: ", 0

segment .text
	global	asm_main
asm_main:
	enter	   0,0			; set up
	pusha				; set up

	mov		eax, msg1	; eax = address of msg1
	call		print_string	; print msg1
	call		read_int	; get an integer from the keyboard (in EAX)
	push		eax		; put the integer on the stack (parameter #1)
	call		f		; call recursive_sum
	pop		ebx		; remove the parameter from the stack
	mov		ebx, eax	; save the value returned by recursive_sum
	mov		eax, msg2	; eax = address of msg2
	call		print_string	; print msg2
	mov		eax, ebx	; eax = sum
	call		print_int	; print the sum
	call		print_nl	; print a new line

	popa				; clean up
	mov	   eax, 0		; clean up
	leave				; clean up
	ret				; clean up

;   	FUNCTION: f
; 	Takes one parameter:  an integer
; 	eax = return value
segment .data
	debug1	db	"Function f called with integer: ",0
segment .text
f:	enter  8,0		; num in [ebp+8], local var x in [ebp-4], local var sum in [ebp-8]
	push	ebx		; save ebx
	push 	ecx		; save ecx
	push  	edx		; save edx

	mov	eax, [ebp+8]	; eax = num
 	sub	eax, 2		; eax -= 2
	jns	next		; if not <0, goto next
 	add	eax, 2		; eax += 2
	jmp	end
next:
	mov	eax, [ebp+8]	; eax = num
	add	eax, -1		; eax -= 1
	push	eax		; put (num -1) on the stack
	call	f		; call f (recursively)
	add	esp, 4		; remove (num-1) from the stack
	mov	[ebp-4], eax	; put the returned value in x
	mov	eax, [ebp+8]	; eax = num
	add	eax, -2		; eax -= 2
	push	eax		; put (num -2) on the stack
	call	f		; call f (recursively), the return value is in eax
	add	esp, 4		; remove (num-1) from the stack
	add	eax, [ebp-4]	; eax += x

end:
	pop	edx		; restore ebx
	pop 	ecx		; restore ecx
	pop  	ebx		; restore edx
	leave			; clean up the stack
	ret			; return


