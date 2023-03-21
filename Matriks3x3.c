#include <stdio.h>
#include <math.h>

int main()
{
    float matriks[3][3], determinan, invers[3][3], kofaktor[3][3], adjoint[3][3];
    printf("Input nilai matriks yang berordo 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &matriks[i][j]);
        }
    }

    printf("\nTampilkan matriks ordo 3x3 yang sudah diinput:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.0f\t", matriks[i][j]);
        }
        printf("\n");
    }

    // Menghitung determinan
    determinan = (((matriks[0][0] * matriks[1][1] * matriks[2][2]) + (matriks[0][1] * matriks[1][2] * matriks[2][0]) +
                   (matriks[0][2] * matriks[1][0] * matriks[2][1]) - ((matriks[2][0] * matriks[1][1] * matriks[0][2]) +
                   (matriks[2][1] * matriks[1][2] * matriks[0][0]) + (matriks[2][2] * matriks[1][0] * matriks[0][1]))));

    printf("Nilai Determinan = %.2f", determinan);

    if (determinan == 0)
    {
        printf("\nMatriks singular dan tidak memiliki invers");
    }
    else
    {
        // Menghitung matriks kofaktor dan adjoint
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                kofaktor[i][j] = (((matriks[(j + 1) % 3][(i + 1) % 3] * matriks[(j + 2) % 3][(i + 2) % 3]) -
                                   (matriks[(j + 1) % 3][(i + 2) % 3] * matriks[(j + 2) % 3][(i + 1) % 3])));
                adjoint[i][j] = kofaktor[i][j] * pow(-1, i + j); // Memasukkan elemen kofaktor ke dalam matriks adjoint
            }
        }

        // Menghitung invers
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                invers[i][j] = adjoint[i][j] / determinan;
            }
        }

        // Menampilkan matriks invers
        printf("\nMatriks Invers:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%.2f\t", invers[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
