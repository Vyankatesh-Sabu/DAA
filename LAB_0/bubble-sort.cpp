#include<bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

void print(vector<int>& arr){
    int num = arr.size();
    ofstream bs("bs-sorted.txt");
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
	bubbleSort(arr);
	finish = clock();
	cout << "Time required = " << (float)(finish - start)/CLOCKS_PER_SEC << " seconds";
    file.close();
    

    print(arr);

    ifstream file1("bs-sorted.txt");
    count=0;
    vector<int> bs;
    while(!file.eof()){
        file>>num;
        bs.push_back(num);
        count++;
    }
    
    clock_t s,f;
    
    start = clock();
	bubbleSort(bs);
	finish = clock();
	cout << "Time required = " << (float)(f - s)/CLOCKS_PER_SEC << " seconds";
    file1.close();
    

    print(arr);
    
}

// time required
// for 10000 --- 0.34995 s
// for 20000 --- 1.49101 s
// for 30000 --- 3.7234 s
// for 50000 --- 11.72 s
// for 100000 --- 48.4144 s