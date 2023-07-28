#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define int long long int
#define deb(x) cout << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


int solve1(int ind) {

    if (ind == 0) return 1;
    if (ind == 1) return 1;

    return solve1(ind-1) + solve1(ind-2);
}


int solve2(int n, vector<int> &dp) {

    if(n == 0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = (solve2(n-1, dp) + solve2(n-2, dp)) % mod;
}

int solve3(int n) {

    int prev2 = 1;
    int prev = 1;
  
    for(int i=2; i<=n; i++){
        int cur_i = prev2+ prev;
        prev2 = prev;
        prev= cur_i;
    }

    return prev;
}

int findNumberOfStairs(int n) {

    // return solve1(n);
    
    // vi dp(n+1, -1);
    // return solve2(n, dp);

    return solve3(n);
}

void __call_func__() {
    
    int n = 0;
    cin >> n;

    deb(findNumberOfStairs(n));

}

int32_t main() {

    void __init_files_and_inputs__();
    __init_files_and_inputs__();

    int t=1;
    // for the number of test cases
    cin >> t;

    while (t--) {
        __call_func__();
    }

    return 0;
}

void __init_files_and_inputs__() {

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}