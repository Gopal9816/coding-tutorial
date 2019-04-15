#include "bits/stdc++.h"
#include "stdlib.h"

#define MAX_SIZE 2147483647

using namespace std;

vector<int> primes;
vector<int> arr(MAX_SIZE,0);

void sieve(){
    arr[0] = arr[1] = 1;
    for(int i = 2; i < MAX_SIZE; i++){
        if(i == 0){
            primes.push_back(i);
            for(int j = i*i; j < MAX_SIZE; j += i){
                arr[j]++;
            }
        }
    }
    cout<<"sieve completed\n";
}

int calc_smith(int n){
    int temp = n;
    vector<int> factors;
    vector<int>::iterator ia = primes.begin();
    int f = *ia;
    while(temp > 0 && f*f <= temp){
        while(temp%f == 0){
            factors.push_back(f);
            temp/=f;
        }
        f = *(++ia);
    }
    cout<<"Factors completed";
    int sum_digits = 0, sum_factors = 0;

    temp = n;
    for(temp=n; temp > 0; sum_digits+=temp%10,temp/=10);
    cout<<"Sum of digits completed";
    for(ia = factors.begin(); ia < factors.end(); ia++){
        for(temp = *ia; temp > 0; sum_factors += temp%10, temp/=10);
    }

    return (sum_digits == sum_factors)?1:0;
}

int main(){
    int t;
    int n;
    cin>>t;
    sieve();
    int res = calc_smith(t);
    cout<<res<<endl;
    return 0;
}