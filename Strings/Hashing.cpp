
const int mod1 = 999999937, mod2 = 1e9 + 223;
const int base1 = 137, base2 = 149;

ll bigmod(ll b,ll p,ll m)
{
    b=b%m;
    if(p==0)
        return 1;
    ll ans=bigmod(b,p/2,m);
    ans=((ans%m)*(ans%m))%m;
    if(p & 1)
        return ((ans%m)*(b%m))%m;
    else
        return ans;

}

ll Hash(string s)
{
    ll h = 0;
    ll p = 1;
    for(int i=0; i<s.size(); i++)
    {
        h = h + ((s[i] - 'a' + 1)*p) % mod;
        h %= mod;
        p = (p*base1) % mod;
    }
    return h;
}

pair< int,int >pw[N];
void pre()
{
    pw[0] = {1,1}; // any base ^ 0 = 1;
    for(int i=1; i<N; i++)
    {
        pw[i].ff = 1LL * pw[i-1].ff * base1 % mod1;
        pw[i].sc = 1LL * pw[i-1].sc * base2 % mod2;
    }
}
struct Hashing
{
    int n;
    string s; /// 0-indexed
    vector<pair<int,int>> hs; /// 1-indexed
    Hashing() {}
    Hashing(string _s)
    {
        n = _s.size();
        s = _s;
        hs.pb({0,0});
        for(int i=0; i<n; i++)
        {
            pair<int,int> p;
            p.ff = ((1LL*hs[i].ff*base1) + s[i] % mod1) % mod1;
            p.sc = ((1LL*hs[i].sc*base2) + s[i] % mod2) % mod2;
            hs.pb(p);
        }
    }
    pair<int,int> get_hash(int l,int r)
    {
        assert(l >= 1 && l <= r && r <= n);
        pair<int,int> ans;
        ans.ff = ((hs[r].ff - (1LL*hs[l-1].ff*pw[r-l+1].ff) % mod1) % mod1 + mod1) % mod1;
        ans.sc = ((hs[r].sc - (1LL*hs[l-1].sc*pw[r-l+1].sc) % mod2) % mod2 + mod2) % mod2;
        return ans;
    }
    pair<int,int> get_hash()
    {
        return get_hash(1,n);
    }
};
/// check palindrome -> prefix hash, suffix hash
/// Longest common substring -> binary search
/// smallest period of a string -> S = "abcdabcdabcd" here abcd is the period of S.
///         prefix hash, suffix hash if i is period then "i must divide n" and "check prefix[n-i] and suffix[i+1]"
/// Similar trees - ( digit * base ^ p + (CHILD1_hash + CHILD2_hash ...) )% mod
///                 digit -> subtree size , p = level. base and mod can be any.
int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
    pre();
    /// Problem - Find the number of times B occurs as a substring of A. for T test cases.
    int t,_=0;
    scc(t)
    while(++_ <= t)
    {
        string a,b;
        cin >> a >> b;

        Hashing a1(a);
        Hashing b1(b);
        pii d = b1.get_hash();

        int ans = 0;
        for(int i=1; i+b.size()-1<=a.size(); i++)
            if(a1.get_hash(i,i+b.size()-1) == d) ans++;

        printf("Case %d: %d\n",_,ans);
    }

    return 0;
}
