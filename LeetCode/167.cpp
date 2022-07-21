//167. Two Sum II - Input Array Is Sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int d = numbers.size() - 1;   
    int l = 0;
    vector<int> ans;
    while(l < d)
    {
        if(numbers[l] + numbers[d] == target)
        {
            ans.push_back(++l);
            ans.push_back(++d);
            break;
        }
        else if(numbers[l] + numbers[d] > target)
            d--;
        else l++;
    }
        return ans;
    }
};