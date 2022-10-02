       IDENTIFICATION DIVISION.
       PROGRAM-ID. FROMATOB.
       
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 INPUT-LINE               PIC X(50).
       01 A                        PIC 9(10).
       01 B                        PIC 9(10).
       01 R                        PIC 9(10).
       01 OPS                      PIC 9(10).
       01 RESULT                   PIC Z(9)9.

       PROCEDURE DIVISION.
           ACCEPT INPUT-LINE.
           UNSTRING INPUT-LINE DELIMITED BY SPACE INTO A, B.

           MOVE 0 TO OPS
           IF A > B THEN
               PERFORM UNTIL A <= B
                   DIVIDE A BY 2 GIVING A REMAINDER R
                   
                   IF R = 1 THEN   
                       ADD 1 TO A
                       ADD 1 TO OPS
                   END-IF

                   ADD 1 TO OPS
               END-PERFORM
           END-IF.

           SUBTRACT A FROM B.
           ADD B TO OPS.

           MOVE OPS TO RESULT.
           DISPLAY RESULT.
       STOP RUN.
