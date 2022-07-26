; Special define
; R0 as the params value passer
; R1 as tmp reg 
; R2 as tmp reg 
; R3 as tmp reg 
; R4 as as choosen chapter mask
; R5 as pages iterator and tmp reg
; R6 as SP
; R7 as PC tmp
; ============================================================
                .ORIG   x3000
Init            LD      R6, StackAdd    ;

RdInN           JSR     Input           ;
                ST      R0, PageN       ;
                LD      R1, PageN       ;
                LD      R2, MasksAdd    ;
                LD      R5, PagesInfoAdd;
RdPagesInfo     ADD     R1, R1, #-1     ; loop
                BRn     ExitRdPagesInfo ; loop exit
                LD      R0, MaskAllIn   ;   \
                LDR     R3, R2, #0      ;   |
                ADD     R0, R0, R3      ;   | Do something to initialize the mask all in.
                ST      R0, MaskAllIn   ;   |
                ADD     R2, R2, #1      ;   /
                JSR     Input           ; Read first chapter
                STR     R0, R5 #0       ;
                JSR     Input           ; Read second chapter
                STR     R0, R5, #1      ;
                ADD     R5, R5, #3      ; The tird is left for chosen.
                BRnzp   RdPagesInfo     ;
ExitRdPagesInfo LD      R0, PageN       ;
                JSR     dfs             ;
                
SolutionFound   LD      R2, PagesInfoAdd;
                LD      R1, PageN       ;
PrtChoosenPages ADD     R1, R1, #-1     ; loop
                BRn     Exit            ; loop exit
                LDR     R0, R2, #2      ;
                LDR     R0, R0, #0      ;
                JSR     PrintNumber     ;
                ADD     R2, R2, #3      ;
                BRnzp   PrtChoosenPages ;

Exit            HALT                    ;
; ------------------------------------------------------------
; Functions
; (special) for Stack ----------------------------------------
incSP           ADD     R6, R6, #1      ;
                RET 
decSP           ADD     R6, R6, #-1     ;
                RET
; OR ---------------------------------------------------------
; Read a and b from SP-1, SP-2 and put a|b at SP-2
OR              STR     R7, R6, #3      ;
                STR     R1, R6, #2      ;
                STR     R2, R6, #1      ;
                STR     R3, R6, #0      ;
                LDR     R1, R6, #-1     ;
                LDR     R2, R6, #-2     ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                NOT     R1, R1          ;
                AND     R3, R1, R2      ;
                NOT     R1, R1          ;
                ADD     R3, R3, R1      ;
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                STR     R3, R6, #-2     ;
                LDR     R3, R6, #0      ;
                LDR     R2, R6, #1      ;
                LDR     R1, R6, #2      ;
                LDR     R7, R6, #3      ;
                RET

; printNumber() ----------------------------------------------
; number to ASCII and print
PrintNumber     STR     R7, R6, #2      ;
                STR     R1, R6, #1      ;
                STR     R2, R6, #0      ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                ADD     R2, R0, #-10    ;
                BRn     NotHaveTen      ;
                LD      R0, OffsetASCII ;
                ADD     R0, R0, #1      ;
                OUT                     ;
                ADD     R0, R2, #0      ;
NotHaveTen      LD      R1, OffsetASCII ;
                ADD     R0, R0, R1      ;
                OUT                     ;
                LD      R0, ASCIISpace  ;
                OUT                     ;
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                LDR     R2, R6, #0      ;
                LDR     R1, R6, #1      ;
                LDR     R7, R6, #2      ;
                RET
                
; dfs() ------------------------------------------------------
; find the solution
dfs             STR     R7, R6, #4      ;
                STR     R1, R6, #3      ;
                STR     R2, R6, #2      ;
                STR     R3, R6, #1      ;
                STR     R0, R6, #0      ; Params value.
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                ADD     R0, R0, #-1     ; Next params value.
                BRn     dfsExit         ; Recursion exit.
                JSR     incSP           ; For chosenMask.
                LD      R3, PagesInfoAdd;
                ADD     R3, R3, R0      ; Actually it should be R5 + R0 - 1, but I did R0-1 already.
                ADD     R3, R3, R0      ; Actually it should be R5 + R0 - 1, but I did R0-1 already. (twice)
                ADD     R3, R3, R0      ; Actually it should be R5 + R0 - 1, but I did R0-1 already. (trible)
                LDR     R1, R3, #0      ; First chapter.
                STR     R3, R3, #2      ; Choose First chapter.
                LD      R2, MasksAdd    ;
                ADD     R2, R2, R1      ;
                LDR     R2, R2, #-1     ; -1 referred to offset
                STR     R2, R6, #0      ; pass arguement
                LD      R2, MaskChosen  ;
                STR     R2, R6, #-1     ; Tmp.
                STR     R2, R6, #1      ; pass arguement
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     OR              ;
                JSR     decSP           ;
                JSR     decSP           ;
                LDR     R2, R6, #0      ;
                ST      R2, MaskChosen  ;
                JSR     dfs             ; First dfs
                LDR     R1, R6, #-1     ;
                ST      R1, MaskChosen  ;
                ADD     R3, R3, #1      ; Move iterator.
                LDR     R1, R3, #0      ; Second chapter.
                STR     R3, R3, #1      ; Choose Second chapter.
                LD      R2, MasksAdd    ;
                ADD     R2, R2, R1      ;
                LDR     R2, R2, #-1     ; -1 referred to offset
                STR     R2, R6, #0      ; pass arguement
                LD      R2, MaskChosen  ;
                STR     R2, R6, #1      ; pass arguement
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     OR              ;
                JSR     decSP           ;
                JSR     decSP           ;
                LDR     R2, R6, #0      ;
                ST      R2, MaskChosen  ;
                JSR     dfs             ; Second dfs
                JSR     decSP           ; For chosen mask.
                LDR     R1, R6, #0      ; recover
                ST      R1, MaskChosen  ;
                
