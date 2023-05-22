class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pri;
        for(auto i:nums) {
            mp[i]++;
        }
        for(auto & i:mp){
            pri.push({i.second,i.first});
            if(pri.size()>k) pri.pop();
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pri.top().second);
            pri.pop();
        }
        return ans;
    }
};