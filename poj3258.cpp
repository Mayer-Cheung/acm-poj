/*POJ 3258 River Hopscotch
Main thoughts: use binary search to maximize the minimum
Difficulty for me :
1. cant figure out how to count the number of the removed rock
2. not very clear about the next operation after binary search
there are two methods to do:
1. instead of considering how to remove, thinking about how to put the remain N-M rocks
2. use a count to record the number, instead of using M inside of the loop, it's really convinient to record.
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int L, N, M;
int a[50010];
//  second method count the number that need to be removed by order
int binarysearch(int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        int count = 0;
        int s = 0, e = 1;
        while (e < n) {
            if (d[e] - d[s] >= mid)
                s = e, e += 1;
            else 
                e += 1, count += 1;
        }
        if (count > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high;
}
//  first method, just consider how to put the remaining rocks, if reaches the end, return false
bool check(int n)
{
	int last = 0;
	for (int i = 1; i < N - M; i++)
	{
		int current = last + 1;
		while (current < N && a[current] - a[last] < n)
		{
			current++;
		}
		if (current == N)
		{
			return false;
		}
		last = current;
	}
	return true;
}
int main()
{
	scanf("%d%d%d", &L, &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	a[++N] = L;
	++N;
	sort(a, a + N);
	// for (int i = 0; i <= N; i++)
	// 	printf("%d\n", a[i]);
	int lb = 0, ub = L + 1;
	while (ub - lb > 1)
	{
		int mid = (lb + ub) / 2;
		if (check(mid))
			lb = mid;
		else
			ub = mid;
	}
	printf("%d\n", lb);
}