#include<bits/stdc++.h>


using namespace std;

int  main(){
    int heads,  knights,a[20000],b[20000];
    
    while(true){
        cin >> heads >>  knights;
        if(!(heads + knights)) break;
        
        for(int i = 0;i < heads;++i) cin >> a[i];
        for(int i = 0;i <  knights;++i) cin >> b[i];
        
        int aux = 0;
        bool ok = true;
        
        sort(a,a + heads);
        sort(b,b + knights);
        
        for(int i = 0,j = 0;i < heads && ok;++i){
            while(j < knights && b[j] < a[i]) ++j;
            
            if(j == knights) ok = false;
            else aux += b[j++];
        }
        
        if(!ok) cout << "Loowater is doomed!" << endl;
        else cout << aux << endl;
    }
    
    return 0;
}