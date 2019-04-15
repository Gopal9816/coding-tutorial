#include "iostream"

using namespace std;

int partition(int arr[], int left, int right, int max){
    int pivot = arr[right];
    int i = left;
    int j = right-1;
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
    t = arr[right];
    arr[right] = arr[i];
    arr[i] = t;
    //print_array(arr,max);
    return i;
}

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void quicksort(int arr[], int left, int right,int max){
    int mid;

    mid = partition(arr,left,right,max);

    if(left<mid-1)
        quicksort(arr,left,mid-1,max);
    if(right>mid+1)
        quicksort(arr,mid+1,right,max);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    quicksort(arr,0,n-1,n);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}