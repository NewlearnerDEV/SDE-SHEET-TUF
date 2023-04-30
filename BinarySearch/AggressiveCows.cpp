// spoj problem
#include<iostream>
using namespace std;
int a[]={10,3,46,23};
int n=4;
int k=3;// no of cows
bool canPlace(int dist)
{
    int cur=a[0];int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]-cur>=dist)
        {
            cnt++;
            cur=a[i];
        }
        if(cnt==k)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int low=1;
    int high=a[n-1]-a[0];
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(canPlace(mid))
        {
              res=mid;
              low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<res<<endl;
    return 0;
}