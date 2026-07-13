#include <bits/stdc++.h>
using namespace std;


vector<int> sequentialDigits(int low , int high){
    vector<int> result;
    string digits = "123456789";

    for (int length = 2; length < 10; length++)
    {
        for (int start = 0; start + length <= 9; start++)
        {
            string s = digits.substr(start , length);
            int num = stoi(s);
            if(num >= low && num <= high){
                result.push_back(num);
            }
        }
    }
    return result;
}

int main(){
    int high = 300;
    int low = 100;

    vector<int> result = sequentialDigits(low , high);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
    
}