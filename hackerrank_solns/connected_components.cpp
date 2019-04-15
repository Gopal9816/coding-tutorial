#include "iostream"
#include "vector"
#include "queue"
#include "string"
#include "algorithm"

using namespace std;

int bfs(vector<vector<int>> *adj_list, vector<string> *color, int start){
    queue<int> q;
    q.push(start);
    color->at(start) = "WHITE";
    int count = 0;
    //cout<<"BFS Init OK\n";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x:adj_list->at(u)){
            if(color->at(x) == "WHITE"){
                q.push(x);
                color->at(x) = "GREY";
            }
        }
        color->at(u) = "BLACK";
        count++;
    }
    return count;
}


int main(){
    vector<vector<int>> adj_list;
    vector<string> color;
    vector<int> count;
    int n;
    cin>>n;
    adj_list.resize(2*n + 1);
    color.resize(2*n + 1);
    int u,v;
    for(int i = 0; i < n; i++){
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    //cout<<"Adj List OK\n";
    for(auto i=color.begin(); i < color.end(); i++){
        *i = "WHITE";
    }
    //cout<<"Color init OK\n";
    int t;
    //int i = 0;
    color.at(0) = "BLACK";
    //cout<<"Starting BFS loop\n";
    for(auto i = color.begin(); i < color.end()-1; i++){
        //cout<<*i<<endl;
        if(*i == "WHITE"){
            //cout<<"BFS at "<<*i<<endl;
            t = bfs(&adj_list,&color,i - color.begin());
            count.push_back(t);
        }
    }
    sort(count.begin(),count.end());
    int small = count.front();
    auto it = count.begin();
    while(small == 1){
        it++;
        small = *it;
    }
    cout<<small<<" "<<count.back();
}