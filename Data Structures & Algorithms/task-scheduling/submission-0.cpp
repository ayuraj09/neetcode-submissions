class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        vector<int> frq(26,0);
        for(int i=0;i<tasks.size();i++){
            frq[tasks[i]-'A']++;
        }

        for(int i=0;i<26;i++){
            if(frq[i]>0){
                pq.push({frq[i],i+'A'});
            }
        }
        int ans = 0;
        while(!pq.empty()){
            queue<pair<int,char>> q;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    auto it = pq.top();
                    pq.pop();
                    ans++;
                    it.first--;
                    if(it.first>0)
                        q.push(it);
                }else{
                    if (q.empty()) break;
                    ans+=(n-i+1);
                    break;
                }
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
