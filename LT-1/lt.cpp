#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter total Number of Singers: ";
    int N;
    cin>>N;
    cout<<"Enter pitches of all:";
    vector<pair<int,int>>ranges(N);
    vector<int> scores(N);         
    for(int i=0;i<N;i++){
        cin>>ranges[i].first>>ranges[i].second;
    }
    vector<int>indices(N);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(),indices.end(),[&ranges](int a,int b){
        return ranges[a].first<ranges[b].first;
    });
    for(int i=0;i<N;i++){
        scores[indices[i]]=2*(N-i-1);
    }
    for (int i = 0; i < N; i++) {
        cout << scores[i] << " ";
    }
}