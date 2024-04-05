#include <cstdio>

int main() {
    int N;
    scanf("%d",&N);
    while(N--){
    int n,k;
    scanf("%d %d", &n, &k);
    int s_k = k / 2; 
    int result = k ^ s_k; 
    printf("%d\n", result);}
    return 0;
}