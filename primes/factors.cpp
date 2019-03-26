#include "vector"
#include "iostream"

using namespace std;

vector<int> primes;

void sieve(int n){
    vector<bool> nums(n+1,true);

    for(int i = 2; i <= n; i++){
        if(nums[i]){
            primes.push_back(i);
            for(int j = 2*i; j <= n; j+= i)
                nums[i] = false;
        }
    }

}

void factors(int n){
    vector<int> factors;
    int i = 0;
    int fact = primes[i];
    while(n >= 1 && fact*fact <= n ){
        while(n%fact == 0){
            factors.push_back(fact);
            n = n/fact;
        }
        fact = primes[++i];
    }

    if(n != 1)
        factors.push_back(n);

    for(int i = 0; i < factors.size(); i++){
        cout<<factors[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    sieve(n);
    factors(n);
}
