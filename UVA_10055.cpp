#include <bits/stdc++.h>
#define MAXN 10005
#define MOD 998244353
#define lowbit(x) ((x) & (-x))
#define D 300
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    long long int a, b;
    while(scanf("%lld %lld", &a,&b)==2)
    if(a>b){
            printf("%lld\n", a-b);
    }
else
    printf("%lld\n", b-a);
}