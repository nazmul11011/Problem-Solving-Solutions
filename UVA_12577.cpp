#include <bits/stdc++.h>
#define MAXN 10005
#define MOD 998244353
#define lowbit(x) ((x) & (-x))
#define D 300
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    string hajj;
    
    int x=0, i=1;
    
    while(x!=1){
    	cin >> hajj;
    	if(hajj=="Hajj") cout << "Case " << i << ": Hajj-e-Akbar" << '\n';
    	else if(hajj=="Umrah") cout << "Case " << i << ": Hajj-e-Asghar" << '\n';
    	else return 0;
    	i++;
    }

    return 0;
}