#include "iostream"
#include "vector"

using namespace std;

struct sent{
    int val;
    string word;
};

typedef struct sent sent;

void counting_sort(vector<sent> arr){
    vector<vector<string>> helper(100);
    /* vector<vector<string>>::iterator arr_it;
    vector<string>::iterator str_it; */

    for(auto x:arr){
            helper[x.val].push_back(x.word);
    }

    for(auto x:helper)
        for(auto y:x)
            cout<<y;

}

int main(){
    int n;
    cin>>n;
    vector<sent> arr(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i].val;
        cin>>arr[i].word;
        if(i < n/2)
            arr[i].word = "-";
    }

    counting_sort(arr);
}