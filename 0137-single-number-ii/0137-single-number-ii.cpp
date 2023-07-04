class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
            int ans = 0;
            for (int i = 0; i < 32; i++)
            {
                int cnt = 0;
                for (auto x: nums)
                {
                    if (x &(1 << i))
                    {
                        cnt++;
                    }
                }
                if (cnt % 3)
                {
                    ans |= (1 << i);
                }
            }
            return ans;
           	// map<int, int> mp;
           	// for (auto x: nums)
           	// {
           	//     mp[x]++;
           	// }
           	// for (auto x: mp)
           	// {
           	//     if (x.second == 1)
           	//     {
           	//         return x.first;
           	//     }
           	// }
           	// return -1;
        }
};