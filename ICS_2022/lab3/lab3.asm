; ======================================================================================================
; Simulate a deque operation
; x002B + push_left 
; x002D - pop_left 
; x005B [ push_right 
; x005D ] pop_right 

; Special Define:
; R0 as the IO register and tmp register while not IO
; R1 as undefined tmp register
; R2 as undefined tmp register
; R3 as undefined tmp register
; R4 as the Left Data Stack Pointer
; R5 as the Right Data Stack Pointer
; R6 as the Stack Pointer.
; R7 as the PC tmp
; ======================================================================================================
; Init
            .ORIG   x3000
            LEA     R4, DSTACK_R
            LEA     R5, DSTACK_R
            LD      R6, STACK_ADD
            
            JSR     incSP           ; Keep Safe.
RD_OPT      GETC                    ; Read in
            OUT                     ; Show on Screen
            ADD     R1, R0, x-A    ; if '\n'
            BRz     SHOW_RES        ; Meet '\n'
            STR     R0, R6, #-1     ; Keep Safe.
            BRnzp   ROUTING_OPT     ; Routing the options.

SHOW_RES    LD      R1, OUTPUT_ADD  ; Find the output string's location.
PRINT       ADD     R1, R1, #1      ; Move
            LDR     R0, R1, #0      ; Load ASCII
            BRz     EXIT
            OUT
            BRnzp   PRINT
            
EXIT        HALT
; ======================================================================================================
; Functions Define

; (Special) Stack Methods:
incSP       ADD     R6, R6, #1      ; SP <- SP+1.
            RET
decSP       ADD     R6, R6, #-1     ; SP <- SP-1.
            RET
incLDSP     ADD     R4, R4, #-1      ; LDSP <- LDSP+1.
            RET
decLDSP     ADD     R4, R4, #1     ; LDSP <- LDSP-1.
            RET
incRDSP     ADD     R5, R5, #1      ; RDSP <- RDSP+1.
            RET
decRDSP     ADD     R5, R5, #-1     ; RDSP <- RDSP-1.
            RET

; Routing the options.
ROUTING_OPT STR     R7, R6, #2      ; Save R7.
            STR     R1, R6, #1      ; Callee Save.
            STR     R2, R6, #0      ; Callee Save.
            JSR     incSP           ; 
            JSR     incSP           ; 
            JSR     incSP           ; 
            LDR     R1, R6, #-4     ; Load the arguments.
                                    ;
            ADD     R1, R1, x-10    ;
            ADD     R1, R1, x-10    ; x000? or x 003?
            ADD     R2, R1, x-10    ;
            BRn     RD_L_OPT        ;
            BRzp    RD_R_OPT        ;
RD_L_OPT    AND     R2, R1, #2      ; B: 1011, D: 1101
            BRz     POP_L           ; -
            BRnp    PUSH_L          ; +
RD_R_OPT    AND     R2, R1, #2      ; B: 1011, D: 1101
            BRz     POP_R           ; ]
            BRnp    PUSH_R          ; [
POP_L       NOT     R1, R4          ; -
            ADD     R1, R1, #1      ; R1 = -LDSP
            ADD     R1, R1, R5      ; R1 = RDSP-LDSP
            BRz     POP_EMPTY       ; 
            LDR     R1, R4, #0      ;
            JSR     decLDSP         ;
            STR     R1, R6, #0      ; Pass arguements to CACHE_OUT 
            JSR     incSP           ;
            JSR     CACHE_OUT       ;
            JSR     decSP           ;
            BRnzp   RD_LEAVE        ;
PUSH_L      GETC                    ; +
            OUT                     ;
            JSR     incLDSP         ;
            STR     R0, R4, #0      ;
            BRnzp   RD_LEAVE        ;
POP_R       NOT     R1, R4          ; ]
            ADD     R1, R1, #1      ; R0 = -LDSP
            ADD     R1, R1, R5      ; R0 = RDSP-LDSP
            BRz     POP_EMPTY       ; 
            JSR     decRDSP         ;
            LDR     R1, R5, #0      ;
            STR     R1, R6, #0      ; Pass arguements to CACHE_OUT 
            JSR     incSP           ;
            JSR     CACHE_OUT       ;
            JSR     decSP           ;
            BRnzp   RD_LEAVE        ;
PUSH_R      GETC                    ; [
            OUT                     ;
            STR     R0, R5, #0      ;
            JSR     incRDSP         ;
            BRnzp   RD_LEAVE        ;
POP_EMPTY   LD      R1, EMPTY_SIGN  ; R0 = '_'
            STR     R1, R6, #0      ; Pass arguements to CACHE_OUT 
            JSR     incSP           ;
            JSR     CACHE_OUT       ;
            JSR     decSP           ;
            BRnzp   RD_LEAVE        ;
RD_LEAVE    JSR     decSP           ;
            JSR     decSP           ;
            JSR     decSP           ;
            LDR     R2, R6, #0      ; Callee Recover.
            LDR     R1, R6, #1      ; Callee Recover. 
            LDR     R7, R6, #2      ; Recover R7.
            RET

; Push to output string.
CACHE_OUT   STR     R7, R6, #3      ; Save R7. 
            STR     R1, R6, #2      ; Callee Save.
            STR     R2, R6, #1      ; Callee Save.
            STR     R3, R6, #0      ; Callee Save.
            JSR     incSP           ;
            JSR     incSP           ;
            JSR     incSP           ;
            JSR     incSP           ; 
            LDR     R3, R6, #-5     ; Load the arguments.
                                    ;
            LDI     R1, OUTPUT_ADD  ; Get output cache size
            LD      R2, OUTPUT_ADD  ;
            ADD     R1, R1, #1      ;
            STI     R1, OUTPUT_ADD  ; Update output cache size.
            ADD     R2, R2, R1      ; Get next output cache address.
            STR     R3, R2, #0      ; Finish Cache
                                    ;
            JSR     decSP           ;
            JSR     decSP           ;
            JSR     decSP           ;
            JSR     decSP           ;
            LDR     R3, R6, #0      ; Callee Recover.
            LDR     R2, R6, #1      ; Callee Recover.
            LDR     R1, R6, #2      ; Callee Recover.
            LDR     R7, R6, #3      ; Recover R7.
            RET
            

; ======================================================================================================
; Data Storage
EMPTY_SIGN  .FILL   x005F

STACK_ADD   .FILL   x4000
OUTPUT_ADD  .FILL   x4100

DSTACK_LL   .FILL   xFFFF
DSTACK_L    .BLKW   x0080
DSTACK_R    .BLKW   x0080
DSTACK_RL   .FILL   xFFFF
            .END
; Stack Storage
            .ORIG   x4000
STACK       .BLKW   x0800  
            .END
; Output Storage
            .ORIG   x4100
OUTPUT_SIZE .FILL   #0
OUTPUT      .BLKW   x0100
            .END