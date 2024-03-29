#include <bits/stdc++.h>
using namespace std;

vector<int> v;
unordered_map<pair<int, int>, int> memo;
int dfs(int l, int r){
    if(r-l <= 1) return max(v[l], v[r]);

    if(memo.count({l, r})) return memo[{l, r}];

    int ll = max(v[l], v[l+1]) + dfs(l+2, r);
    int lr = max(v[l], v[r]) + dfs(l+1, r-1);
    int rr = max(v[r], v[r-1]) + dfs(l, r-2);
    return memo[{l, r}] = max({ll, rr, lr});
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n; cin >> n;
    v.resize(n+1);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    int ans = dfs(0, n-1);
    cout << ans;
}
