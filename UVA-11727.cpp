#include <bits/stdc++.h>
#define MAXN 10005
#define MOD 998244353
#define lowbit(x) ((x) & (-x))
#define D 300
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int n, i=1;
    cin >> n;
    
    while(n--){
    	int x[3];
    	cin >> x[0] >> x[1] >> x[2];
    	sort(x, x+3);
    	
    	cout << "Case " << i << ": " << x[1] << '\n';
    	i++;
    }

    return 0;
}