#include "iostream"

using namespace std;

void partition(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left+1;
    int j = right;
    int t;
    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j){
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    t = arr[left];
    arr[left] = arr[j];
    arr[j] = t;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    partition(arr,0,n-1);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}