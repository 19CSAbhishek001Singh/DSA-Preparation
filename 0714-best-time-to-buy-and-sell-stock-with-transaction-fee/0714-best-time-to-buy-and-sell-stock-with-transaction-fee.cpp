class Solution {
public:
    long long dp[100001][2];
     int rec(int ind, int buy,int fee, vector<int> &prices){
        int n=prices.size(),profit=0;
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==0){
            profit+=max({
                -prices[ind]+rec(ind+1,1,fee,prices),
                0+rec(ind+1,0,fee,prices)
            });
        }
        if(buy==1){
            profit+=max({
                prices[ind]-fee+rec(ind+1,0,fee,prices),
                0+rec(ind+1,1,fee,prices)
            });
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
         memset(dp,-1,sizeof(dp));
        return rec(0,0,fee,prices);
    }
};