#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print(vector<int>& arr){
    int num = arr.size();
    ofstream bs("is-sorted.txt");
    for (int i = 0; i < num; i++)
    {
        bs<<arr[i]<<endl;
    }
    
}

int main(){
    ifstream file("file.txt");
    int num;
    int count=0;
    vector<int> arr;
    while(!file.eof()){
        file>>num;
        arr.push_back(num);
        count++;
    }
    
    clock_t start,finish;
    
    start = clock();
	insertionSort(arr);
	finish = clock();
	cout << "Time required = " << (float)(finish - start)/CLOCKS_PER_SEC << " seconds";
    file.close();
    

    print(arr);
    
}

// time required
// for 10000 --- 0.119093 s
// for 20000 --- 0.46387 s
// for 30000 --- 1.02172 s
// for 50000 --- 2.93075 s
// for 100000 --- 11.3698 s