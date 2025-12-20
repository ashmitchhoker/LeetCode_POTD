#include <bits/stdc++.h>
using namespace std;

vector<string> validateCoupons(vector<string> & code , vector<string> & businessLine , vector<bool> & isActive){

    int n = code.size();
    vector<pair<int , string>> validCoupons;
    vector<string> result;

    unordered_map<string , int> validBusiness;
    validBusiness["restaurant"] = 3;
    validBusiness["grocery"] = 1;
    validBusiness["pharmacy"] = 2;
    validBusiness["electronics"] = 0;

    
    unordered_map<char , int> validChar;
    validChar['_'] = 1;
    for (char i = 'a'; i <= 'z'; i++)
    {
        validChar[i] = 1;
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        validChar[i] = 1;
    }
    for (char i = '0'; i <= '9'; i++)
    {
        validChar[i] = 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        string currCode = code[i];
        if (currCode == "")
        {
            continue;
        }
        
        bool validCode = true;
        for (int i = 0; i < currCode.size(); i++)
        {
            if (!validChar.count(currCode[i])){
                validCode = false;
                break;
            }
        }

        if (!validCode || !validBusiness.count(businessLine[i]) || !isActive[i])
        {
            continue;
        }
        
        validCoupons.push_back({validBusiness[businessLine[i]] , currCode});
    }


    sort(validCoupons.begin() , validCoupons.end() , [](const pair<int , string> & A , const pair<int , string> & B){
        if (A.first != B.first) return A.first < B.first;
        return A.second < B.second;
    });

    for (auto & p : validCoupons)
    {
        result.push_back(p.second);
    }

    return result;
}

int main(){
    vector<string> code = {"SAVE20" , "" , "PHARMA5" , "SAVE@20"};
    vector<string> businessLine = {"restaurant" , "grocery" , "pharmacy" , "restaurant"};
    vector<bool> isActive = {true , true , true , true};

    vector<string> result = validateCoupons(code , businessLine , isActive);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}