#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

#define MAXN 1000000

int a[MAXN+1];

void solve(int n) {
    stack<int> s;
    
    int result = INT_MIN, cur;
    for (int i = 0; i < n; ++ i) {
       while (!s.empty() && s.top() >= a[i]) {
          cur = INT_MAX;  
          int tmp = s.top(); s.pop();
          if (tmp < cur) {
              cur = tmp;
              result = max(result, cur ^ a[i]);
          }   
       }
       if (!s.empty()) result = max(result, a[i] ^ s.top());
       s.push(a[i]);
    }
 
    printf("%d\n", result);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++ i) scanf("%ld", &a[i]);

    solve(N);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
