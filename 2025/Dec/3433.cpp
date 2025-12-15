#include <bits/stdc++.h>
using namespace std;


void userMentioned(vector<int>& result , string mentions){
    int n = mentions.size();
    int right = n - 1;

    int len = 0;
    while (right >= 0)
    {
        if(mentions[right] == 'd'){
            int id = stoi(mentions.substr(right + 1 , len));
            right -= 3;
            len = 1;

            result[id]++;
            continue;
        }

        len++;
        right--;
    }
    
}
vector<int> countMentions(int numberOfUsers , vector<vector<string>> & events){
    // events 0 is either MESSAGE or OFFLINE
    // 1 is timestamp , 2 is mention string prefix used is id followed by number  and " "
    // offline called only when user is online
    // in 2 HERE means all online mentions and ALL means all online + offline
    sort(events.begin() , events.end() , [](const vector<string>& a , const vector<string>& b){
        int timeA = stoi(a[1]);
        int timeB = stoi(b[1]);

        if(timeA != timeB) return timeA < timeB;
        return a[0] == "OFFLINE" && b[0] == "MESSAGE";
    });
    vector<int> result(numberOfUsers , 0);

    unordered_map<int , int> off_map; // id , timestamp
    // queue<vector<int>> off_queue; // id , timestamp used for here mentions

    int adder = 0;
    for(int i = 0 ; i < events.size() ; i++){
        vector<string> event = events[i];

        int timestamp = stoi(event[1]);

        string mentions = event[2];

        if(event[0] == "OFFLINE"){
            int user = stoi(mentions);
            off_map[user] = timestamp + 60;
            // off_queue.push({user , timestamp});
            continue;
        }

        if(mentions == "ALL"){
            adder++;
            continue;
        }

        if (mentions == "HERE")
        {
            adder++;
            for(auto const& pair : off_map){
                int id = pair.first;
                int ontime = pair.second;
                if (ontime > timestamp)
                {
                    result[id]--;
                }
                
            }
        }
        userMentioned(result , mentions);
    }


    for(int i = 0 ; i < numberOfUsers ; i++){
        result[i] += adder;
    }
    return result;
}

int main(){
    int n = 2;
    vector<vector<string>> events = {
        {"OFFLINE", "10", "0"},
        {"MESSAGE", "12", "HERE"}
    };

    countMentions(n , events);
    return 0;
}