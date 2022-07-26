## Algorithm explanation

- First I will add two new trap instructions into the vector table. (Actually only one should be there only.)

  - `DELAY` and `INTERACT`, refer to let the process wait for some time and get a input from keyboard (It will still return although if there is no input, and it will simply return with the R0 = 0).
-  Then a function named `PRINT_FRAM` is defined to draw a frame in a line.
-  Also, a function named `BIRD_DROP` is defined to update the position of the bird each timestamp.
-  After getting the return value of the `INTERACT`, I will check if it is a number or an alphabet, and deal with them according to the requirement.



- As for the interrupt version, just put the `INTERACT` 's address into the `x0180`, and remove the `Trap` instruction in the main code. And things else are quite likely.

## Essential parts of your code with sufficient comments

 ```assembly
 ; Using Trap
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
                 ADD     R3, R3, R0      ;
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
 ```

```assembly
; Using Interrupt
INIT            LEA     R6, STACK       ; Set SP.
                LD      R1, D_SHAPE
                LD      R2, D_POS
                AND     R5, R5, #0
                
NEXT_FRAM       JSR     PRINT_FRAM      ;
                JSR     BIRD_DROP       ;
                TRAP    x00             ; Delay
                ADD     R4, R5, #0      ; Save.
                AND     R5, R5, #0      ; Reset R5
                ADD     R4, R4, #0      ; Set CC.
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
```



## Questions TA asked you and your answer in Check