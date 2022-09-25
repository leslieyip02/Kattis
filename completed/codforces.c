#include <stdio.h>

int main(void)
{
    int n, k, i, j, d, m;
    scanf("%i %i", &n, &k);

    int y[n];
    for (i = 0; i < n; i++)
    {
        scanf("%i", &y[i]);
    }

    // store distance to next division for each contest throughout y
    int z[n];
    for (i = 0; i < n; i++)
    {
        if (y[i] == k)
        {
            z[i] = -1;
            continue;
        }

        d = 1;
        while (y[(i + d) % n] != y[i] + 1)
            d++;
        z[i] = d;
    }

    m = __INT_MAX__;
    for (i = 0; i < n; i++)
    {
        if (y[i] == 1)
        {
            d = 1; 
            j = i;
            
            do
            {
                d += z[j];
                j = (j + z[j]) % n;
            }
            while (y[j] != k);

            m = d < m ? d : m;
        }
    }

    printf("%i\n", m);

    return 0;
}

/*

https://github.com/Kodsport/swedish-olympiad-2019/tree/master/final/kodkraft

We observe that once Nicolas has started competing, 
there is no purpose in not participating in a competition 
that he can participate in, and we can therefore without 
limitation assume that he is always participating in the 
next competition that he can participate in.

With that observation in mind, for each event i we 
calculate when the next event n_i for division x_i + 1 is,
where x_i is the division competing in event i. This is 
the next event that Nicolas will participate in after 
participating in event  i. To calculate n_i, we can first 
calculate when the first competition of the year is for 
each division. We then go through all the competitions 
backwards (ie we start with the last competition of the year)
and keep track of when the next competition is in each division.
At the same time, we calculate n_i using the snapshot of what 
the next competition is in each division that we have when 
we reach competition i.

Once we have calculated n_i for all i, we can use dynamic 
programming to calculate for each competition i how long 
Nicolas must have competed on Kodkraft to be able to 
participate in and win competition i. Let t_i be the number 
of competitions Nicolas must have participated in at least 
in order to win competition i. Note that with Nicola's strategy
of never opting out of a race he can enter, there may be races 
he can never enter regardless of what time of year he starts 
competing, for example if there are two races in a row for 
Division 2 so Nicolas will never be in the latter of them. 
In such cases, t_i = \infty.

We now go through all the divisions in order from division 1
to division K , and calculate t_i for all competitions in one
division at a time. To be able to do that, we first need to 
create lists of which competitions are in each division, but 
that's easy to do in linear time. For all competitions i in 
division 1, we set t_i=1 because Nicolas does not need to have 
participated in any other competition before.

To calculate t_i for all competitions in division 2, we first 
set t_i to \infty for all competitions in that division. Next, 
we go through all competitions j in division 1 and set t_{n_j}=\min\{t_{n_j}, 
t_j+\texttt{diff}(j,n_j)\}, where \texttt{ diff}(a,b) is the number of 
races between a (exclusive) and b (inclusive), which can be calculated, 
for example, by \texttt{diff}(a,b)=(b-a+N)\% N.

After we calculate t_i for all competitions in division 2, we 
calculate t_i for all competitions in division 3 using the values ​​we
calculated for division 2, and we continue in this way until we calculate
t_i for all competitions in division K. Finally, we find the minimum of t_i 
for all competitions i in division K and print it as our answer!

The complexity of the algorithm is O(N), which is fast enough for N = 10^6.

For partial points, the problem could also be solved with slower time complexity, e.g. O(N^2) or O(N^3).
O(N^2) can be achieved, for example, by finding the next competition after i that Nicolas will participate in by looping and checking competitions i+1, i+2, \dots until one arrives at one in the next division.
Since these loops can take a long time (up to O(N)), an extra factor N is added to the time complexity.

*/