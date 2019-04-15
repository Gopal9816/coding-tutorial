#include "iostream"

using namespace std;

void counting_sort(int arr[], int n){
    int count[100] = {0};

    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    for(int i = 0; i < 100; i++)
        cout<<count[i]<<" ";

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)  
        cin>>arr[i];
    counting_sort(arr,n);
    return 1;
}