#include <bits/stdc++.h>
#ifndef use_ios11
#define use_ios11
using namespace std;
#define log(a) cerr << "\033[32m[DEBUG] " << #a << '=' << (a) << " @ line " << __LINE__ << "\033[0m" << endl
typedef long long ll;
#define pb push_back
typedef pair<int, int> pii;

#define mem(p) memset(&p, 0, sizeof(p))
typedef pair<long long, long long> pll;
#define ir(x) \
    int x;    \
    yin >> x
#define foor(action, actionx2, actionx4, width)         \
    do                                                  \
    {                                                   \
        unsigned long __width = (unsigned long)(width); \
        unsigned long __increment = __width >> 2;       \
        for (; __increment > 0; __increment--)          \
        {                                               \
            actionx4;                                   \
        }                                               \
        switch (__width & 3)                            \
        {                                               \
        case 2:                                         \
            actionx2;                                   \
            break;                                      \
        case 3:                                         \
            actionx2;                                   \
        case 1:                                         \
            action;                                     \
            break;                                      \
        }                                               \
    } while (0)
struct ins
{
    int ans;
    ins()
    {
        ans = 1;
    }
#define endl '\n'
    void read()
    {
    }
    void read1(char &s)
    {
        char c = getchar();
        for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
            ;
        s = c;
        if (c == EOF)
            ans = 0;
    }
    void read1(string &s)
    {
        s = "";
        char c = getchar();
        for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
            ;
        for (; isprint(c) && c != ' ' && c != '\n' && c != '\t'; c = getchar())
            s += c;
        if (c == EOF)
            ans = 0;
    }
    void read1(char *s)
    {
        char c = getchar();
        int tt = 0;
        for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
            ;
        for (; isprint(c) && c != ' ' && c != '\n' && c != '\t'; c = getchar())
            s[tt++] = c;
        s[tt] = '\0';
        if (c == EOF)
            ans = 0;
    }

    template <typename T>
    void read1(T &n)
    {
        T x = 0;
        int f = 1;
        char c = getchar();
        for (; !isdigit(c); c = getchar())
        {
            if (c == '-')
                f = -1;
            if (c == EOF)
            {
                ans = 0;
                return;
            }
        }
        for (; isdigit(c); c = getchar())
            x = x * 10 + c - 48;
        n = x * f;
        if (c == EOF)
            ans = 0;
        if (c != '.')
            return;
        T l = 0.1;
        while ((c = getchar()) <= '9' && c >= '0')
            x = x + (c & 15) * l, l *= 0.1;
        n = x * f;
        if (c == EOF)
            ans = 0;
    }
    void write() {}
    void write1(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
            putchar(s[i]);
    }
    void write1(const char *s)
    {
        int n = strlen(s);
        for (int i = 0; i < n; i++)
            putchar(s[i]);
    }
    void write1(char *s)
    {
        int n = strlen(s);
        for (int i = 0; i < n; i++)
            putchar(s[i]);
    }

    void write1(char s)
    {
        putchar(s);
    }
    void write1(float s, int x = 6)
    {
        char y[10001];
        sprintf(y, "%%.%df", x);
        printf(y, s);
    }
    void write1(double s, int x = 6)
    {
        char y[10001];
        sprintf(y, "%%.%dlf", x);
        printf(y, s);
    }
    void write1(long double s, int x = 6)
    {
        char y[10001];
        sprintf(y, "%%.%dLf", x);
        printf(y, s);
    }
    template <typename T>
    void write1(T n)
    {
        if (n < 0)
            n = -n, putchar('-');
        if (n > 9)
            write1(n / 10);
        putchar('0' + n % 10);
    }
    friend ins operator>>(ins x, char *n);
    template <typename T>
    friend ins operator>>(ins x, T &n);
    template <typename T>
    friend ins operator<<(ins x, T n);
    operator bool()
    {
        return ans;
    }
};

ins operator>>(ins x, char *n)
{
    if (!x.ans)
        return x;
    x.read1(n);
    return x;
}

template <typename T>
ins operator>>(ins x, T &n)
{
    if (!x.ans)
        return x;
    x.read1(n);
    return x;
}
template <typename T>
ins operator<<(ins x, T n)
{
    x.write1(n);
    return x;
}
ins yin;
ins yout;
#endif
const int N = 2e5 + 10;
char ch[N];
ll n, l, r, t[N][27];
vector<ll> sum[N];
string st[N];
vector<char> ans;
vector<int> v[27];
int bel[N][26];
void dfs(int x, char ch, ll l, ll r)
{
    x = *lower_bound(v[ch - 'a' + 1].begin(), v[ch - 'a' + 1].end(), x);
    if (x == n + 1 || sum[x].back() == 1 && r == 1)
    {
        ans.push_back(bel[x][ch - 'a']);
        return;
    }
    ll s = 0;
    int ll = lower_bound(sum[x].begin(), sum[x].end(), l) - sum[x].begin();
    for (int i = ll; i <= st[x].size(); i++)
    {
        if (sum[x][i - 1] + 1 > r)
            break;
        dfs(x + 1, st[x][i - 1], max(l, sum[x][i - 1] + 1) - sum[x][i - 1], min(r, sum[x][i]) - sum[x][i - 1]);
    }
}
signed main()
{
    yin >> l >> r >> n;
    for (int i = 1; i <= n; i++)
        yin >> ch[i] >> st[i];
    for (int i = 1; i <= 26; i++)
        t[n + 1][i] = 1;
    for (int i = 0; i < 26; i++)
        bel[n + 1][i] = i + 'a';
    for (int i = n; i >= 1; i--)
    {
        memcpy(bel[i], bel[i + 1], sizeof(bel[i]));
        if (st[i].size() == 1)
        {
            bel[i][ch[i] - 'a'] = bel[i + 1][st[i][0] - 'a'];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= 26; j++)
            if (ch[i] - 'a' + 1 != j)
                t[i][j] = t[i + 1][j];
            else
                for (char k : st[i])
                    t[i][j] = min((ll)1e18, t[i][j] + t[i + 1][k - 'a' + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        v[ch[i] - 'a' + 1].push_back(i);
        sum[i].push_back(0);
        for (int j = 0; j < st[i].size(); j++)
            sum[i].push_back(min((ll)1e18, sum[i].back() + t[i + 1][st[i][j] - 'a' + 1]));
    }
    for (int i = 1; i <= 26; i++)
        v[i].push_back(n + 1);
    dfs(1, 'a', l, r);
    for (auto x : ans)
        cout << x;
    cout << endl;
    assert(ans.size() == r - l + 1);
    return 0;
}