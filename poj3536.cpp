#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>

using namespace std;

int canzhen[1000];
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        memset(canzhen,0,sizeof(canzhen));
        int min = 999999999;
        int biaoi=0,biaoj=0,biaok=0;
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(n%i == 0){
                canzhen[count++] = i;
            }
        }
        for(int i = 0; i < count;i++){
            for(int j = 0; j < count; j++){
                for(int k = 0; k < count; k++){
                    if(canzhen[i]*canzhen[j]*canzhen[k] == n){
                        if(canzhen[i]*canzhen[j]+canzhen[j]*canzhen[k]+canzhen[i]*canzhen[k] <= min)
                        {
                            min = canzhen[i]*canzhen[j]+canzhen[j]*canzhen[k]+canzhen[i]*canzhen[k];
                            biaoi = canzhen[i];
                            biaoj = canzhen[j];
                            biaok = canzhen[k];
                        }
                    }
                }
            }
        }

        printf("%d %d %d\n", biaoi, biaoj, biaok);
    }
    return 0;
}