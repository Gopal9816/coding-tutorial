#include "vector"
#include "iostream"
#include "chrono"

using namespace std;

void getPrimes(int n){
    vector<int> primes;
    bool flag;
    for(int i = 2; i <= n; i++)
    {
        flag = true;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag)
            primes.push_back(i);
    }
    
    for(int i = 0; i < primes.size(); i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    int n;
    cin>>n;


    auto start = chrono::high_resolution_clock::now();
    getPrimes(n);
    auto end = chrono::high_resolution_clock::now();

    auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout<<elapsed_time.count()<<"ms\n";
}