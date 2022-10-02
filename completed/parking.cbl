       IDENTIFICATION DIVISION.
       PROGRAM-ID. PARKING.
       
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 INPUT-LINE               PIC X(50).
       01 A                        PIC 9(3).
       01 B                        PIC 9(3).
       01 C                        PIC 9(3).
       01 X                        PIC 9(3).
       01 Y                        PIC 9(3).
       01 T                        PIC 9(5).
       01 RESULT                   PIC Z(5).
       
       01 INTERVALS.
           05 INTERVAL PIC 9(1) VALUE 0 OCCURS 100 TIMES INDEXED BY I.

       PROCEDURE DIVISION.
           ACCEPT INPUT-LINE.
           UNSTRING INPUT-LINE DELIMITED BY SPACE INTO A, B, C.

           MULTIPLY 2 BY B;
           MULTIPLY 3 BY C;

           PERFORM PARK 3 TIMES.

           MOVE 0 TO T.
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 100
               IF INTERVAL(I) = 1 THEN
                   ADD A TO T
               END-IF

               IF INTERVAL(I) = 2 THEN
                   ADD B TO T
               END-IF

               IF INTERVAL(I) = 3 THEN
                   ADD C TO T
               END-IF
           END-PERFORM.

           MOVE T TO RESULT.
           DISPLAY RESULT.
       STOP RUN.

       PARK.
           ACCEPT INPUT-LINE.
           UNSTRING INPUT-LINE DELIMITED BY SPACE INTO X, Y.
           PERFORM VARYING I FROM X BY 1 UNTIL I = Y
               ADD 1 TO INTERVAL(I)
           END-PERFORM.
