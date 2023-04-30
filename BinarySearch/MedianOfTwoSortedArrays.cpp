class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        while (i < m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        sort(ans.begin(), ans.end());
        // while(i<m&&j<n)
        // {
        //     if(nums1[i]<nums2[j])
        //     {
        //         ans.push_back(nums1[i]);
        //         i++;
        //     }
        //     if(nums1[i]>nums2[j])
        //     {
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        //       if(nums1[i]==nums2[j])
        //     {   ans.push_back(nums1[i]);
        //         ans.push_back(nums2[j]);
        //         i++;
        //         j++;
        //     }
        // }
        // if(m>n)
        // {    int k=n;
        //     while(k<m)
        //     {

        //         ans.push_back(nums1[k]);
        //         k++;
        //     }

        // }

        if (ans.size() % 2 == 0)
        {
            int a = (ans.size() / 2) - 1;
            double x = (ans[ans.size() / 2] + ans[a]) / 2.0;
            return x;
        }
        else
        {
            return ans[ans.size() / 2];
        }
    }
};