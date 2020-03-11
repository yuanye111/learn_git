#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    std::vector<int> Arr;
    int rob(vector<int>& nums)
    {
       vector<int> val = nums;//(nums.size()-1,-1);
      if(nums.size() == 0)
          return 0;
      if(nums.size() == 1)
          return nums[0];
       val[1] = (nums[0] > nums[1] ? nums[0] : nums[1]);
       for(int i = 2;i < nums.size();i++)
       {
          if(val[i-1] > val[i-2] + nums[i])
	      val[i] = val[i-1];
	    else
	      val[i] = val[i-2] + nums[i];
       }
       return val[nums.size()-1];
    }
 
    int SubRob(vector<int> p,int start,int end)
    {
    	if(start == end)
         return p[start];
        else if(start + 1 == end)
            return (p[start] > p[end] ? p[start] : p[end]);
        else if(end - start == 2)
        {
            if(p[start] + p[end] > p[start + 1])
            {
                return p[start] + p[end];
            }
            else
               return p[start + 1];
        }
        else
        {
            int j,k;
            j = p[start] + SubRob(p,start+2,end);
            k = p[start + 1] + SubRob(p,start+3,end);
            return (j > k ? j : k);
        }
    }
    int rob(vector<int> nums)
    {
    	if(nums.size() == 0)
    		return 0;
        SubRob(nums,0,nums.size()-1);
    }

int main()
{
	Solution sol;
    int max;
	std::vector<int> v = {2,7,9,3,1};
	max = sol.rob(v);
	printf("max:%d\n",max);
}
