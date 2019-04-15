#include "bits/stdc++.h"

using namespace std;

int closestNumber(int a, int b, int x){
    unsigned long long res = pow(a,b);
    int mod = res%x;
    if(mod <= x/2){
        return res - mod;
    }
    else{
        return res + (x-mod);
    }
}

int main(){
    int t;
    cin>>t;
    int a,b,x;
    while(t--){
        cin>>a>>b>>x;
        int result = closestNumber(a,b,x);
        cout<<result<<endl;
    }
    return 0;
}
