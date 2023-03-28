class Solution
{
public:
    int trap(vector<int> &height)
    {
        //----------------------------------T.L.E-----------------APPROACH-1
        // vector<int>prefix;
        // int n=height.size();
        // prefix.push_back(height[0]);
        // int k=height[0];
        // for(int i=1;i<n;i++)
        // {
        //    if(height[i]>k)
        //     {
        //       k=height[i];
        //       prefix.push_back(k);
        //    }
        //    else
        //    {
        //        prefix.push_back(k);
        //    }
        // }
        // vector<int>suffix;
        // int end=height[n-1];
        //     suffix.push_back(end);
        // for(int i=n-2;i>=0;i--)
        // {
        //     if(height[i]>end)
        //     {
        //         end=height[i];
        //         suffix.insert(suffix.begin()+0,end);
        //     }
        //     else
        //     {
        //         suffix.insert(suffix.begin()+0,end);
        //     }
        // }
        // // for(int i=0;i<n;i++)
        // // {
        // //     cout<<prefix[i]<<" "<<suffix[i]<<endl;
        // // }
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     ans=ans+min(suffix[i],prefix[i])-height[i];
        // }
        // return ans;
        int l = 0;
        int r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while (l < r)
        {
            if (height[l] <= height[r])
            {

                if (height[l] >= lmax)
                {
                    lmax = height[l];
                }
                else
                {
                    ans += lmax - height[l];
                }
                l++;
            }
            else
            {
                if (height[r] >= rmax)
                {
                    rmax = height[r];
                }
                else
                {
                    ans += rmax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};