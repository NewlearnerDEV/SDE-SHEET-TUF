class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        // brute -force
    //    for(int i=0;i<nums.size();i++) 
    //    {
    //        for(int j=0;j<nums.size();j++)
    //        {
    //            if(i!=j&&nums[i]+nums[j]==target)
    //            {
    //               res.push_back(i);
    //               res.push_back(j);
    //            }
    //        }
    //    }return res;
    map<int,int>mp;
    for(int i=0;i<nums.size();i++) 
    {
        if(mp.find(target-nums[i])!=mp.end())
        {
            res.push_back(i);
            res.push_back(mp[target-nums[i]]);
            break;
        }
        else
        {
            mp[nums[i]]=i;
        }
    }
    return res;
        
    }
};