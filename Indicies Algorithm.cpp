#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        if(nums.size() < 2 || nums.size() > 104) {
            return indices;
        }

        unordered_map<int, int> hashMap;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < -109 || nums[i] > 109) {
                return indices;
            }
            hashMap[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++) {
            if(target < -109 || target > 109) {
                return indices;
            }
            int complement = target - nums[i];
            if(hashMap.count(complement) && hashMap[complement] != i) {
                indices.push_back(i);
                indices.push_back(hashMap[complement]);
            }
        }
        return indices;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 4};
    int targetValue;
    cout<<"Enter the target value: ";
    cin>>targetValue;
    if(targetValue<-109 || targetValue>109){
      cout<<"Entered target value should be between -109 and 109";
      return 0;
    }
    if(nums.size() < 2 || nums.size() > 104) {
      cout<<"The length of array should be between 2 and 104";
      return 0;
    }
    for(int i=0; i<nums.size(); i++) {
            if(nums[i] < -109 || nums[i] > 109) {
                cout<<"The elements of array should be between -109 and 109";
                return 0;
            }
    }
    vector<int> indices = solution.twoSum(nums, targetValue);
    cout << indices[0] << " " << indices[1];
    return 0;
}
