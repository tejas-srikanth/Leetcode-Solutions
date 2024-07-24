class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> us;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (us.find(key) == us.end()){
            us[key] = {{timestamp, value}};
        } else {
            us[key].push_back({timestamp, value});
        }
    }
    
    string get(string key, int timestamp) {
        if (us.find(key) == us.end()){
            return "";
        }
        vector<pair<int, string>>& theVector = us[key];
        int start = 0;
        int end = theVector.size() - 1;
        int n = theVector.size();
        if (theVector[end].first <= timestamp){
            return theVector[end].second;
        }
        while (start <= end){
            int mid = (start + end) / 2;
            pair<int, string> p = theVector[mid];
            if (p.first < timestamp){
                if (mid < n - 1 && theVector[mid+1].first > timestamp){
                    return p.second;
                }
                start = mid+1;
            }

            else if (p.first > timestamp){
                end = mid-1;
            }

            else {
                return p.second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */