       IDENTIFICATION DIVISION.
       PROGRAM-ID. POPULARVOTE.
       
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 CASES                    PIC 9(3).
       01 CANDIDATES               PIC 9(2).
       01 COUNTER                  PIC 9(2).
       01 VOTES                    PIC 9(5).
       01 WINNER                   PIC 9(2).
       01 TIED                     PIC 9(1).
       01 MOST-VOTES               PIC S9(5).
       01 TOTAL-VOTES              PIC 9(6).
       01 RATIO                    PIC 9(3)V9(8).

       01 I                        PIC 9(1).
       01 J                        PIC 9(1).
       01 RESULT                   PIC X(2).

       PROCEDURE DIVISION.
           ACCEPT CASES.
           PERFORM COUNT-VOTES UNTIL CASES = 0.
       STOP RUN.

       COUNT-VOTES.
           MOVE -1 TO MOST-VOTES.
           MOVE 0 TO TOTAL-VOTES.
           MOVE 0 TO TIED.
           MOVE 1 TO COUNTER.

           ACCEPT CANDIDATES.
           PERFORM UNTIL COUNTER > CANDIDATES
               ACCEPT VOTES

               IF VOTES = MOST-VOTES then 
                   MOVE 1 TO TIED
               END-IF

               IF VOTES > MOST-VOTES THEN
                   MOVE COUNTER TO WINNER
                   MOVE VOTES TO MOST-VOTES
                   MOVE 0 TO TIED
               END-IF

               ADD VOTES TO TOTAL-VOTES
               ADD 1 TO COUNTER
           END-PERFORM.

           IF TIED EQUALS 0 THEN
               DIVIDE MOST-VOTES BY TOTAL-VOTES
                   GIVING RATIO

               MOVE WINNER TO RESULT
               
               IF WINNER > 9 THEN
                   MOVE 1 TO I
                   MOVE 2 TO J
               ELSE
                   MOVE 2 TO I
                   MOVE 1 TO J
               END-IF

               IF RATIO > 0.5 THEN
                   DISPLAY "majority winner ", RESULT(I:J)
               ELSE
                   DISPLAY "minority winner ", RESULT(I:J)
               END-IF
           END-IF.

           IF TIED EQUALS 1 THEN
               DISPLAY "no winner"
           END-IF.

           SUBTRACT 1 FROM CASES.
