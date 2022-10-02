       IDENTIFICATION DIVISION.
       PROGRAM-ID. DEATHANDTAXES.
       
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 INPUT-LINE               PIC X(50).
           88 EOF VALUE SPACES.
       
       01 OPTION                   PIC X(5).
       01 COUNTER                  PIC 9(1).
       
       01 TOTAL-SHARES             PIC 9(16).
       01 TOTAL-VALUE              PIC S9(16)V9(8).

       01 NUM-SHARES               PIC 9(16).
       01 SHARE-COST               PIC 9(16)V9(8).
       01 AVG-COST                 PIC 9(16)V9(8).
       01 PROFIT                   PIC S9(16)V9(8).

       PROCEDURE DIVISION.
           PERFORM FOREVER
               ACCEPT INPUT-LINE
                 
               IF EOF THEN
                   EXIT PERFORM
               END-IF
          
               MOVE 0 TO COUNTER
               INSPECT INPUT-LINE TALLYING COUNTER FOR ALL "buy"
               IF COUNTER = 1 THEN
                   UNSTRING INPUT-LINE DELIMITED BY SPACE
                       INTO OPTION, NUM-SHARES, SHARE-COST
                   PERFORM BUY-SHARES
               END-IF
          
               MOVE 0 TO COUNTER
               INSPECT INPUT-LINE TALLYING COUNTER FOR ALL "sell"
               IF COUNTER = 1 THEN
                   UNSTRING INPUT-LINE DELIMITED BY SPACE
                       INTO OPTION, NUM-SHARES, SHARE-COST
                   PERFORM SELL-SHARES
               END-IF

               MOVE 0 TO COUNTER
               INSPECT INPUT-LINE TALLYING COUNTER FOR ALL "split"
               IF COUNTER = 1 THEN
                   UNSTRING INPUT-LINE DELIMITED BY SPACE
                       INTO OPTION, NUM-SHARES
                   PERFORM SPLIT-SHARES
               END-IF

               MOVE 0 TO COUNTER
               INSPECT INPUT-LINE TALLYING COUNTER FOR ALL "merge"
               IF COUNTER = 1 THEN
                   UNSTRING INPUT-LINE DELIMITED BY SPACE
                       INTO OPTION, NUM-SHARES
                   PERFORM MERGE-SHARES
               END-IF
               
               MOVE 0 TO COUNTER
               INSPECT INPUT-LINE TALLYING COUNTER FOR ALL "die"
               IF COUNTER = 1 THEN
                   UNSTRING INPUT-LINE DELIMITED BY SPACE
                       INTO OPTION, SHARE-COST
                   PERFORM DIE
               END-IF
           END-PERFORM.
       STOP RUN.

       BUY-SHARES.
           ADD NUM-SHARES TO TOTAL-SHARES.
           MULTIPLY NUM-SHARES BY SHARE-COST.
           ADD SHARE-COST TO TOTAL-VALUE.
           DIVIDE TOTAL-VALUE BY TOTAL-SHARES 
               GIVING AVG-COST.

       SELL-SHARES.
           SUBTRACT NUM-SHARES FROM TOTAL-SHARES.
           MULTIPLY TOTAL-SHARES BY AVG-COST 
               GIVING TOTAL-VALUE.

       SPLIT-SHARES.
           MULTIPLY NUM-SHARES BY TOTAL-SHARES.
           DIVIDE NUM-SHARES INTO AVG-COST.

       MERGE-SHARES.
           MULTIPLY NUM-SHARES BY AVG-COST.
           DIVIDE NUM-SHARES INTO TOTAL-SHARES.
           MULTIPLY TOTAL-SHARES BY AVG-COST 
               GIVING TOTAL-VALUE.

       DIE.
           SUBTRACT AVG-COST FROM SHARE-COST 
               GIVING PROFIT.
           
           IF PROFIT IS POSITIVE THEN
               MULTIPLY 0.3 BY PROFIT
               SUBTRACT PROFIT FROM SHARE-COST
           END-IF.

           MULTIPLY TOTAL-SHARES BY SHARE-COST 
               GIVING TOTAL-VALUE.
           DISPLAY TOTAL-VALUE.
