#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[2][n];
    for(int i =0; i<n; i++){
        cin>>arr[0][i];
        cin>>arr[1][i];
    }

    int point[n] = {0};
    for(int i =0; i<n-1; i++){
        for(int j =i+1; j<n; j++){
            if(arr[0][i]==arr[0][j] && arr[1][i]==arr[1][j]){
                point[i]++;
                point[j]++;
            }else if(arr[0][i]<=arr[0][j] && arr[1][i]>=arr[1][j]){
                point[i] = point[i] +2;
            }else if(arr[0][i]>=arr[0][j] && arr[1][i]<=arr[1][j]){
                point[j]= point[j] + 2;
            }
        }
    }

    for(int i =0; i<n; i++){
        cout<<point[i]<<"  ";
    }

    cout<<endl;


}

int main(){
    solve();
}