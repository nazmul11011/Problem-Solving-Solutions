#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        string word;
        cin >> word;
        size_t size = word.size();
        if (size > 10)
        {
            cout << word[0] << size - 2 << word[size - 1] << '\n';
        }
        else
            cout << word << '\n';
    }
}