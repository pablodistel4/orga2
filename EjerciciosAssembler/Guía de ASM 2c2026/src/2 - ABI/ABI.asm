extern sumar_c
extern restar_c
;########### SECCION DE DATOS
section .data

;########### SECCION DE TEXTO (PROGRAMA)
section .text

;########### LISTA DE FUNCIONES EXPORTADAS

global alternate_sum_4
global alternate_sum_4_using_c
global alternate_sum_4_using_c_alternative
global alternate_sum_8
global product_2_f
global product_9_f

;########### DEFINICION DE FUNCIONES
; uint32_t alternate_sum_4(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4);
; parametros: 
; x1 --> EDI
; x2 --> ESI
; x3 --> EDX
; x4 --> ECX
alternate_sum_4:
  sub EDI, ESI
  add EDI, EDX
  sub EDI, ECX

  mov EAX, EDI
  ret

; uint32_t alternate_sum_4_using_c(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4);
; parametros: 
; x1 --> EDI
; x2 --> ESI
; x3 --> EDX
; x4 --> ECX
alternate_sum_4_using_c:
  ;prologo
  push RBP ;pila alineada
  mov RBP, RSP ;strack frame armado
  push R12
  push R13	; preservo no volatiles, al ser 2 la pila queda alineada

  mov R12D, EDX ; guardo los parámetros x3 y x4 ya que están en registros volátiles
  mov R13D, ECX ; y tienen que sobrevivir al llamado a función

  call restar_c 
  ;recibe los parámetros por EDI y ESI, de acuerdo a la convención, y resulta que ya tenemos los valores en esos registros
  
  mov EDI, EAX ;tomamos el resultado del llamado anterior y lo pasamos como primer parámetro
  mov ESI, R12D
  call sumar_c

  mov EDI, EAX
  mov ESI, R13D
  call restar_c

  ;el resultado final ya está en EAX, así que no hay que hacer más nada

  ;epilogo
  pop R13 ;restauramos los registros no volátiles
  pop R12
  pop RBP ;pila desalineada, RBP restaurado, RSP apuntando a la dirección de retorno
  ret


alternate_sum_4_using_c_alternative:
  ;prologo
  push RBP ;pila alineada
  mov RBP, RSP ;strack frame armado
  sub RSP, 16 ; muevo el tope de la pila 8 bytes para guardar x4, y 8 bytes para que quede alineada

  mov [RBP-8], RCX ; guardo x4 en la pila

  push RDX  ;preservo x3 en la pila, desalineandola
  sub RSP, 8 ;alineo
  call restar_c 
  add RSP, 8 ;restauro tope
  pop RDX ;recupero x3
  
  mov EDI, EAX
  mov ESI, EDX
  call sumar_c

  mov EDI, EAX
  mov ESI, [RBP - 8] ;leo x4 de la pila
  call restar_c

  ;el resultado final ya está en EAX, así que no hay que hacer más nada

  ;epilogo
  add RSP, 16 ;restauro tope de pila
  pop RBP ;pila desalineada, RBP restaurado, RSP apuntando a la dirección de retorno
  ret


; uint32_t alternate_sum_8(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4, uint32_t x5, uint32_t x6, uint32_t x7, uint32_t x8);
; registros y pila: 
;x1->EDI 
;x2-> ESI
;x3-> EDX 
;x4-> ECX
;x5-> R8D
;X6-> R9D
;X7->[RBP+16]
;X7->[RBP+24]
alternate_sum_8:
	;prologo

  push RBP 
  MOV RBP, RSP   ;aunque trabaje con 32 bits, el prologir y el epilogo van en 64 

  ;NUDO 

  MOV EAX, EDI 
  SUB EAX, ESI
  ADD EAX, EDX 
  SUB EAX, ECX 
  ADD EAX, R8D 
  SUB EAX, R9D 
  ADD EAX, DWORD [RBP+16] ;DWORD acalra que lea solo los 32 bits menos significativos
  SUB EAX, DWORD [RBP+24]



	;epilogo
  POP RBP 
	ret


; SUGERENCIA: investigar uso de instrucciones para convertir enteros a floats y viceversa
;void product_2_f(uint32_t * destination, uint32_t x1, float f1);
;registros: 
;destination-> RDI (64 bits obligatorio)
; x1->ESI
; f1-> XMM0 

product_2_f:


