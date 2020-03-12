#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    std::vector<int> Arr;

	int FindCrossMaxArr(int start,int mid, int end)
	{
       int max_left,max_right;
       int sum = 0;
       
       max_left = Arr[mid];
       max_right = Arr[mid+1];
       for(int i = mid;i > start;i--)
       {
           sum = sum + Arr[i];

           if(sum > max_left)
               {
               	 max_left = sum;
               }
       }
       
       sum = 0;

       for (int i = mid+1; i < end; i++)
       {
       	  sum += Arr[i];

       	  if(sum > max_right)
       	  {
       	  	max_right = sum;
       	  }
       }

       return max_right + max_left;

	}

    int FindMaxSubArray(int start,int end)
    {
    	int mid;
    	int mid_max,left_max,right_max,max;
    	if(start == end)
    		return Arr[start];

        mid = start/2 + end/2;
        left_max = FindMaxSubArray(start,mid);
        right_max = FindMaxSubArray(mid+1,end);
        mid_max = FindCrossMaxArr(start,mid,end);

        if(left_max > right_max && left_max > mid_max)
        {
        	max = left_max;
        }
        else if(mid_max > right_max)
        	max = mid_max;
        else
        	max = right_max;
        
        
        return max;
    }

    int maxSubArray(vector<int>& nums) {
        Arr = nums;
       
        int max = FindMaxSubArray(0,nums.size()-1);
        
        return max;
    }
};

int main()
{
	Solution sol;
    int max;
	std::vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
	max = sol.maxSubArray(v);
	printf("max:%d\n",max);
}