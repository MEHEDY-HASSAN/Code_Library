//https://codeforces.com/blog/entry/43230

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define yes         puts("Yes");
#define no          puts("No");
#define ff          first
#define sc          second
#define inf         999999999
#define pi          3.14159265358979323846264
#define printv(v)   for(auto x:v)cout<<x<<' ';cout<<endl;
#define takev(v)    for(auto &x:v)cin>>x;
inline  int         random(int a=1,int b=10)
{
    return a+rand()%(b-a+1);
}
typedef long long ll;
inline ll           lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
//#define see(x)  cout<<endl<<#x<<" : "<<(x)<<endl;
#define see(args...) \
{ \
    string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);\
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout<< *it << " = " << a <<",\n"[++it==istream_iterator<string>()];
    err(it, args...);
}
#define scc(n) scanf("%d",&n);
#define sccc(n) scanf("%lld",&n);

typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const int MAXN = 40005;
const int MAXM = 100005;
const int LN = 19;

int N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
// LVL is level
// DP is used to find LCA
int BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN], ANS[MAXM];
// BL[i] is the block number of the i'th element based on cur
// ID is the array after DFS traversal. ekahne sobai 2 bar kore thakbe
int d[MAXN], l[MAXN], r[MAXN];
// d used to compress
// Start time -> l and End time -> r
bool VIS[MAXN];
vector < int > adjList[MAXN];

struct query{
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];

// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur;
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}

// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}

inline void check(int x, int& res){
	// If (x) occurs twice, then don't consider it's value
	if ( (VIS[x]) and (--VAL[A[x]] == 0) ) res--;
	else if ( (!VIS[x]) and (VAL[A[x]]++ == 0) ) res++;
	VIS[x] ^= 1;
}

void compute(){

	// Perform standard Mo's Algorithm
	int curL = Q[0].l, curR = Q[0].l - 1, res = 0;

	for (int i = 0; i < M; i++){

		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);

		int u = ID[curL], v = ID[curR];

		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);

		ANS[Q[i].id] = res;

		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
	}

	for (int i = 0; i < M; i++) printf("%d\n", ANS[i]);
}


int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));

    int u, v, x;

	while (scanf("%d %d", &N, &M) != EOF){

		// Cleanup
		cur = 0;
		memset(VIS, 0, sizeof(VIS));
		memset(VAL, 0, sizeof(VAL));
		for (int i = 1; i <= N; i++) adjList[i].clear();

		// Inputting Values
		for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
		memcpy(d + 1, A + 1, sizeof(int) * N);

		// Compressing Coordinates
		sort(d + 1, d + N + 1);
		K = unique(d + 1, d + N + 1) - d - 1;
		for (int i = 1; i <= N; i++) A[i] = lower_bound(d + 1, d + K + 1, A[i]) - d;

		// Inputting Tree
		for (int i = 1; i < N; i++){
			scanf("%d %d", &u, &v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		int Size = sqrt(cur);

		for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / Size + 1;

		for (int i = 0; i < M; i++){
			scanf("%d %d", &u, &v);
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
		}

		sort(Q, Q + M);
		compute();
	}

    return 0;
}
// Problem : https://www.spoj.com/problems/COT2/
