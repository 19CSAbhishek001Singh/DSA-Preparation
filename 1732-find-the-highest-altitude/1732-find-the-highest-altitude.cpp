class Solution
{
    public:
        int largestAltitude(vector<int> &gain)
        {
            int curr = 0;
            int maxi = INT_MIN;
            for (int i = 0; i < gain.size(); i++)
            {
                curr += gain[i];
                maxi = max(curr, maxi);
            }
            return max(maxi, 0);
        }
};