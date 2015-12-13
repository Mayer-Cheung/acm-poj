#include <cstdio>

using namespace std;

int main()
{
    int s, d;
    while (~scanf("%d%d", &s, &d))
    {
        if (s * 4 - d < 0)
            if (s * 10 - d * 2 > 0) 
            	printf("%d\n", s * 10 - d * 2);
            else 
            	printf("Deficit\n");
        else if (s * 3 - d * 2 < 0)
            if (s*8 - d*4 > 0) 
            	printf("%d\n", s * 8 - d * 4);
            else 
            	printf("Deficit\n");
        else if (s * 2 - d * 3 < 0)
            if (s * 6 - d * 6 > 0) 
            	printf("%d\n", s * 6 - d * 6);
            else 
            	printf("Deficit\n");
        else if (s - d * 4 < 0)
            if (s * 3 - d * 9 > 0) 
            	printf("%d\n", s * 3 - d * 9);
            else 
            	printf("Deficit\n");
        else 
        	printf("Deficit\n");
    }
    return 0;
}
