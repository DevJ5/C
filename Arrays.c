#include <stdio.h>
#include <cs50.h>

// 	Pointer to an array
// You can generate a pointer to the first element of an array by simply specifying the array name, without any index.

const int COUNT = 3;

void printChart(int count, int scores[]);

int main(void)
{
    int scores[COUNT];
    for (int i = 0; i < COUNT; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }

    printChart(COUNT, scores);
}

void printChart(int count, int scores[])
{
    for (int i = 0; i < count; i++)
    {
        printf("Score %i: ", i + 1);
        for (int j = 0; j < scores[i]; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
