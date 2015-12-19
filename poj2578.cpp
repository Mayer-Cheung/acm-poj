#include <cstdio>

using namespace std;

int main()
{
	int n;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &n);
		if (n < 168)
		{
			printf("CRASH %d\n", n);
			return 0;
		}
	}
	printf("NO CRASH\n");
}