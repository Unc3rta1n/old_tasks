#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>


char str[] = "122";
//Возвращает true, если str[curr] не совпадает ни с одним из
// символов после str[start]
bool shouldSwap(char str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void findPermutations(char str[], int index, int n)
{
    if (index >= n) {
        puts(str);

        return;
    }

    for (int i = index; i < n; i++) {

        //Продолжаем для str[i], только если он не совпадает ни с одним из символов после str[index]
        bool check = shouldSwap(str, index, i);
        if (check) {
            
            char c = str[index];
            str[index] = str[i];
            str[i] = c;
            findPermutations(str, index + 1, n);
            
             c = str[index];
            str[index] = str[i];
            str[i] = c;
        }
    }
}


int main()
{
    
    int n = strlen(str);
    findPermutations(str, 0, n);
    return 0;
}