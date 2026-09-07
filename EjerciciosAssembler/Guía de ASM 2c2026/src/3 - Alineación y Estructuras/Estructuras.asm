

;########### ESTOS SON LOS OFFSETS Y TAMAÑO DE LOS STRUCTS
; Completar las definiciones (serán revisadas por ABI enforcer):
NODO_OFFSET_NEXT EQU 0
NODO_OFFSET_CATEGORIA EQU 8
NODO_OFFSET_ARREGLO EQU 16
NODO_OFFSET_LONGITUD EQU 24
NODO_SIZE EQU 32
PACKED_NODO_OFFSET_NEXT EQU 0
PACKED_NODO_OFFSET_CATEGORIA EQU 8
PACKED_NODO_OFFSET_ARREGLO EQU 9
PACKED_NODO_OFFSET_LONGITUD EQU 17
PACKED_NODO_SIZE EQU 21
LISTA_OFFSET_HEAD EQU 0
LISTA_SIZE EQU 8
PACKED_LISTA_OFFSET_HEAD EQU 0
PACKED_LISTA_SIZE EQU 8

;########### SECCION DE DATOS
section .data

;########### SECCION DE TEXTO (PROGRAMA)
section .text

;########### LISTA DE FUNCIONES EXPORTADAS
global cantidad_total_de_elementos
global cantidad_total_de_elementos_packed

;########### DEFINICION DE FUNCIONES
;extern uint32_t cantidad_total_de_elementos(lista_t* lista);
;registros: lista(puntero)-> RDI  

cantidad_total_de_elementos:
	push RBP 
	MOV RBP, RSP 
	
	xor RAX, RAX 

	;RDI APUNTA A a la lista 
	 MOV RDI, qword[RDI+ LISTA_OFFSET_HEAD]
	 ;ahora apunta al nodo
	.ciclo:
		
		CMP RDI, 0 
		JE .epilogo

		;ojo a la hora de sumar registros de 32 bits con registros de 64, conviene hacer el pasaje primero
		MOV R8D, dword [RDI + NODO_OFFSET_LONGITUD]  
		ADD RAX, R8



		MOV RDI, qword [RDI+ NODO_OFFSET_NEXT] ;como el primer elemento del nodo es next* entonces basta con desreferenciarse a si mismo
		JMP .ciclo 


	.epilogo: 
		pop RBP 
		ret

;extern uint32_t cantidad_total_de_elementos_packed(packed_lista_t* lista);
;registros: lista->RDI
cantidad_total_de_elementos_packed:
	.prologo: 
	push rbp 
	mov rbp, rsp 
	xor rax, rax ;siempre hay que limpiar rax??????
	.nudo: 

	mov rdi, qword [rdi]   ;ahora rdi apunta a head* 

	.ciclo:

	cmp rdi, 0 
	JE .epilogo 

	mov r8d, dword [rdi+ PACKED_NODO_OFFSET_LONGITUD]
	add rax, r8

	mov rdi, qword[rdi+ NODO_OFFSET_NEXT] 
	JMP .ciclo

	.epilogo: 

	pop rbp 
	ret

