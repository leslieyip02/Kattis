#include <stdio.h>
#include <math.h>

int main(void)
{
    // read input
    int n;
    scanf("%i", &n);

    // dimensions of A1 (landscape)
    double verticalEdge = pow(2, -0.75);
    double horizontalEdge = pow(2, -1.25) * 2;

    // account for perimeter of A1 paper
    double tape = -(horizontalEdge + verticalEdge) * 2;
    // number of pieces of the current size needed to make up 1 x A1
    long needed = 1;
    for (int i = 0; i < n - 1; i++)
    {
        // since the area of each piece of paper halves, the amount required doubles
        needed *= 2;
        // number of A(i + 2) size papers available
        int pieces;
        scanf("%i", &pieces);

        // only halve the longer edge as the other edge remains the same as size shrinks
        if (i % 2 == 0)
        {
            horizontalEdge /= 2;
        }
        else
        {
            verticalEdge /= 2;
        }

        double perimeter = (horizontalEdge + verticalEdge) * 2;

        // subtract as much area as possible from required number 
        // add the entire perimeter of the paper to the tape total
        // to account for tape on all 4 sides of the paper
        if (needed < pieces)
        {
            tape += perimeter * needed;
            needed -= pieces;
            break;
        }
        else
        {
            tape += perimeter * pieces;
            needed -= pieces;
        }
    }

    if (needed > 0)
    {
        printf("impossible");
    }
    else
    {
        // divide tape total in half since the tape on the 4 edges of
        // each piece of paper overlap with adjacent pieces
        printf("%f", tape / 2);
    }

    return 0;
}