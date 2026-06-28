#include <bits/stdc++.h>
using namespace std;

int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
    // sort
    // start from lst 1 , > 5 ,
    int ans = INT_MAX;
    int eplt = INT_MAX;

    for (int i = 0; i < lst.size(); i++)
    {
        eplt = min(eplt , lst[i] + ld[i]);
    }

    for (int i = 0; i < wst.size(); i++)
    {
        if (wst[i] >= eplt)
        {
            ans = min(ans , wst[i] + wd[i]);
        }
    }
    
    
    int epwt = INT_MAX;

    for (int i = 0; i < wst.size(); i++)
    {
        epwt = min(eplt , wst[i] + wd[i]);
    }


    for (int i = 0; i < lst.size(); i++)
    {
        if (lst[i] >= epwt)
        {
            ans = min(ans , lst[i] + ld[i]);
        }
    }

    return ans;
}



int main(){
    vector<int> lst = {2 , 8};
    vector<int> ld = {4 , 1};
    vector<int> wst = {6};
    vector<int> wd = {3};

    cout << earliestFinishTime(lst , ld , wst , wd);

    return 0;
}