#include <iostream>
using namespace std;

const int N = 9;

bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; ++x)
    {
        if (grid[row][x] == num || grid[x][col] == num)
        {
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool findUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; ++row)
    {
        for (col = 0; col < N; ++col)
        {
            if (grid[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[N][N])
{
    int row, col;

    if (!findUnassignedLocation(grid, row, col))
    {
        return true;
    }

    for (int num = 1; num <= 9; ++num)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
            {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int grid[N][N];
    cout << endl;
    cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << "Enter the value for cell (" << i + 1 << ", " << j + 1 << "): ";
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid))
    {
        cout << "Sudoku solved:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}




// testcase:
/*

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

*/
