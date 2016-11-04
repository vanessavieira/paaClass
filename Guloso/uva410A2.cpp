
#include <bits/stdc++.h>

using namespace std;

bool callback(int a, int b){
    return a > b;
}
int main(){
    int C, S, turn = 0;
    double avg, imbalance;
    int mass[10000];
    while(cin >> C >> S){
        for(int i = 0; i < S; i++)
            scanf("%d", &mass[i]);

        avg = (double)accumulate(mass, mass+S,0)/C;

        for(int i = S; i < 2*C; i++)
            mass[i] = 0;

        sort(mass, mass + 2*C,callback);

        imbalance = 0;

        printf("Set #%d\n", ++turn);

        for(int i = 0; i< C; i++){
            printf(" %d:",i);

            if(mass[2 * C - i - 1])
                printf(" %d", mass[2*C-i-1]);
            if(mass[i])
                printf(" %d", mass[i]);

            imbalance += abs(mass[i] + mass[2*C-i-1] - avg);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
    return 0;
}