#include<bits/stdc++.h>
using namespace std;


void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller
                // element is found
                min_idx = j; 
            }
        }

        // Move minimum element to its
        // correct position
        swap(arr[i], arr[min_idx]);
    }
}

void print(vector<int>& arr){
    int num = arr.size();
    ofstream bs("ss-sorted.txt");
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
	selectionSort(arr);
	finish = clock();
	cout << "Time required = " << (float)(finish - start)/CLOCKS_PER_SEC << " seconds";
    file.close();
    

    print(arr);
    
}

// time required
// for 10000 --- 0.16714 s
// for 20000 --- 0.67993 s
// for 30000 --- 1.77016 s
// for 50000 --- 5.11929 s
// for 100000 --- 22.2273 s