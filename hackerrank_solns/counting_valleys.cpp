#include "iostream"
#include "vector"
using namespace std;

int main(){
    int n;
    string hike;

    cin>>n;
    cin>>hike;

    string::iterator it = hike.begin();
    int count = 0, level = 0;
    for(int i = 0; i < n; i++, it++)
    {
        int t = level;
        if(*it == 'U'){
            level++;
        }
        else
        {
            level--;
        }
        if(t == 0 && level == -1)
            count++;
    }

    cout<<count;
    
}