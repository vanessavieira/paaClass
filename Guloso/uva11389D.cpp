#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    int n, d, r;
    vector<int>morn;
    vector<int>even;

    while(cin >> n >> d >> r){
        if(!(n + d + r)) break; 
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            morn.push_back(x);
        }
        sort(morn.begin(),morn.end());
        for(int i = 0; i < n; i++) {
            cin >> x;
            even.push_back(x);
        }
        sort(even.begin(),even.end(),greater <int>());
        int overtime = 0;
        for(int i=0; i<n; i++) {
            int h = morn[i] + even[i];
            if(h > d) overtime = overtime + (h-d);
        }
       cout << overtime*r <<endl;
       morn.clear();
       even.clear();
    }
    return 0;
}