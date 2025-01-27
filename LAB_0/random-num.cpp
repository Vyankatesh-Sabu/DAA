#include<bits/stdc++.h>
using namespace std;


//generate number of random number
int main(){
    int create_num = 50000;
    ofstream file("file.txt");
    for (int i = 0; i < create_num; i++)
    {
        int random_num = rand()%100000 +1;
        file<<random_num;
        if(i!=9999){
            file<<endl;
        }
    }
    
}