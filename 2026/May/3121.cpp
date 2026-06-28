#include <bits/stdc++.h>
using namespace std;


int numberOfSpecialChars(string word){
    int n = word.size();

    // create hashmap of letters pointing two [has capital occured (int) , whether special or not , if added],
    // create counter , if lower occurs for the first time and capital not there then I will increment counter
    // if lower occurs after capital and if added decrement counter
    // return counter

    unordered_map<char , vector<int>> m;

    int counter = 0;

    for (char c : word){
        bool upper = isupper(c);
        c = tolower(c);
        if(!m.count(c)){
            if(upper){
                m[c] = {1 , 0 , 0};
            }
            else{
                m[c] = {0 , 1 , 0};
            }
            continue;
        }

        if(!upper){
            m[c][1] = 1;
            if(m[c][0] && m[c][2]){
                counter--;
                m[c][2] = 0;
            }
        }
        else{
            m[c][0] = 1;
            if(m[c][1] && !m[c][2]){
                counter++;
                m[c][2] = 1;
            }
        }
        // has capital occured , has lower occured , is counted as special
    }
    return counter;
}


int main(){
    string word = "AbBCab";

    cout << numberOfSpecialChars(word);

    return 0;
}
