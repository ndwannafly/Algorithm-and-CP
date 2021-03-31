#include <bits/stdc++.h>
using namespace  std;
//  1 1 1 1
//  1 1 1 1

// 2 1 1 1
// 3 1 1 1

// 0 1 1 1
// 4 1 1 1

// 4 1 1 1
// 0 1 1 1

// 0 1 1 1
// 0 2 1 1

// 0 3 1 1
// 0 0 1 1

// 0 4 1 1
// 0 0 0 1
int main() {
    priority_queue<long> pq;
    pq.push(5);
    pq.push(10);
    cout<<pq.top();
}
