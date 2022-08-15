; Type in a decimal integer in [0, 65535].
; Output it's hexadecimal form.

; Special Define:
; R0 as the IO register
; 
; R2 as the undefined tmp register.
; R3 as the undefined tmp register.
; R4 as the undefined tmp register.
; R5 as the output hexadecimal number Stack Pointer.
; R6 as the Stack Pointer.
; R7 as the PC tmp

; Process Codes Head & Init
            .ORIG   x3000
            AND     R2, R2, #0      ; R2 <- 0.
            AND     R3, R3, #0      ; R3 <- 0.
            LEA     R5, tmpN_H      ; Set oSP for hexadecimal.
            LEA     R6, STACK       ; Set SP for calculation.
        
; Read the Inpout Data and transform it from ASCII to decimal      (ignore most problems)
; R2 act as the tmp register of input decimal result here.
; R3 act as the tmp register of total input decimal result here.
RDIN        TRAP    x20             ; Read in one char on screen.
            TRAP    x21             ; Print the input.
            STR     R0, R6, #0      ; Store the char read in. It also pass arguments to function AtoD.
            JSR     incSP           ; Increase SP after store. 
            ADD     R0, R0, #-10    ; Reach end? (ASCII = 10)
            ; Branch here           ;
            BRz     endRDIN         ; If zero, means equal, than exit.
            ; ASCII 2 decimal       ; 
            JSR     AtoD            ; Calculate decimal here.
            JSR     decSP           ; Find return result.
            LDR     R2, R6, #0      ; Load return result.
            ; Add to R2             ;
            STR     R3, R6, #0      ; Pass arguments to function MulTen.
            JSR     incSP           ; Increase SP after store.
            JSR     MulTen          ;
            JSR     decSP           ; Find return result.
            LDR     R3, R6, #0      ; Load return result.
            ADD     R3, R3, R2      ; Add input number to total.
                                    ;
            JSR     RDIN            ; Continue readin.
            ; Exit of Loop:
endRDIN     ST      R3, tmpN_D      ; Store the decimal of input.

; Transform the decimal stored in tmpN_D into hexadecimal and store it to SC_Os.
            LD      R2, tmpN_D      ; Load the decimal of input.
DtoH        AND     R3, R2, x000f   ; R3 <- R2 mod 16.
            STR     R3, R5, #0      ; Push R3 into output Stack
            JSR     incoSP          ; Increase oSP after store.
            STR     R2, R6, #0      ; Pass arguments to fucntion RShift
            JSR     incSP           ; Increase SP after store.
            JSR     RShift16        ;
            JSR     decSP           ; Find return result.
            LDR     R2, R6, #0      ; Load the return result.
            BRz     endDtoH         ; If zero, than exit.
            JSR     DtoH            ; Continue to transform.
endDtoH     LEA     R5, tmpN_H      ; Reset oSP for hexadecimal.

; Output the things in output Stack one by one.
            JSR     ENDL            ; Print '\n' before output.
            LDR     R2, R5, #3      ; ___*
            JSR     OUTPUT          ;
            LDR     R2, R5, #2      ; __*_
            JSR     OUTPUT          ;
            LDR     R2, R5, #1      ; _*__
            JSR     OUTPUT          ;
            LDR     R2, R5, #0      ; *___
            JSR     OUTPUT          ;

; Process Codes Tail
EXIT        TRAP    x25
        
; ============================================================================

; Function Defination
OUTPUT      STR     R7, R6, #0      ; Save R7.
            STR     R2, R6, #1      ; Pass arguments to function HtoA
            JSR     incSP           ; Increase oSP after store.
            JSR     incSP           ; Increase oSP after store.
            JSR     HtoA            ;
            JSR     decSP           ; Find return result.
            JSR     decSP           ; Find return result.
            LDR     R0, R6, #1      ; Load the return result.
            TRAP    x21             ; Output.
            LDR     R7, R6, #0      ; Recover R7.
            RET
; (Special) Stack Methods:
incSP       ADD     R6, R6, #1      ; SP <- SP+1.
            RET
decSP       ADD     R6, R6, #-1     ; SP <- SP-1.
            RET
; (Special) Output Stack Methods:
incoSP      ADD     R5, R5, #1      ; oSP <- oSP+1.
            RET
decoSP      ADD     R5, R5, #-1     ; oSP <- oSP-1.
            RET
; Utils Methods:
ENDL        STR     R2, R6, #0      ; Callee Save.
            AND	    R2, R2, #0      ; R2 <- 0.
            ADD     R2, R2, #10     ; R2 <- 10.
            TRAP    x21
            LDR     R2, R6, #0      ; Callee Recover.
            RET
; Shift Options
RShift      STR     R7, R6, #2      ; Save R7.
            STR     R2, R6, #1      ; Callee Save.
            STR     R3, R6, #0      ; Callee Save.
            JSR     decSP           ; Find arguments.
            LDR     R2, R6, #0      ; Load the arguments.
            AND     R3, R3, #0      ; R3 <- 0
            ADD     R3, R3, x0001   ;
            NOT     R3, R3          ; Set mask
            AND     R2, R2, R3      ; Make it even.
            NOT     R2, R2          ;
            ADD     R2, R2, #1      ; R2 <- (-R2)
            STR     R2, R6, #0      ; Save the edited arguments.
            AND     R3, R3, #0      ; R3 <- 0.
FdHALF      ADD     R2, R2, R3      ; 
            ADD     R2, R2, R3      ; R2 <- R2 + 2*R3
            BRz     endFdHALF       ; If zero, means R3 = R2 >> 1, than exit
            LDR     R2, R6, #0      ; Reset R2.
            ADD     R3, R3, #1      ; Increase R3.
            JSR     FdHALF          ; Continue to find half.
