#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSolution(int **board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%s ", board[i][j] ? "Q" : "#");
        printf("\n");
    }
}

bool solve(int **board, bool row[], bool diag1[], bool diag2[], int N, int col)
{
    if (col == N)
        return true;

    for (int i = 0; i < N; i++)
    {
        int d1 = i - col + N - 1;
        int d2 = i + col;

        if (!row[i] && !diag1[d1] && !diag2[d2])
        {
            board[i][col] = 1;
            row[i] = diag1[d1] = diag2[d2] = true;

            if (solve(board, row, diag1, diag2, N, col + 1))
                return true;

            board[i][col] = 0;
            row[i] = diag1[d1] = diag2[d2] = false;
        }
    }

    return false;
}

bool solveNQ(int N)
{
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        board[i] = (int *)calloc(N, sizeof(int));

    bool *row = (bool *)calloc(N, sizeof(bool));
    bool *diag1 = (bool *)calloc(2 * N - 1, sizeof(bool));
    bool *diag2 = (bool *)calloc(2 * N - 1, sizeof(bool));

    if (!solve(board, row, diag1, diag2, N, 0))
    {
        printf("Solution does not exist\n");

        for (int i = 0; i < N; i++)
            free(board[i]);
        free(board);
        free(row);
        free(diag1);
        free(diag2);

        return false;
    }

    printSolution(board, N);

    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
    free(row);
    free(diag1);
    free(diag2);

    return true;
}

int main()
{
    int N;

    printf("Enter the number of queens: ");
    scanf("%d", &N);

    solveNQ(N);

    return 0;
}
