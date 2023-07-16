class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int offset=100000,n=nums.size();
        vector<int> freq(300002,0);
        for(int i=0;i<n;i++){
            int start=nums[i]-k;
            int end=nums[i]+k;
            freq[start+offset]++;
            freq[end+offset+1]--;
        }
        int ans=freq[0];
        for(int i=1;i<300002;i++){
            freq[i]+=freq[i-1];
            ans=max(ans,freq[i]);
        }
        return ans;
    }
};