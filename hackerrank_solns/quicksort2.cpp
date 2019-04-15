#include "iostream"
#include "vector"

using namespace std;

int partition(int arr[],int left,int right){
    int pivot = arr[left];
    int t;
    int i = left+1;
    int j = right;
    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j){
            t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
            i++;
            j--;
        }
    }
    t = arr[left];
    arr[left] = arr[j];
    arr[j] = t;
    return j;
}

void quicksort(int arr[], int left, int right){
    int middle;

    middle = partition(arr,left,right);
    if(left < middle - 1)
        quicksort(arr,left,middle-1);
    if(right>middle+1)
        quicksort(arr,middle+1,right);
    for(int i = left; i <= right; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}