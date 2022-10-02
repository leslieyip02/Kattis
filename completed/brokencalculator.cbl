       IDENTIFICATION DIVISION.
       PROGRAM-ID. BROKENCALCULATOR.
       
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 INPUT-LINE               PIC X(50).
       01 N                        PIC 9(4).
       01 A                        PIC S9(18).
       01 B                        PIC S9(18).
       01 C                        PIC S9(18).
       01 P                        PIC S9(18).
       01 DP                       PIC S9(2).
       01 OP                       PIC X(1).
       01 RESULT                   PIC X(18).

       PROCEDURE DIVISION.
           ACCEPT N.
           MOVE 1 TO C.

           PERFORM UNTIL N = 0
               MOVE C TO P

               ACCEPT INPUT-LINE
               UNSTRING INPUT-LINE DELIMITED BY SPACE 
                   INTO A, OP, B

               IF OP = "+" THEN
                   PERFORM ADDITION2
               END-IF
               
               IF OP = "-" THEN
                   PERFORM SUBTRACTION2
               END-IF
               
               IF OP = "*" THEN
                   PERFORM MULTIPLICATION2
               END-IF

               IF OP = "/" THEN
                   PERFORM DIVISON2
               END-IF

               MOVE C TO RESULT
               COMPUTE DP = FUNCTION LOG10 (FUNCTION ABS (C))

               IF C < 0 THEN
                   DISPLAY "-" WITH NO ADVANCING
               END-IF
               DISPLAY RESULT(18 - DP : DP + 1)

               SUBTRACT 1 FROM N
           END-PERFORM.
       STOP RUN.

       ADDITION2.
           ADD A TO B GIVING C.  
           SUBTRACT P FROM C.

       SUBTRACTION2.
           SUBTRACT B FROM A.
           MULTIPLY A BY P GIVING C.

       MULTIPLICATION2.
           MULTIPLY A BY B GIVING C.
           MULTIPLY C BY C.

       DIVISON2.
           DIVIDE A BY 2 GIVING C REMAINDER B.
           ADD B TO C.
