#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;

    std::vector<int> stones(n);
    for(int i = 0; i < n; ++i){
        std::cin>> stones[i];
    }
    // main operation
    std::vector<int> dp(n);

    // base case
    dp[0] = 0; // no cost at first stone
     // from stone 1, one can jump only one step
    dp[1] = std::abs(stones[1] - stones[0]); // can only jump one step

    for(int i = 2; i < n; ++i){
        dp[i] = std::min(
            dp[i - 1] + std::abs(stones[i] - stones[i - 1]),
            dp[i - 2] + std::abs(stones[i] - stones[i - 2])
            );
    }
    std::cout<<dp.back()<<"\n";
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // soln here 
    /*SOLVE IT*/
    solve();
    
    return 0;
}
/*
dp[i] = min cost to reach stone i
Take min of possible previous jumps + their cost
*/