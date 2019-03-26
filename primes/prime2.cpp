#include "bits/stdc++.h"

using namespace std;

void getPrimes(int n){
    vector<bool> numList(n+1,true);
    vector<int> primes;

    for(int i = 2; i <=n; i++){
        if(numList[i]){
            primes.push_back(i);
            for(int j = 2*i; j <= n; j+=i)
                numList[j] = false;
        }
    }

    for(int i = 0; i < primes.size(); i++){
        cout<<primes[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;

    getPrimes(n);

}