#include<bits/stdc++.h>
using namespace std;


string preprocess(string word){
    string result;
    for(char c : word){
        if(isalpha(c)){
            result += toupper(c);
        }
    }

    return result;
}

int main(){

    //dictionary vector
    vector<string> dictionary;
    vector<string> document;
    // open file

    ifstream fin("dictionary.txt",std::ios::in);
    if(!fin.is_open()){
        cout<<"Error opening file"<<endl;
        return 0;
    }else{
        string word;
        while(fin>>word){
            dictionary.push_back(word);
        }

    }

    // printf("%d",dictionary.size());
    fin.close();

    sort(dictionary.begin(),dictionary.end());

    ifstream fin1("document.txt",std::ios::in);
    if(!fin1.is_open()){
        cout<<"Error opening file"<<endl;
        return 0;
    }else{
        string word;
        while(fin1>>word){
            word = preprocess(word);
            document.push_back(word);
        }
    }

    fin1.close();

    sort(document.begin(),document.end());
    vector<string> misspelled;

    while(!document.empty()){
        string word = document.back();
        document.pop_back();
        if(!binary_search(dictionary.begin(),dictionary.end(),word)){
            misspelled.push_back(word);
        }
    }

int count =0;
    while(!misspelled.empty()){
        cout<<misspelled.back()<<endl;
        misspelled.pop_back();
        count++;
    }

    cout<<count<<endl;
}