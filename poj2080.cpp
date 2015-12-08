#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

char strd[33][5], strm[14][5];
char week[7][12] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int year[2] = {365, 366};

struct Cal 
{
    int y, m, d;
} cal;

int isRun(int n)
{
    if ((n%4 == 0 && n%100 != 0) || (n % 400 == 0))
        return 1;
    return 0;
}
int main() 
{
    int n, y, m, d;
    while (scanf("%d", &n) != EOF) 
    {
        if (n == -1)
            break;
        d = n%7;
        n++;
        y = m = 0;
        while (n > year[isRun(2000 + y)]) 
        {
            n-=year[isRun(2000+y)];
            y++;
        }

        y+=2000;
        if(isRun(y))
            month[2]++;
        int i;
        for (i = 1; i <= 12; i++) 
        {
            if (n > month[i]) 
            {
                n -= month[i];
            }
            else
                break;
        }

        m = i;
        if (month[2] == 29)
            month[2]--;
        cout << y << "-" << (m < 10? "0" : "") << m << "-" 
        << (n < 10? "0" : "") << n << " " << week[d] << endl;

    }
    return 0;
}