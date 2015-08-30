/*
solution with hashtable, reduce the hashtable size by removing duplicate

inspired by https://leetcode.com/discuss/12358/my-c-solution-using-hashtable; 

I push non-duplicate pair into mp from back to front, so when checking front to back won't miss answers. 

Consider the case [0,0,0,0] . 1step mp[0] = < <2,3> >, and this combine 2step <0,1> as the final result.
*/
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int n = nums.size();
        if(n < 4) return  res;
        sort(nums.begin(),nums.end());
        unordered_map<int, vector<pair<int, int>> > mp;
        // 1step first push non-duplicate pair, back to front
        for(int i =n-1; i >0; i--){
            if(i<n-1 && nums[i]==nums[i+1]) continue;
            for(int j = i - 1; j >=0; j--){
                if((j<i-1) && nums[j]==nums[j+1]) continue;
                mp[nums[i]+nums[j]].push_back(make_pair(j,i));
            }
        }

        //2step check from front to back
        for(int i = 0; i < n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i + 1; j < n; j++){
                if((j>i+1) && nums[j]==nums[j-1]) continue;
                int tar2 = target-nums[i]-nums[j];
                if(mp.find(tar2)!=mp.end()){
                   for(auto item : mp[tar2]){
                        int k = (item).first, l = (item).second;
                        if(k>j){
                            vector<int> vi = {nums[i],nums[j],nums[k],nums[l]};
                            res.push_back(vi);
                        }
                    } 
                }
            }
        }

        return res;
    }
