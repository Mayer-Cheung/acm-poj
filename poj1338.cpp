#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1505;

int min(int a, int b, int c)
{
	int min;
	min = a < b ? a : b;
	min = min < c ? min : c;
	return min;
}

int main()
{
	int ugly[MAXN];
	ugly[1] = 1;
	int p2, p3, p5;
	p2 = p3 = p5 = 1;
	for (int i = 2; i <= MAXN; i++)
	{
		int val2 = ugly[p2] * 2;
		int val3 = ugly[p3] * 3;
		int val5 = ugly[p5] * 5;
		ugly[i] = min(val2, val3, val5);

		if (ugly[i] == val2)
			p2++;
		if (ugly[i] == val3)
			p3++;
		if (ugly[i] == val5)
			p5++;
	}

	int n;
	while (scanf("%d", &n), n)
	{
		printf("%d\n", ugly[n]);
	}
}#include <iostream>
using namespace std;

const int MAX_POS = 1500;

/*返回三者的最小值*/
int myMin(int a, int b, int c) {
    int min;
    min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}

int main()
{
    int ugly[MAX_POS + 1];
    ugly[1] = 1;
    int p2, p3, p5;
    p2 = p3 = p5 = 1;

    /*先求出MAX_POS个ugly number*/
    for(int i = 2; i <= MAX_POS; i++) {
        int value2 = ugly[p2] * 2;
        int value3 = ugly[p3] * 3;
        int value5 = ugly[p5] * 5;
        ugly[i] = myMin(value2, value3, value5);
        /*使用最小那个ugly number的下标加1*/
        if(ugly[i] == value2) p2++;
        if(ugly[i] == value3) p3++;
        if(ugly[i] == value5) p5++;
    }

    int n;
    while(cin >> n, n != 0) {
        cout << ugly[n] << endl;
    }

    return 0;
}