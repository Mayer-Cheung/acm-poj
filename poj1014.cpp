#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 60005;
#define INIT 0xffffffff
int f[MAXN];

void ZeroOnePack(int cost, int weight, int V)
{
        for (int v = V; v >= cost; v--)
                f[v] = max(f[v], f[v - cost] + weight);
}

void CompletePack(int cost, int weight, int V)
{
        for (int v = cost; v <= V; v++)
                f[v] = max(f[v], f[v - cost] + weight);
}

void MultiPack(int cost, int weight, int num, int V)
{
        if (cost * num >= V)
        {
                CompletePack(cost, weight, V);
                return;
        }
        int k = 1;
        while (k < num)
        {
                ZeroOnePack(k * cost, k * weight, V);
                num -= k;
                k *= 2;
        }
        ZeroOnePack(cost * num, num * weight, V);
}

int main()
{
        int index = 0;
        int num[7];
        while (true)
        {
                ++index;
                int sum = 0;
                int bin = 0;
                for (int i = 1; i < 7; i++)
                {
                        scanf("%d", &num[i]);
                        sum += i * num[i];
                        bin |= num[i];
                }

                if (!bin)
                        break;

                if (sum & 0x01)
                        printf("Collection #%d:\nCan't be divided.\n\n", index);
                else
                {
                        int V = sum >> 1;
                        f[0] = 0;
                        for (int i = 1; i <= V; i++)
                                f[i] = INIT;

                        for (int i = 1; i < 7; i++)
                                MultiPack(i, i, num[i], V);

                        if (f[V] != V)
                                printf("Collection #%d:\nCan't be divided.\n\n", index);
                        else
                                printf("Collection #%d:\nCan be divided.\n\n", index);


                }
        }
}