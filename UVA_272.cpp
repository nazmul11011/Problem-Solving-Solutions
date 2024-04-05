#include <bits/stdc++.h>
#define MAXN 10005
#define MOD 998244353
#define lowbit(x) ((x) & (-x))
#define D 300
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    char ch;
    int f=0;
    while(scanf("%c", &ch)==1){
    	if(ch=='"') {
    		if(f==0){
    			cout << "``";
    			f=1;
    		}else{
    			cout << "''";
    			f=0;
    		}
    	}else {
    		cout << ch;
    	}
    }

    return 0;
}