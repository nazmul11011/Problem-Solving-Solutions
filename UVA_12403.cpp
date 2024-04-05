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
    n=n+1;

    string donate;
    int total_money = 0;

    while (n--) {
        getline(cin, donate);
        if (donate == "report") {
            cout << total_money << '\n';
        } else {
            int i = 0;
            while (donate[i] != '\0') {
                if (donate[i] >= '0' && donate[i] <= '9') {
                    break;
                }
                i++;
            }
			
			int num=0;
            while (donate[i] >= '0' && donate[i] <= '9') {
                num = num * 10 + (donate[i] - '0');
                i++;
            }
            total_money+=num;
            //cout << num << '\n';
            
        }
    }

    return 0;
}