dfsExit         JSR     CheckIsOK       ; Check whether it fits requirements.
                ADD     R0, R0, #0      ; Set cc.
                BRp     SolutionFound   ; 
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                LDR     R0, R6, #0      ;
                LDR     R3, R6, #1      ;
                LDR     R2, R6, #2      ;
                LDR     R1, R6, #3      ;
                LDR     R7, R6, #4      ;
                RET


CheckIsOK       STR     R7, R6, #3      ;
                STR     R1, R6, #2      ;
                STR     R2, R6, #1      ;
                STR     R3, R6, #0      ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                LD      R1, MaskChosen  ;
                LD      R2, MaskAllIn   ;
                AND     R0, R0, #0      ;
                NOT     R1, R1          ;
                ADD     R1, R1, #1      ;
                ADD     R1, R1, R2      ; R1 = R2 - R1
                BRz     IsOK            ;
                BRnzp   IsNotOK         ;
IsOK            ADD     R0, R0, #1      ;
                BRnzp   IsNotOK         ;
IsNotOK         JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                LDR     R3, R6, #0      ;
                LDR     R2, R6, #1      ;
                LDR     R1, R6, #2      ;
                LDR     R7, R6, #3      ;
                RET

; Input() ----------------------------------------------------
; read a number ended with '\n' or ' ' and return the value through R0.
Input           STR     R7, R6, #2      ;
                STR     R1, R6, #1      ;
                STR     R2, R6, #0      ;
                JSR     incSP           ;
                JSR     incSP           ;
                JSR     incSP           ;
                AND     R1, R1, #0      ;
RdAscii         GETC                    ;
                OUT                     ;
                ADD     R2, R0, #-10    ;
                BRz     FinishRdAscii   ; Meet '\n'
                ADD     R2, R0, #-16    ;
                ADD     R2, R2, #-16    ;
                BRz     FinishRdAscii   ; Meet ' '
                ADD     R2, R1, R1      ; R2 = 2*x
                ADD     R1, R2, R2      ; R1 = 4*x
                ADD     R1, R1, R1      ; R1 = 8*x
                ADD     R1, R1, R2      ; R1 = 10*x
                ADD     R2, R0, #-16    ; Ascii to Number
                ADD     R2, R2, #-16    ; Ascii to Number
                ADD     R2, R2, #-16    ; Ascii to Number
                ADD     R1, R1, R2      ; R1 = 10*x + y
                BRnzp   RdAscii         ;
FinishRdAscii   ADD     R0, R1, #0      ; Store into R0
                JSR     decSP           ;
                JSR     decSP           ;
                JSR     decSP           ;
                LDR     R2, R6, #0      ;
                LDR     R1, R6, #1      ;
                LDR     R7, R6, #2      ;
                RET
                
                
; ============================================================
; Data part
OffsetASCII     .FILL   #48 
ASCIISpace      .FILL   #32 
PageN           .FIll   #0
PagesInfoAdd    .FILL   x4000
MasksAdd        .FILL   x4040
MaskAllIn       .FILL   #0
MaskChosen      .FILL   #0
StackAdd        .FILL   x4100
                .END
; Data part 2 
                .ORIG   x4000
PagesInfo       .BLKW   #48                
                .END 
                .ORIG   x4040
Masks           .FILL   #1
                .FILL   #2
                .FILL   #4
                .FILL   #8
                .FILL   #16
                .FILL   #32
                .FILL   #64
                .FILL   #128
                .FILL   #256
                .FILL   #512
                .FILL   #1024
                .FILL   #2048
                .FILL   #4096
                .FILL   #8192
                .FILL   #16384
                .FILL   #32768
                .END 
                .ORIG   x4100
STACK           .BLKW   #1024
                .END