endFdHALF   STR     R3, R6, #0      ; Update the result.
            JSR     incSP           ; Find Saved arguments.
            LDR     R3, R6, #0      ; Callee Recover.
            LDR     R2, R6, #1      ; Callee Recover.
            LDR     R7, R6, #2      ; Recover R7.
            RET
; Shift Options
RShift16    STR     R7, R6, #3      ; Save R7.
            STR     R2, R6, #2      ; Callee Save.
            STR     R3, R6, #1      ; Callee Save.
            STR     R4, R6, #0      ; Callee Save.
            JSR     decSP           ; Find arguments.
            LDR     R2, R6, #0      ; Load the arguments.
            AND     R3, R3, #0      ; R3 <- 0
            ADD     R3, R3, x000f   ;
            NOT     R3, R3          ; Set mask
            AND     R2, R2, R3      ; Make it even16.
            NOT     R2, R2          ;
            ADD     R2, R2, #1      ; R2 <- (-R2)
            STR     R2, R6, #0      ; Save the edited arguments.
            AND     R3, R3, #0      ; R3 <- 0.
FdHALF16    ADD     R4, R3, R3      ; R4 <- 2*R3
            ADD     R4, R4, R4      ; R4 <- 4*R3
            ADD     R4, R4, R4      ; R4 <- 8*R3
            ADD     R4, R4, R4      ; R4 <- 16*R3
            ADD     R2, R2, R4      ; R2 <- R2 + 16*R3
            BRz     endFdHALF16     ; If zero, means R3 = R2 >> 4, than exit
            LDR     R2, R6, #0      ; Reset R2.
            ADD     R3, R3, #1      ; Increase R3.
            JSR     FdHALF16        ; Continue to find half16.
endFdHALF16 STR     R3, R6, #0      ; Update the result.
            JSR     incSP           ; Find Saved arguments.
            LDR     R4, R6, #1      ; Callee Recover.
            LDR     R3, R6, #1      ; Callee Recover.
            LDR     R2, R6, #2      ; Callee Recover.
            LDR     R7, R6, #3      ; Recover R7.
            RET

; Multiply 10 to the number stored in SP-1.
MulTen      STR     R7, R6, #2      ; Save R7.
            STR     R2, R6, #1      ; Callee Save.
            STR     R3, R6, #0      ; Callee Save.
            JSR     decSP           ; Find arguments.
            LDR     R2, R6, #0      ; LD the arguments.
            LDR     R3, R6, #0      ; LD the arguments.
                                    ;
            ADD     R2, R2, R2      ; R2 = 2x
            ADD     R3, R2, R2      ; R3 = 4x
            ADD     R3, R3, R3      ; R3 = 8x
            ADD     R2, R2, R3      ; R2 = 10x
                                    ;
            STR     R2, R6, #0      ; Update the result.
            JSR     incSP           ; Find Saved arguments.
            LDR     R3, R6, #0      ; Callee Recover.
            LDR     R2, R6, #1      ; Callee Recover.
            LDR     R7, R6, #2      ; Recover R7.
            RET

; Transform an ASCII char stored in SP-1 to a decimal number.
AtoD        STR     R7, R6, #1      ; Save R7.
            STR     R2, R6, #0      ; Callee Save.
            JSR     decSP           ; Find arguments.
            LDR     R2, R6, #0      ; LD the arguments.
                                    ;
            ADD     R2, R2, x-f     ; Calculate Decimal.
            ADD     R2, R2, x-f     ; Calculate Decimal.
            ADD     R2, R2, x-f     ; Calculate Decimal.
            ADD     R2, R2, x-3     ; Calculate Decimal.
                                    ;        
            STR     R2, R6, #0      ; Update the result.
            JSR     incSP           ; Find Saved arguments.
            LDR     R2, R6, #0      ; Callee Recover.
            LDR     R7, R6, #1      ; Recover R7.
            RET
; Transform a hexadecimal stored in SP-1 to an ASCII.
HtoA        STR     R7, R6, #2      ; Save R7.
            STR     R2, R6, #1      ; Callee Save.
            STR     R3, R6, #0      ; Callee Save.
            JSR     decSP           ; Find arguments.
            LDR     R2, R6, #0      ; LD the arguments.
                                    ;
            ADD     R3, R2, #-10    ; 
            BRn     isNUMBER        ; If negative, the number will be displayed as arabic numerals.
            ADD     R2, R2, xf      ; to A,B,C...
            ADD     R2, R2, xf      ; to A,B,C...
            ADD     R2, R2, xf      ; to A,B,C...
            ADD     R2, R2, xa      ; to A,B,C...
            JSR     conHtoA         ;
isNUMBER    ADD     R2, R2, xf      ; to 1,2,3...
            ADD     R2, R2, xf      ; to 1,2,3...
            ADD     R2, R2, xf      ; to 1,2,3...
            ADD     R2, R2, x3      ; to 1,2,3...
                                    ;
conHtoA     STR     R2, R6, #0      ; Update the result.
            JSR     incSP           ; Find Saved arguments.
            LDR     R3, R6, #0      ; Callee Recover.
            LDR     R2, R6, #1      ; Callee Recover.
            LDR     R7, R6, #2      ; Recover R7.
            RET
; Data Storage
tmpN_D      .FILL   #0              ; Decimal of the input.
tmpN_H      .BLKW   #4              ; Hexadecimal of the input, one word for one digit.
STACK       .BLKW   1024
TST         .FILL   xffff
            .END