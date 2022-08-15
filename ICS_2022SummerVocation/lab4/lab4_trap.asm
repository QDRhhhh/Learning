; ===================================================================
; Modify the vector table.
                .ORIG   x0000
TARP_DELAY      .FILL   x2000
TRAP_INTERACT   .FILL   x2100
                .END
; ===================================================================
; Edit the trap instruction's body.
; DELAY -------------------------------------------------------------
                .ORIG   x2000           ;
                ADD     R6, R6, #-1     ; Callee save.
                STR     R1, R6, #0      ; Callee save.
                ADD     R6, R6, #-1     ; Callee save.
                STR     R7, R6, #0      ; Callee save.
                                        ;
                LD      R1, DELAY_TIME  ;
LOOP            ADD     R1, R1, #-1     ;
                BRnp    LOOP            ;
                                        ;
                LDR     R7, R6, #0      ; Callee recover.
                ADD     R6, R6, #1      ; Callee recover.
                LDR     R1, R6, #0      ; Callee recover.
                ADD     R6, R6, #1      ; Callee recover.
                RTI
DELAY_TIME      .FILL   x2000
                .END
; INTERACT ----------------------------------------------------------
                .ORIG   x2100           ;
                LDI     R0, KBSR        ; Read KB status
                BRzp    LEAVE           ;
                LDI     R0, KBDR        ; Read KB data
LEAVE           RTI                     ;
KBSR            .FILL   xFE00           ;
KBDR            .FILL   xFE02           ;
                .END                    ;
; ===================================================================
; Main code.

; R0 act as special register for I/O
; R1 act as the shape of the bird (a-z)
; R2 act as the position of the bird (1~18)
; R3 act as tmp register 
; R4 act as tmp register 

; R6 as the Stack Pointer.
; R7 as the PC tmp

                .ORIG   x3000
; BODY --------------------------------------------------------------
INIT            LEA     R6, STACK       ; Set SP.
                LD      R1, D_SHAPE
                LD      R2, D_POS
                
NEXT_FRAM       JSR     PRINT_FRAM      ;
                JSR     BIRD_DROP       ;
                TRAP    x00             ; Delay
                TRAP    x01             ; Interact
                ADD     R4, R0, #0      ; Set CC.
                BRz     NEXT_FRAM       ; No input.
                LD      R3, OFFSET_AaN  ;
                ADD     R3, R3, R4      ;
                BRn     IS_NUMBER       ;
IS_ALPHABET     ADD     R1, R4, #0      ; Change shape.
                BRnzp   NEXT_FRAM       ;
IS_NUMBER       LD      R3, OFFSET_N    ;
                ADD     R3, R3, R4      ;
                ADD     R2, R2, R3      ;
                LD      R3, OFFSET_MaxP ;
                ADD     R3, R3, R2      ;
                BRnz    NEXT_FRAM       ;
                LD      R2, MAX_POS     ;
                BRnzp   NEXT_FRAM       ;
                HALT
; FUNC --------------------------------------------------------------

; (Special) Stack Methods:
incSP           ADD     R6, R6, #1      ; SP <- SP+1.
                RET
decSP           ADD     R6, R6, #-1     ; SP <- SP-1.
                RET
; Print a fram like '......aaa...........'
PRINT_FRAM      STR     R7, R6, #2      ; Save R7
                STR     R3, R6, #1      ; Callee save
                STR     R4, R6, #0      ; Callee save
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                                        ;
                ADD     R3, R2, #0      ; Get number of the previous dot.
LOOP_PRE        ADD     R3, R3, #-1     ; Print the '.' before bird.
                BRz     LOOP_PRE_EXIT   ;
                LD      R0, CH_DOT      ;
                OUT                     ;
                BRnzp   LOOP_PRE        ;
LOOP_PRE_EXIT   LD      R3, BIRD_SIZE   ;
LOOP_MID        ADD     R3, R3, #-1     ;
                BRn     LOOP_MID_EXIT   ;
                ADD     R0, R1, #0      ;
                OUT                     ;
                BRnzp   LOOP_MID        ;
LOOP_MID_EXIT   LD      R3, LINE_SIZE   ;
                ADD     R4, R2, #2      ;
                NOT     R4, R4          ;
                ADD     R4, R4, #1      ; R4 = -(pos+2)
                ADD     R3, R3, R4      ;
LOOP_SUF        ADD     R3, R3, #-1     ; Print the '.' after bird.
                BRn     LOOP_SUF_EXIT   ;
                LD      R0, CH_DOT      ;
                OUT                     ;
                BRnzp   LOOP_SUF        ;
                                        ;
LOOP_SUF_EXIT   LD      R0, CH_LF       ;
                OUT                     ;
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                LDR     R4, R6, #0      ; Callee recover
                LDR     R3, R6, #1      ; Callee recover
                LDR     R7, R6, #2      ; Recover R7
                RET
; Bird will drop a pixel each timestamp.
BIRD_DROP       STR     R7, R6, #1      ; Save R7
                STR     R3, R6, #0      ; Callee save
                JSR     incSP           ;
                                        ;
                ADD     R2, R2, #-1     ;
                BRp     BIRD_DROP_EXIT  ;
                ADD     R2, R2, #1      ; Recover if it touch the ground.
                                        ;
BIRD_DROP_EXIT  JSR     decSP           ;
                LDR     R3, R6, #0      ; Callee recover
                LDR     R7, R6, #1      ; Recover R7
                RET


; DATA --------------------------------------------------------------
D_SHAPE         .FILL   x0061
D_POS           .FILL   #1
MAX_POS         .FILL   #18
OFFSET_N        .FILL   #-48
OFFSET_AaN      .FILL   #-90
OFFSET_MaxP     .FILL   #-18
CH_LF           .FILL   x000A
CH_DOT          .FILL   x002E
BIRD_SIZE       .FILL   #3
LINE_SIZE       .FILL   #20
STACK           .BLKW   x0100
                .END
; ===================================================================



