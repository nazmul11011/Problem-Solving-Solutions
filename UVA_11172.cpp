#include <bits/stdc++.h>
#define MAXN 10005
#define MOD 998244353
#define lowbit(x) ((x) & (-x))
#define D 300
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--){
    	int a,b;
    	cin >> a >> b;
    	if(a>b) cout << ">" << '\n';
    	else if(a<b) cout << "<" << '\n';
    	else cout << "=" << '\n';
    }

    return 0;
}