#include<bits/stdc++.h>
#define ll long long

struct Activity{
    int a, b, c;
};

void solve(){
    int n;
    std::cin>>n;

    std::vector<Activity> v(n);
    for(int i = 0; i < n; ++i){
        std::cin>> v[i].a>> v[i].b>> v[i].c;
    }
    ll dp[n][3];

    // base case
    dp[0][0] = v[0].a;
    dp[0][1] = v[0].b;
    dp[0][2] = v[0].c;

    for(int i = 1; i < n; ++i){
        dp[i][0] = v[i].a + std::max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i].b + std::max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i].c + std::max(dp[i - 1][0], dp[i - 1][1]);
    }

    std::cout<<std::max({dp[n - 1][0],dp[n - 1][1],dp[n - 1][2]})<<"\n";

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // soln here 
    solve();
    
    return 0;
}
/*LT 746, 198, 213, 276, 256*/