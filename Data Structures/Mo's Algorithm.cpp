
#define scc(n) scanf("%d",&n);
#define sccc(n) scanf("%lld",&n);

typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int N = 2e5+9, mod = 1e9+9;

ll n, blocks = 490, q, sum;
ll a[N], ans[N];

struct Query
{
    int index,l,r;
    bool operator < (const Query &other) const {
        int K = l/blocks;
        int K_other = other.l/blocks;
        if(K == K_other)
            return r < other.r;
        return K < K_other;
    }
}qr[N];

void Add(int id)
{
    sum += a[id];
}

void Remove(int id)
{
    sum -= a[id];
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
//    srand(time(NULL));

    scc(n)
    scc(q)
    for(int i=1; i<=n; i++)
        scc(a[i])

    for(int i=1; i<=q; i++)
    {
        scc(qr[i].l)
        scc(qr[i].r)
        qr[i].index = i;
    }

    sort(qr+1,qr+q+1);

    int L = 1, R = 0;
    for(int i=1; i<=q; i++)
    {
        while(R < qr[i].r) Add(++R);
        while(L < qr[i].l) Remove(L++);
        while(R > qr[i].r) Remove(R--);
        while(L > qr[i].l) Add(--L);
        ans[qr[i].index] = sum;
    }

    for(int i=1; i<=q; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}
// Problem: https://cses.fi/problemset/task/1646
