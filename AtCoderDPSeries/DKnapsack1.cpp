#include<bits/stdc++.h>
#define ll long long 

struct items{
    ll w, v;
};
void solve(){
    int n, W;
    std::cin>> n>>W;

    std::vector<items> vec(n);

    for(int i = 0; i < n; ++i){
        std::cin>>vec[i].w>>vec[i].v;
    }
    std::vector<ll> dp(W+1); // caching, initially set to 0s so dp[0] = 0 base is set

    for(ll i = 0; i < n; ++i){
        for(ll w = W; w >= vec[i].w; w--){
            dp[w] = std::max(dp[w], vec[i].v + dp[w - vec[i].w]);
        }
    }
    std::cout<<dp.back()<<"\n";
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // soln here 
    solve();
    
    return 0;
}

