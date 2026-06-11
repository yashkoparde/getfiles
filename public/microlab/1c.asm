;ALP for Logical Operations
        AREA    LOGICAL, CODE, READONLY
        ENTRY

        MOV     R0, #0x0000        ; R0 = 0x0000
        MOV     R1, #0x2040        ; R1 = 0x2040
        MOV     R2, #0x007F        ; R2 = 0x007F

        ORR     R0, R1, R2         ; R0 = R1 OR R2

        AND     R3, R1, #0x0F      ; R3 = R1 AND 0x0F

        ANDS    R3, R1, #0x0F      ; R3 = R1 AND 0x0F, updates flags

        EOR     R4, R1, R2         ; R4 = R1 XOR R2

        BIC     R5, R1, R2         ; R5 = R1 AND NOT(R2)

STOP    B       STOP

        END
