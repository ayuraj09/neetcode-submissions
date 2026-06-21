class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mp;   
public:
    TimeMap() {
    }
    string getVal(int t, vector<pair<int,string>> a){
        int l = 0;
        int r = a.size()-1;
        int ansIdx = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(a[mid].first<=t){
                ansIdx = mid;
                l=mid+1;
            }else r=mid-1;
        }
        if(ansIdx!=-1) return a[ansIdx].second;
        return "";
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &it = mp[key];
        return getVal(timestamp,it);
    }
};
