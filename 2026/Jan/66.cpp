#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> & digits){
    int carry = 1;

    for (int i = digits.size() - 1 ; i >=0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    

    if (carry)
    {
        digits.insert(digits.begin() , 1);
    }
    return digits;
}

int main(){
    vector<int> digits = {9};

    vector<int> result =  plusOne(digits);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    return 0;
}