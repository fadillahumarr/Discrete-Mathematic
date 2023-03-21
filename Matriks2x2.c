#include <stdio.h>

int main()
{
    float matriks[2][2], determinan, invers[2][2];

    printf("Input nilai matriks yang berordo 2x2:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%f", &matriks[i][j]);
        }
    }
    printf("\nTampilkan matriks ordo 2x2 yang sudah diinput:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.0f\t", matriks[i][j]);
        }
        printf("\n");
    }

    // Menghitung determinan
    determinan = matriks[0][0] * matriks[1][1] - matriks[0][1] * matriks[1][0];

    printf("Nilai Determinan = %.2f", determinan);
    if (determinan == 0)
    {
        printf("\nMatriks singular dan tidak memiliki invers");
    }
    else
    {
        // Menghitung invers
        invers[0][0] = matriks[1][1] / determinan;
        invers[0][1] = matriks[0][1] / -determinan;
        invers[1][0] = matriks[1][0] / -determinan;
        invers[1][1] = matriks[0][0] / determinan;

        printf("\nTampilkan invers matriksnya :\n");
        printf("| %.2f  %.2f |\n", invers[0][0], invers[0][1]);
        printf("| %.2f  %.2f |\n", invers[1][0], invers[1][1]);
    }
    return 0;
}