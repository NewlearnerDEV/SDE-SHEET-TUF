class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int first=nums[0];
        int prod=1;
        bool zerofound=false;
        for(int i=0;i<n;i++)
        {   
            prod=prod*nums[i];
            if(nums[i]==0)
            {
                prod=1;
                zerofound=true;
                continue;
            }
            first=max(first,prod);

        }
      cout<<first;
      int last=nums[0];
      prod=1;
      for(int i=n-1;i>=0;i--)
      {
         prod=prod*nums[i];
         if(nums[i]==0)
         {
             prod=1;
             zerofound=true;
             continue;
         }
         last=max(last,prod);

      }
      int ans=0;
      if(zerofound==true)
      {
          ans=max(ans,max(last,first));
      }
      else
      {
          ans=max(last,first);
      }
      return ans;
    }
};