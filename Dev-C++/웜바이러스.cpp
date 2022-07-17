#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main()
{
  int N, M, num1, num2, i, j, node, cnt = 0;
  scanf("%d %d", &N, &M);
  queue<int> q;
  set<int> s;
  int arr[N+1][N+1];

  for(i = 0; i <= N; i++) {
    for (j = 0; j <= N; j++) {
      arr[i][j] = 0;
    }
  }

  for (i = 0; i < M; i++) {
    scanf("%d %d", &num1, &num2);
    arr[num1][num2] = 1;
    arr[num2][num1] = 1;
  }

  set<int>::iterator it;
  q.push(1);
  s.insert(1);

  while(!q.empty()) {
    node = q.front();
    q.pop();
    for (i = 1; i <= N; i++) {
      if (arr[node][i] == 1) {
        it = s.find(i);
        if (it == s.end()) {
          cnt++;
          q.push(i);
          s.insert(i);
          arr[node][i] = 0;
        }
        else {
          arr[node][i] = 0;
        }
      }
      else continue;
    }
  }

  printf("%d\n", cnt);

  return 0;
}
