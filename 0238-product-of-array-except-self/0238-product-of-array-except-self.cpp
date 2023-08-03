class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int product=1;
        vector<int> ans(n,0),left(n,0),right(n,0);
          left[0]=1;
        right[n-1]=1;
        for(int i=0;i<n;i++){
            left[i]=product;
            product*=nums[i];
        }
        product=1;
         for(int i=n-1;i>=0;i--){
            right[i]=product;
            product*=nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};