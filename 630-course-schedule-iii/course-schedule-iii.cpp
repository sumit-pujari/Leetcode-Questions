class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>&a ,const vector<int>&b){
            return a[1]<b[1];
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp());
        priority_queue<int>pq;

        int totaltime=0;
        int ans=0;

        for(auto course:courses){
            int duration=course[0];
            int lastday=course[1];
            
            totaltime+=duration;
            pq.push(duration);

            if(totaltime>lastday){
                int max=pq.top();
                pq.pop();
                totaltime-=max;
            }

        }
        return pq.size();
    }
};


// 100 200    200 1300   1000 1250    2000 3200
//0-.100   100              yes
//100+200  300  1300        yes
//300+1000 1300 1250        no
//300+2000 2300 3200        yes


//2 10     2 19     3 19    5 15    5 16    6 7    8 14    10 11
//0+2  2   2   yes
//2+2  4   19  yes
//2+3  5   19  yes
//5+5 10   15  yes
//10+5 15  16  yes
