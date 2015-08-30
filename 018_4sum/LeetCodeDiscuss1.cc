/*
36ms C++ solution with 4th element reclusive search

Method similar to 3Sum Closest reclusive solution Use a reclusive search function with O(log n) for search of the 4th element
*/
    //search if target is within nums in range start to end 
    //used to search for the 4th element
    bool _search(int target, vector<int>& nums,int start,int end)
    {
        if (start<0) return false;
        if (start>end) return false;
        if(target <nums[start] || target > nums[end]) return false;
        if(start ==end) return (target ==nums[start]);
        int c = (start+end)/2;
        if(nums[c]>target){
            return _search(target,nums,start,c-1);
        }else if (nums[c] <target){
            return _search(target,nums,c+1,end);
        }
        return true;
    }

    void _fourSum(vector<int>& nums, int target,vector<int>&sumList, vector<vector<int>>& result,int start)
    {
        if(nums.size()==0) return;
        int elementLeft = 4 - sumList.size();


        //avoid unnecessary process, return if the target is too small or too large 
        if(target < nums[start]*elementLeft ||target>nums[nums.size()-1]*elementLeft) return;


        if(sumList.size()==3)
        {
            if(_search(target,nums,start,nums.size()-1))
            {
                sumList.push_back(target);
                result.push_back(sumList);
                sumList.pop_back();
                return;
            }
            return;
        }
        //a number bigger than the whole list
        int last = nums[nums.size()-1]+1;

        for (int i=start;i<nums.size();i++)
        {
            if(last ==nums[i])continue;
            last =nums[i];
            sumList.push_back(nums[i]);
            _fourSum(nums,target-nums[i],sumList,result,i+1);
            sumList.pop_back();
        };
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>  result;
        vector<int>  temp;
        sort(nums.begin(),nums.end());
        _fourSum(nums,target,temp,result,0);
        return result;
    }
