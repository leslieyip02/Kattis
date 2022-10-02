       IDENTIFICATION DIVISION.
       PROGRAM-ID. TRACKINGSHARES.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 C                        PIC 9(2).
       01 K                        PIC 9(2).
       01 N                        PIC 9(4).
       01 D                        PIC 9(3).
       01 I                        PIC 9(3).
       01 J                        PIC 9(3).
       01 INPUT-LINE               PIC X(50).
       01 COMPANY-INDEX            PIC 9(2).
       01 RECORDED                 PIC 9(1).
       01 DAY-SUM                  PIC 9(8).
       01 RESULT                   PIC Z(8).

       01 SHARES.
           05 COMPANY-SHARES OCCURS 1 TO 20 TIMES DEPENDING ON C.
               10 SHARE-RECORD PIC 9(8) VALUE 0 OCCURS 365 TIMES.

       01 COMPANIES.
           05 HELD PIC 9(8) VALUE 0 OCCURS 1 TO 20 TIMES DEPENDING ON C.

       PROCEDURE DIVISION.
           ACCEPT C.
           
           MOVE 1 TO COMPANY-INDEX.
           PERFORM ADD-ENTRY UNTIL COMPANY-INDEX > C.

           PERFORM PRINT-RESULT VARYING J FROM 1 BY 1 UNTIL J > 365.
       STOP RUN.

       ADD-ENTRY.
           ACCEPT K.
           PERFORM UNTIL K = 0
               ACCEPT INPUT-LINE
               UNSTRING INPUT-LINE DELIMITED BY SPACE INTO N, D
               MOVE N TO SHARE-RECORD(COMPANY-INDEX, D)

               SUBTRACT 1 FROM K
           END-PERFORM.

           ADD 1 TO COMPANY-INDEX.

       PRINT-RESULT.   
           MOVE 0 TO RECORDED.

           PERFORM VARYING I FROM 1 BY 1 UNTIL I > C
               IF SHARE-RECORD(I, J) > 0 THEN
                   MOVE 1 TO RECORDED
                   MOVE SHARE-RECORD(I, J) TO HELD(I)
               END-IF
           END-PERFORM.

           IF RECORDED = 1 THEN
               MOVE 0 TO DAY-SUM
               PERFORM VARYING I FROM 1 BY 1 UNTIL I > C 
                   ADD HELD(I) TO DAY-SUM
               END-PERFORM

               MOVE DAY-SUM TO RESULT

               DISPLAY RESULT, " " WITH NO ADVANCING 
           END-IF.
