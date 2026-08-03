class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>f;
        unordered_map<char,int>free;
        for(char ch:tasks){
            f[ch]++;
            free[ch]=1;
        }
        
        priority_queue<pair<int,char>>pq;
        for(auto i:f){
            pq.push({i.second,i.first});
        }

        //int intervals=0;
        int seat=1;

        while(!pq.empty()){
            vector<pair<int,char>>pulled;
            while(!pq.empty()){
                pair<int,char>p=pq.top();
                pq.pop();

                int freq=p.first;
                char child=p.second;
                if(free[child]<=seat){
                    if(p.first>1){
                        pq.push({p.first-1,p.second});
                        free[p.second]=seat+n+1;
                    }
                    break;
                }
                else{
                    pulled.push_back(p);
                }
            }

            for(int i=0;i<pulled.size();i++){
                pq.push(pulled[i]);
            }
            seat++;
        }
        return seat-1;
    }
};