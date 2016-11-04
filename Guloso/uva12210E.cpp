#include<bits/stdc++.h>

using namespace std;

int main() {
    int B,S,count=0,ara[10000],i,j,temp,a,arr[10000];

    while(cin >> B >> S) {
        if(!(B + S)) break;
        else if(B <= S) {
            for(i = 0; i < B; i++) cin >> ara[i];
            for(j = 0; j < S; j++) cin >> arr[j];
            printf("Case %d: 0\n",++count);
        }
        else {
            a=B-S;
            for(i = 0; i < B; i++) cin >> ara[i];
            for(j = 0; j < S; j++) cin >> arr[j];
            for(j = 0; j < B-1; j++)
                for(i = 0; i< B; i++)
                    if(ara[i]>ara[i+1]) swap(ara[i], ara[i + 1]);
            printf("Case %d: %d %d\n",++count,a,ara[0]);
        }
    }
    return 0;
}
