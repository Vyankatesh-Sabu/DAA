#include <iostream>
#include <vector>
using namespace std;

long int C(int n){
    if(n==0) return 1;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;

    return C(n-1) + C(n-2) + C(n-3);
}

long int interativeC(int n){
    if(n==0) return 1;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;

    long int prev1 = 1;
    long int prev2 = 1;
    long int prev3 = 2;

    for(int i=3; i<=n; i++){
        long int current = prev1 + prev2 + prev3;
        prev1 = prev2;
        prev2 = prev3;
        prev3 = current;
    }   

    return prev3;
}

long int CInM(int n, int m){
    if(n == 0 && m == 0) return 1;
    if(n == 0 || m == 0) return 0;
    if(n < m) return 0;

    return CInM(n-1, m-1) + CInM(n-2, m-1) + CInM(n-3, m-1);
}

long int CInMIterative(int n, int m){
    if(n < 0 || m < 0) return 0;
    if(n == 0 && m == 0) return 1;
    if(m == 0) return 0;
    if(n == 0) return 0;

    vector<long int> dp(n + 1, 0);
    dp[0] = 1;

    for(int jumps = 1; jumps <= m; jumps++){
        vector<long int> new_dp(n + 1, 0);
        for (int steps = 1; steps <= n; steps++) {
            new_dp[steps] = (steps - 1 >= 0 ? dp[steps - 1] : 0)
                          + (steps - 2 >= 0 ? dp[steps - 2] : 0)
                          + (steps - 3 >= 0 ? dp[steps - 3] : 0);
        }
        dp = new_dp;
    }

    return dp[n];
}

void forAllM(int n){
    long int sum = 0;
    for(int i=0; i<=n; i++){
        long int temp = CInM(n, i);
        cout << temp <<endl;
        sum += temp;
    }

    cout << "Sum: " << sum << endl<<endl;

    sum = 0;
    for(int i=0; i<=n; i++){
        long int temp = CInMIterative(n, i);
        cout << temp <<endl;
        sum += temp;
    }

    cout << "Sum: " << sum << endl;
}

int main(){
    
    cout<<"Enter the value of n: ";
    int n;
    cin >> n;

    cout << C(n) << endl;
    cout << interativeC(n) << endl;

    forAllM(n);
    return 0;
}