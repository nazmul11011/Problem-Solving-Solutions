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
    	int a;
    	cin >> a;
    	a=a*567;
    	a=a/9;
    	a=a+7492;
    	a=a*235;
    	a=a/47;
    	a=a-498;
    	int remainder=(a%100)/10;
    	if(remainder<0) remainder=remainder*(-1);
    	cout << remainder << '\n';
    }

    return 0;
}