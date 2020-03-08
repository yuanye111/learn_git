class Solution {
public:
    std::vector<int> Arr;
	int FindCrossMaxArr(int start,int mid, int end)
	{
       int max_left,max_right;
       int left;
       int right;
       max_left = max_right = 0;
       for(int i = mid;i >= start;i--)
       {
           if(max_left + Arr[i] > max_left)
               {
               	 max_left = max_left + Arr[i];
                 left = i;
               }
       }

       for (int i = 0; i <= end; ++i)
       {
       	  if(max_right + Arr[i] > max_right)
       	  {
       	  	max_right = max_right + Arr[i];
       	  	right = i;
       	  }
       }

       return max_right + max_left;

	}
    int FindMaxSubArray(int start,int end)
    {
    	int mid;
    	int mid_max,left_max,right_max;
    	if(start == end)
    		return Arr[start];

        mid = start/2 + end/2;
        left_max = FindMaxSubArray(start,mid);
        right_max = FindMaxSubArray(mid+1,end);
        mid_max = FindCrossMaxArr(start,mid,end);

        if(left_max > right_max && left_max > mid_max)
        {
        	return  left_max;
        }
        else if(mid_max > right_max)
        	return mid_max;
        else
        	return right_max;
    }
    int maxSubArray(vector<int>& nums) {
          
    }
};