#include <stdio.h>

//QuestÃ£o 1
int checarPontos(int d)
{

    if (d <= 800)
    {
        return 1;
    }
    else if (d > 800 && d <= 1400)
    {
        return 2;
    }
    else if (d > 1400 && d <= 2000)
    {
        return 3;
    }
}

int main()
{
    int D;

    scanf("%d", &D);

    printf("%d\n", checarPontos(D));

    return 0;
}