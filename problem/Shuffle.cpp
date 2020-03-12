#include <stdio.h>
#include <vector>
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
class Solution {
public:
  std::vector<int> InitArr;
  
	Solution(vector<int>& nums) {
        InitArr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return InitArr;
    }
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ShuffleArr = InitArr;
        for(int i = ShuffleArr.size() - 1; i >= 0 ; i--)
        {
          srand((unsigned)time(NULL));
          int pos = rand()%(i+1);
          int tmp = ShuffleArr[i];
          ShuffleArr[i] = ShuffleArr[pos];
          ShuffleArr[pos] = tmp;
        }

        return ShuffleArr;
    }
};

int main()
{
       for(int i=0;i<10;i++)
             printf("%d\n",rand()%100);
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */