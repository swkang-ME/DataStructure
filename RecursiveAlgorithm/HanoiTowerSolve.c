#include <stdio.h>

int movePlate(int PlateStare, char InitPole, char ByPole, char FinalPole);

int main()
{
    int PlateStare;

    printf("하노이 타워 갯수: ");
    scanf("%d", &PlateStare);
    printf("\n");

    movePlate(PlateStare, 'A', 'B', 'C');
}

int movePlate(int PlateStare, char InitPole, char ByPole, char FinalPole)
{
    if (PlateStare == 1)
    {
        printf("원판 %d를 %c에서 %c로 이동\n", PlateStare, InitPole, FinalPole);
    }
    else if (PlateStare >= 2)
    {
        movePlate(PlateStare - 1, InitPole, FinalPole, ByPole);
        printf("원판 %d를 %c에서 %c로 이동\n", PlateStare, InitPole, FinalPole);
        movePlate(PlateStare - 1, ByPole, InitPole, FinalPole);
    }
}
