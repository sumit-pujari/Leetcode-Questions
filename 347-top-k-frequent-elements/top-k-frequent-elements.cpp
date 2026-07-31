class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }

        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        for(auto i:f){
            int element=i.first;
            int freq=i.second;
            pair<int,int>curr={freq,element};
            //pq.push(i.second,i.first);
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first<pq.top().first) continue;
            pq.pop();
            pq.push(curr);
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};