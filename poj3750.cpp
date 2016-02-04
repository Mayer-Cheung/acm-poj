#include <iostream>
#include <cstdio>

using namespace std;

char name[70][20];

int main()
{
	int n;
	scanf("%d", &n);
	int index[70];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
		index[i] = i;
	}
	int w, s;
	char ch;
	scanf("%d%c%d", &w, &ch, &s);
	w = (w + n - 1) % n;
	while (n)
	{
		w = (w + s - 1) % n;
		printf("%s\n", name[index[w]]);
		for (int i = w; i < n; i++)
			index[i] = index[i + 1];
		n--;
	}
}