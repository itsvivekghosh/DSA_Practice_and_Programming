#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define int long long int
#define print(x) cout << x << endl
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


int solve1(int ind, vi &arr, vi &dp) {

    if (ind == 0)
        return 0;

    int jumpOne = solve1(ind-1, arr, dp) + abs(arr[ind] - arr[ind-1]);

    int jumpTwo = 0;
    if (ind > 1) {
        jumpTwo = solve1(ind-2, arr, dp) + abs(arr[ind] - arr[ind-2]);
    }

    return min(jumpOne, jumpTwo);
}

int solve2(vi &height, int n) {

    vector<int> dp(n,-1);
    dp[0]=0;

    for(int ind=1;ind<n;ind++){
        int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
    }

    return dp[n-1];
}

void __call_func__() {
    
    int n;
    cin>>n;

    vi arr(n, 0);
    for (auto &a: arr) cin >> a;


    // vi dp (n+1, -1);
    // print(solve1(n-1, arr, dp));


    print(solve2(arr, n));

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
