#include<stdio.h>
#include<stdbool.h>

#define WIDTH 7
#define HEIGHT 7 
int x, y, x1, y1;
int gridArray[WIDTH][HEIGHT] =
{   { -1,-1,-1,-1,-2,-1,-2 },
    { -2,-1,-1,-1,-1,-2,-2 },
    { -2,-1,-1,-1,-1,-2,-2 },
    { -2,-2,-1,-1,-1,-2,-1 },
    { -1,-2,-2,-2,-1,-1,-2 },
    { -1,-2,-1,-1,-1,-2,-2 },
    { -2,-2,-1,-1,-1,-1,-1 }  };
char gridWave[WIDTH][HEIGHT];
void mapPrint(int map[WIDTH][HEIGHT])
{
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            printf("%4d  ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void initcoords()
{
    printf("enter the start coordinate x,y:\n");
    scanf_s("%d %d", &x, &y);
    if (gridArray[x][y] == -1)
    {
        gridArray[x][y] = 0;
        mapPrint(gridArray);
    }
    printf("enter the finish coordinate x,y:\n");
    scanf_s("%d %d", &x1, &y1);
    if (gridArray[x1][y1] == -1)
    {
        gridArray[x1][y1] = -3;
        mapPrint(gridArray);
    }
}
void initwalls(int gridArray[WIDTH][HEIGHT], char gridWave[WIDTH][HEIGHT])
{
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            if (gridArray[i][j] == 0)
                gridWave[i][j] = 'S';
            else if (gridArray[i][j] == -3)
                gridWave[i][j] = 'E';
            else if (gridArray[i][j] == -2)
                gridWave[i][j] = '#';
            else if (gridArray[i][j] == -1)
                gridWave[i][j] = '.';
        }
    }
}
void printsolve()
{
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            printf("%4c  ", gridWave[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool SolveMaze()
{
    bool foundEnd = false;
    int dist = 0;
    while (!foundEnd)
    {
        bool foundEmpty = false;
        for (int x = 0; x < WIDTH && !foundEnd; ++x)
        {
            for (int y = 0; y < HEIGHT; ++y)
            {
                if (gridArray[x][y] == dist)
                {
                    // check east cell
                    if (x < WIDTH - 1)
                    {
                        if (gridArray[x + 1][y] == -3)
                        {
                            foundEnd = true;
                            gridArray[x + 1][y] = dist + 1;
                            break;
                        }
                        else if (gridArray[x + 1][y] == -1)
                        {
                            gridArray[x + 1][y] = dist + 1;
                            foundEmpty = true;
                        }
                    }
                    // check west cell
                    if (x > 0)
                    {
                        if (gridArray[x - 1][y] == -3)
                        {
                            foundEnd = true;
                            gridArray[x - 1][y] = dist + 1;
                            break;
                        }
                        else if (gridArray[x - 1][y] == -1)
                        {
                            gridArray[x - 1][y] = dist + 1;
                            foundEmpty = true;
                        }
                    }
                    // check south cell
                    if (y < HEIGHT - 1)
                    {
                        if (gridArray[x][y + 1] == -3)
                        {
                            foundEnd = true;
                            gridArray[x][y + 1] = dist + 1;
                            break;
                        }
                        else if (gridArray[x][y + 1] == -1)
                        {
                            gridArray[x][y + 1] = dist + 1;
                            foundEmpty = true;
                        }
                    }
                    // check north cell
                    if (y > 0)
                    {
                        if (gridArray[x][y - 1] == -3)
                        {
                            foundEnd = true;
                            gridArray[x][y - 1] = dist + 1;
                            break;
                        }
                        else if (gridArray[x][y - 1] == -1)
                        {
                            gridArray[x][y - 1] = dist + 1;
                            foundEmpty = true;
                        }
                    }
                }
            }
        }
        if (!foundEnd && !foundEmpty)
        {
            printf_s("This maze has no solution!\n");
            return false;
        }
        dist++;
    }
    return true;
}
void find_path()
{
    int endpath = 0;
    if (gridArray[x1][y1] > 0)
    {
        endpath = gridArray[x1][y1];
    }
    while (endpath != 0)
    {
        if (gridArray[x1 + 1][y1] == endpath - 1)
        {
            gridWave[x1 + 1][y1] = 'G';
            x1 = x1 + 1;
            y1 = y1;
            endpath--;
            continue;
        }
        if (gridArray[x1 - 1][y1] == endpath - 1)
        {
            gridWave[x1 - 1][y1] = 'G';
            x1 = x1 - 1;
            y1 = y1;
            endpath--;
            continue;
        }
        if (gridArray[x1][y1 + 1] == endpath - 1)
        {
            gridWave[x1][y1 + 1] = 'G';
            x1 = x1;
            y1 = y1 + 1;
            endpath--;
            continue;
        }
        if (gridArray[x1][y1 - 1] == endpath - 1)
        {
            gridWave[x1][y1 - 1] = 'G';
            x1 = x1;
            y1 = y1 - 1;
            endpath--;
            continue;
        }
    }
}

int main()
{
    mapPrint(gridArray);
    initcoords();
    initwalls(gridArray, gridWave);
    if (!SolveMaze()) {
        printsolve();
        return 0;
        system("pause");
    }
    else
    {
        mapPrint(gridArray);
        find_path();
        printsolve();
        system("pause");
    }
    return 0;
}
