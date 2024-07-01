#include <stdio.h>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> answer;
    
    //Finding starting position
    int low=0, high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            if(mid-1>=0 && nums[mid-1]==target)
                high=mid-1;
            else if(mid==0)
            {
                answer.push_back(mid);
                break;
            }
            else if(mid-1>=0 && nums[mid-1]<target)
            {
                answer.push_back(mid);
                break;
            }
        }
        else if(nums[mid]>target)
            high=mid-1;
        else
            low=mid+1;
    }
    if(answer.empty()) answer.push_back(-1);
        //Finding ending position
    low=0, high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            if(mid+1<nums.size() && nums[mid+1]==target)
                low=mid+1;
            else if(mid==nums.size()-1)
            {
                answer.push_back(mid);
                break;
            }
            else if(mid+1<nums.size() && nums[mid+1]>target)
            {
                answer.push_back(mid);
                break;
            }
        }
        else if(nums[mid]>target)
            high=mid-1;
        else
            low=mid+1;
    }
    if(answer.size()==1) answer.push_back(-1);
    
    return answer;
}
int main()
{
    vector<int> v={5,7,7,8,8,10};
    vector<int> res=searchRange(v, 8);
    for(int i=0;i<res.size();i++)
        printf("%d ",res[i]);
    return 0;
}