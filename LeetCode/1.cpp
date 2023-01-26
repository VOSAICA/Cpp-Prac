#include <map>
#include <vector>

class Solution
{
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = m.find(target - nums[i]);
            if (it != m.end())
            {
                return {it->second, i};
            }
            m.insert({nums[i], i});
        }
        return {};
    }
};
