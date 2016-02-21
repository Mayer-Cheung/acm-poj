#include <iostream>
#include <cstdio> 
#define F(i,a,b) for (int i=a;i<=b;i++)  
using namespace std;  
  
int map[20][20],  
    move[4][2] = { {-1, 1}, {0, 1}, {1, 1}, {1, 0} };  
  
bool test(int x, int y)  
{  
    int c = map[x][y];  
    F(k,0,3)  
    {  
        int nowx = x, nowy = y;  
        bool done= true;  
        F(l,1,4)  
        {  
            nowx += move[k][0], nowy += move[k][1];  
            if (!(1<=nowx && nowx<=19 && 1<=nowy && nowy <=19 ) )  
            {  
                done = false;  
                break;  
            }  
            if (map[nowx][nowy] != c)  
            {  
                done = false;  
                break;  
            }  
        }  
  
        if (done && map[ x-move[k][0] ][ y-move[k][1] ] != c &&  
            map[ nowx+move[k][0] ][ nowy+move[k][1] ] !=c)  
        {  
            printf("%d\n%d %d\n", c, x, y);  
            return true;  
        }  
    }  
    return false;  
}  
  
int main()  
{  
    int T;  
  
    scanf("%d", &T);  
    F(t, 1, T)  
    {  
        F(i,1,19)  
            F (j,1,19)  
                scanf("%d", &map[i][j] );  
  
        bool done = false;  
        for (int i=1;i<=19 && !done; i++)  
            for (int j = 1; j <=19  && !done; j++)  
            {  
                if (map[i][j] != 0)  
                {  
                    if ( test(i,j) )  
                        done = true;  
                }  
            }  
  
        if (!done)  
            printf("0\n");  
    }  
  
    return 0;  
}