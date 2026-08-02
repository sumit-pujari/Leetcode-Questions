class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>projects;
        for(int i=0;i<profits.size();i++){
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());

        int i=0;
        int n=projects.size();
        priority_queue<int>pq;
        while (k--) {
            while (i < n) {
                if (projects[i].first > w) break;
                pq.push(projects[i].second);
                i++;
            }

            if (pq.empty())
                break;

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};