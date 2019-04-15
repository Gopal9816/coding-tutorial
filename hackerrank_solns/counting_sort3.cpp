#include "iostream"
using namespace std;

void counting_sort(int arr[], int n){
    int count[100] = {0};
    int num=0;
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    for(int i = 0; i < 100; i++){
        while(count[i]--)
            num++;
        cout<<num<<" ";
    }

}


int main(){
    int n;
    string s,val;
    string::size_type sz;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        cin>>s;
    }
    counting_sort(arr,n);
    return 0;
}