product_2_f:
    ; 1. Expandimos tu float (32 bits) a double (64 bits). 
    ; mejoramos precision delfloat pasandolo a double
    cvtss2sd xmm0, xmm0
    
    ; 2. Aseguramos que el entero sea leído como "sin signo" (positivo).
    ; Al copiar ESI a EAX, el procesador limpia de ceros la mitad alta de RAX.

    ; basicamente nos aseguramos de usar el registro de 64 y no el de 32 para que no lo tome como neg,
    ; pasandolo a un registro nuevo, se limpian los 32 bits mas significativos, (en este caso usamos rax)

    mov eax, esi

    
    cvtsi2sd xmm1, rax  ; Convertimos ese entero limpio a double
    
    ; 3. Multiplicamos en precisión doble (mulsd en lugar de mulss)
    mulsd xmm0, xmm1
    
    ; 4. Truncamos el double a entero. Usamos R10 (64 bits) por si el 
    ; resultado de la cuenta es gigantesco y no entra en 32 bits.
    cvttsd2si r10, xmm0
    
    ; 5. Escribimos exactamente 32 bits en el puntero de destino
    mov [rdi], r10d
    
    ret


  ;cvtsi2ss XMM1, ESI
  ;mulss XMM0, XMM1 
  ;cvttss2si R10D, XMM0
  ;MOV [RDI], R10D 
 
  ;cvttss2si R10D, XMM0
  ; ESI, R10D  
  ;MOV [RDI], ESI
	ret


;extern void product_9_f(double * destination
;, uint32_t x1, float f1, uint32_t x2, float f2, uint32_t x3, float f3, uint32_t x4, float f4
;, uint32_t x5, float f5, uint32_t x6, float f6, uint32_t x7, float f7, uint32_t x8, float f8
;, uint32_t x9, float f9);
;registros y pila: destination[rdi], 
;x1-> ESI 
;f1-> XMM0 
;x2-> EDX
;f2-> XMM1
;x3->ECX
;f3->XMM2
;x4-> R8D
;f4->XMM3
;x5->R9D
;f5->XMM4
;x6-> [RBP + 16] ;empezamos desde aca porque RBP+8 tiene al RIP 
;f6-> XMM5
;x7-> [rbp + 24]
;f7-> XMM6
;x8-> [rbp + 32]
;f8-> XMM7
;x9->[RBP+ 40]
;f9->[RBP+48]
product_9_f:
	;prologo
	push rbp
	mov rbp, rsp

	;convertimos los flotantes de cada registro xmm en doubles
	cvtss2sd xmm0, xmm0
  cvtss2sd xmm1, xmm1
  cvtss2sd xmm2, xmm2
  cvtss2sd xmm3, xmm3
  cvtss2sd xmm4, xmm4
  cvtss2sd xmm5, xmm5
  cvtss2sd xmm6, xmm6
  cvtss2sd xmm7, xmm7

  cvtss2sd xmm8, dword [RBP+48] 


 
  

	;multiplicamos los doubles en xmm0 <- xmm0 * xmm1, xmmo * xmm2 , ...
	mulsd XMM0, XMM1
  mulsd XMM0, XMM2
  mulsd XMM0, XMM3
  mulsd XMM0, XMM4
  mulsd XMM0, XMM5
  mulsd XMM0, XMM6
  mulsd XMM0, XMM7
  mulsd XMM0, XMM8


	; convertimos los enteros en doubles y los multiplicamos por xmm0.
  ;los anteriores
 ;siempre antes de pasar uno lo limpiamos usando otro registro 
  mov R10D, ESI
  cvtsi2sd XMM9, R10
  mov R10D, EDX
  cvtsi2sd XMM10, R10
  mov R10D, ECX
  cvtsi2sd XMM11, R10
  mov R10D, R8D
  cvtsi2sd XMM12, R10
  mov R10D, R9D 
  cvtsi2sd XMM13, R10
  mov R10D, dword [RBP + 16]
  cvtsi2sd XMM14, R10
  mov R10D, dword [rbp + 24]
  cvtsi2sd XMM15, R10
  ; hasta aca nos faltan solo x8 y x9 

  mulsd XMM0, XMM9
  mulsd XMM0, XMM10
  mulsd XMM0, XMM11
  mulsd XMM0, XMM12
  mulsd XMM0, XMM13
  mulsd XMM0, XMM14
  mulsd XMM0, XMM15

  ;convertimos los que faltan ahora que ya utilizamos los otros ints 
  mov R10D, dword [RBP+32]
  mov R11D, dword [RBP+ 40]
  cvtsi2sd XMM1, R10
  cvtsi2sd XMM2, R11
  mulsd XMM0, XMM1
  mulsd XMM0, XMM2

  movsd [rdi], XMM0

	; epilogo
	pop rbp
	ret

