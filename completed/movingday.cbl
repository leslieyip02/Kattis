       IDENTIFICATION DIVISION.
       PROGRAM-ID. BROKENCALCULATOR.
       
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 INPUT-LINE               PIC X(50).
       01 N                        PIC 9(3).
       01 V                        PIC 9(18).
       01 L                        PIC 9(18).
       01 W                        PIC 9(18).
       01 H                        PIC 9(18).
       01 V0                       PIC 9(18).
       01 VI                       PIC 9(18).
       01 D                        PIC S9(18).
       01 DP                       PIC 9(2).
       01 RESULT                   PIC X(18).

       PROCEDURE DIVISION.
           ACCEPT INPUT-LINE.
           UNSTRING INPUT-LINE DELIMITED BY SPACE INTO N, V.

           MOVE 0 TO V0.
           PERFORM VOLUME N TIMES.

           SUBTRACT V FROM V0 GIVING D.
           COMPUTE DP = FUNCTION LOG10 (FUNCTION ABS(D)).

           MOVE D TO RESULT.
           IF D < 0 THEN
               DISPLAY "-" WITH NO ADVANCING
           END-IF
           DISPLAY RESULT(18 - DP : DP + 1)
       STOP RUN.

       VOLUME.
           ACCEPT INPUT-LINE.
           UNSTRING INPUT-LINE DELIMITED BY SPACE INTO L, W, H.

           COMPUTE VI = L * W * H.
           IF VI > V0 THEN
               MOVE VI TO V0
           END-IF.
