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



class DisjointSet {

	vector<int> parent, rank;

	public:
		DisjointSet(int n) {
			// setting the ranks for all the vertices to 0 default
			rank.resize(n+1, 0);
			// setting the parent of node to itself, 1=1, 2=2, 3=3,....n=n
			parent.resize(n+1, 1e9);

			for (int i=1;i<=n;++i) {
				parent[i]=i;
			}
		}


		int findUltimateParent(int node) {
			if (node == parent[node]) {
				return node;
			}

			return parent[node] = findUltimateParent(parent[node]);
		}

		void unionByRank(int u, int v) {

			int ultimateParentOfU = findUltimateParent(u);
			int ultimateParentOfV = findUltimateParent(v);

			if (ultimateParentOfV == ultimateParentOfU) {
				return ;
			}
			if (rank[ultimateParentOfU] < rank[ultimateParentOfV]) {
				parent[ultimateParentOfU] = ultimateParentOfV;
			} else if (rank[ultimateParentOfV] < rank[ultimateParentOfU]) {
				parent[ultimateParentOfV] = ultimateParentOfU;
			} else {
				parent[ultimateParentOfV] = ultimateParentOfU;
				rank[ultimateParentOfU]++;
			}

		}
};

void call() {

	DisjointSet ds(7);

	ds.unionByRank(1, 2);
	ds.unionByRank(2, 3);
	ds.unionByRank(4, 5);
	ds.unionByRank(6, 7);
	ds.unionByRank(5, 6);

	if (ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same" << endl;
	} else {
		cout << "Not Same" << endl;
	}

	ds.unionByRank(3, 7);

	if (ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same" << endl;
	} else {
		cout << "Not Same" << endl;
	}

}

int32_t main() {
    void sync_files_and_os();
    sync_files_and_os();
    int t;
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
