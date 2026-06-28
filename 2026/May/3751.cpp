#include <bits/stdc++.h>
using namespace std;

int totalWaviness(int num1 , int num2){
    // i know the number of digits 

    // for 3 digit check middle /10 % 10
    // for 4 digit check 2nd and third (100)%10 , (10)%10
    // for 5 digit check 2 , 3 , 4
    // for 6 digit check 2 , 3 , 4 , 5
    if (num1 < 100)
    {
        if (num2 < 100) return 0;
        num1 = 100;
    }

    int waviness = 0;

    for (int i = num1 ; i <= num2; ++i)
    {
        int digit = floor(log10(abs(i))) + 1;
        
        vector<int> digits;

        while (digit)
        {
            int divider = pow(10 , (digit - 1));
            digits.push_back((i / divider) % 10);
            digit--;
        }

        for(int j = 1 ; j < digits.size() - 1 ; ++j){
            if (digits[j] > digits[j - 1] && digits[j] > digits[j + 1] || digits[j] < digits[j - 1] && digits[j] < digits[j + 1])
            {
                waviness++;
            }
        }

        // cout << digits[0] << endl;
        // cout << digits[1] << endl;
        // cout << digits[2] << endl;
    }

    return waviness;

}


int main(){
    int num1 = 4848 , num2 = 4848;
    cout << totalWaviness(num1 , num2);

    return 0;
}