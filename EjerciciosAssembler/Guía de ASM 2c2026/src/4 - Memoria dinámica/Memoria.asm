extern malloc
extern free
extern fprintf

section .data

	formato db "%s",0
	nada db "NULL",0
section .text

global strCmp
global strClone
global strDelete
global strPrint
global strLen

; ** String **

; int32_t strCmp(char* a, char* b)

;a*-> RDI 
;b*-> RSI
strCmp:

	.prologo: 
	push RBP 
	mov RBP, RSP 


	ciclo:

	MOV R8B, byte [RDI] ;R8B tiene el caracter de a
	MOV R9B, byte [RSI]; R9B tiene el caracter de b 

	;primero me fijo si los strings empataron totalmente, para ello ambos punteros deben apuntar al \0 
	MOV DL, R8B 
	ADD DL, R9B  
	cmp DL, 0 ; si DL es cero es porque RBB Y R9D son cero 
	JE .soniguales 

	CMP R8B, R9B 
	JA .AmayorQueB
	JB .BMayorQueA 

	INC RDI 
	INC RSI 
	JMP ciclo

	.AmayorQueB:

	mov EAX, -1 
	JMP .epilogo


	.BMayorQueA:

	mov eax, 1 
	JMP .epilogo

	.soniguales:

	mov EAX, 0 

	.epilogo: 
	pop RBP

	ret

; char* strClone(char* a)   
;RDI-> string a 
strClone:

	.prologo:
		PUSH RBP  
		MOV RBP, RSP 
		push R12 ;la pila se desalinea!!! tiene que ser mul de 16
		sub RSP, 8
		MOV R12, RDI ; r12-> PUNTERO ORIGINAL

		;primero calculo el tamanio del arreglo 

		call strLen ;en eax tengo el tamanio del string, porque 1 caracter= 1 byte

		push R13 
		sub rsp, 8
		MOV R13, RAX   ;R13 ->tamanio
		INC R13 ;al tamanio le sumamos unos mas, el '\0'
		MOV RDI, R13;
		call malloc ;EN RAX esta el nuevo un nuevo puntero 

		;conviene copiar byte a byte porque el tamanio reservado de malloc no coincide necesariamente con el tamanio del registro

		xor R10, R10  ;R10 = contador 

		.ciclo: 

		CMP R10D, R13D
		JE .epilogo 

		;usamos R11 como registro intermedio
		MOV R11B, byte[R12+R10]   ;usamos los registros de 64 para la address
		MOV byte[RAX+R10], R11B
		INC R10
		JMP .ciclo

	.epilogo: 

	add rsp, 8
	pop R13
	add RSP, 8 ;hay que popear la pila en orden contrario, como hariamos en una pila abstracta
	pop R12  
	pop RBP 
	ret

; void strDelete(char* a)
;RDI-> puntero a 
strDelete:

	.prologo:
	PUSH RBP  
	MOV RBP, RSP 

	call free

	.epilogo: 
	pop RBP 
	ret
	

; void strPrint(char* a, FILE* pFile)
;RDI-> puntero a 
;RSI -> puntero pFile 

strPrint:
	
	.prologo:
	PUSH RBP  
	MOV RBP, RSP 

	xor RAX, RAX ; AL tiene que estar en 0 para usar fprintf 
	
	;si a es un string vacio, tiene que imprimir null 

	MOV R10B, byte [RDI]

	MOV R11, RDI  ;R11-> puntero char 
	MOV RDI, RSI  ;en RDI tiene que estar el puntero al file 

	CMP R10B, 0 
	JE .stringvacio 

	lea RSI, formato 
	MOV RDX, R11
	call fprintf    ;fprintf escribe en el archivo que apunta RDI el texto de RDX con el formato de RSI
	JMP .epilogo

	.stringvacio: 

	LEA RSI, [nada] ; en RSI tiene que estar el puntero al texto 
	call fprintf 

	.epilogo: 
	pop RBP 
	ret

; uint32_t strLen(char* a)
;RDI-> puntero a
strLen:

	.prologo:
	PUSH RBP  
	MOV RBP, RSP 

	xor EAX, EAX; limpio eax

	.ciclo: 

	MOV R10B, byte[RDI]

	CMP R10B, 0 
	JE .epilogo
	
	INC RDI 
	INC EAX 

	JMP .ciclo 

	.epilogo: 
	pop RBP 
	ret


