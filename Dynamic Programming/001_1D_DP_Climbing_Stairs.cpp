#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MAXX LLONG_MAX
#define endl '\n'
#define int long long int
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vss;


// User function Template for C++
class Solution {
    
    public:
        int max_product_of_edges_in_path(int n, vector<vector<int>> &edges) {
            
            int m = edges.size();

            vector<pair<int, int>> adj[n+1];
            for (int i=0;i<edges.size();++i) {
                adj[edges[i][0]].push_back( { edges[i][1], edges[i][2] } );
            }

            priority_queue<pair<int, int>, vector<pii>, greater<pii> > pq;
            pq.push({1, 1});

            vector<int> dist(n+1, -1);
            dist[0] = dist[1] = 1;

            while (!pq.empty()) {

                pair<int, int> data = pq.top();
                pq.pop();

                int mul = data.first;
                int node = data.second;
                if (dist[node] > mul) {
                    continue;
                }

                for (auto it : adj[node]) {

                    int nextNode = it.first;
                    int nextDistance = it.second;

                    if (nextDistance * mul > dist[nextNode]) {
                        dist[nextNode] = nextDistance * mul;
                        pq.push( { dist[nextNode], nextNode } );
                    }
                }
            }

            return dist[n];

        }
};

void call() {

    int n = 5, m = 5;
    cin>>n>>m;
    vector<vector<int>> edges;
    
    for (int i=0;i<m;++i) {
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({ a, b, c });
    }
 
    // Function call
    cout << Solution().max_product_of_edges_in_path(n, edges) << endl;
    return ;
}

int32_t main() {
    void sync_files_and_os();
    sync_files_and_os();
    int t=1;
    cin >> t;
    while (t--) {
        call();
    }
    return 0;
}

void sync_files_and_os() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../error.txt", "w", stderr);
        freopen("../output.txt", "w", stdout);
    #endif
}


