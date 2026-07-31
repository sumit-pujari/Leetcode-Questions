class Solution {
public:

    struct cmp {
        bool operator()(pair<int, string> &a, pair<int, string> &b) {
            if (a.first == b.first)
                return a.second < b.second;   // lexicographically smaller has higher priority
                return a.first > b.first;         // smaller frequency has higher priority
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>f;
        for(int i=0;i<words.size();i++){
            f[words[i]]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto i:f){
            string s=i.first;
            int freq=i.second;
            pair<int,string>curr={freq,s};
            pq.push(curr);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};