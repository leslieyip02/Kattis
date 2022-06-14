#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 2d array to hold 1 problem for each letter
    // index 0 is whether the answer is correct
    // index 1 is the time take to solve
    // index 2 is the number of incorrect attempts
    int problems[26][3] = { 0 };
    int score = 0, solved = 0;
    int time;

    for (int i = 0; i < 100; i++)
    {
        // max length: 300 A right
        char line[12];
        gets(line);

        // index 0 is time
        // index 1 is the problem letter
        // index 2 is the result
        char *input[3];
        char *token = strtok(line, " ");
        for (int j = 0; j < 3; j++)
        {
            input[j] = token;
            token = strtok(NULL, " ");
        }

        int time = atoi(input[0]);
        if (time == - 1) { break; }

        int index = (int) *input[1] - 65;
        if (problems[index][0] == 0)
        {
            problems[index][1] = time;
            if (strcmp(input[2], "right") == 0)
            {
                problems[index][0] = 1;
                score += problems[index][1] + problems[index][2] * 20;
                solved++;
            }
            else
            {
                problems[index][2] += 1;
            }
        }
    }

    printf("%i %i\n", solved, score);
    return 0;
}