class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>f;
        for(char ch:s){
            f[ch]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto i:f){
            pq.push({i.second,i.first});
        }

        string result="";

        while(!pq.empty()){
            pair<int,char>p1=pq.top();
            pq.pop();
            if(result.empty() || result.back() != p1.second){
                result.push_back(p1.second);
                p1.first--;
                if(p1.first>0) pq.push(p1);
            }

            else{
                if(pq.empty()) return "";
                pair<int,char>p2=pq.top();
                pq.pop();
                result.push_back(p2.second);
                p2.first--;
                if(p2.first>0){
                    pq.push(p2);
                }
                pq.push(p1);
            }
        }
        return result;
    }
};