#include <bits/stdc++.h>
using namespace std;

int sumFourDivisors(vector<int> & nums){
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int curr = nums[i];
        int foundD = 0;

        int tempSum = 1 + curr;

        for (int divisors = 2; divisors * divisors <= curr ; divisors++)
        {
            if (curr % divisors == 0)
            {
                if (foundD > 0)
                {
                    tempSum = 0;
                    foundD = 0;
                    break;
                }
                else{
                    foundD = divisors;
                    tempSum += divisors + (curr / divisors);
                }
            }
        }

        if (foundD > 0 && foundD != curr / foundD)
        {
            sum += tempSum;
        }
        
    }
    

    return sum;
}


int main(){
    vector<int> nums = {1 , 2 , 3 , 4 , 5};

    cout << sumFourDivisors(nums);

    return 0;
}