#include <iostream>
#include <queue>
#define MAX 500001
using namespace std;
int cnt = 0;
typedef struct {
	int brown;
	int depth;
	int cony;
}game;
queue<game> q;
int main()
{
	int C, B;
	bool visit[MAX] = { false };
	game a;
	cin >> B >> C;
	a.brown = B; a.cony = C; a.depth = 0;
	q.push(a);

	int ans = 987654321;

	while (!q.empty())
	{
		int cony = q.front().cony;
		int brown = q.front().brown;
		int depth = q.front().depth;
		printf("cony : %d brown : %d\ depth : %d\n", cony, brown, depth);
		if (brown == cony) {
			if(ans>depth)
				ans = depth; 
			break;
		}
		q.pop();
		game a;
		cnt++;
		//visit[brown] = true;
		if (brown * 2 < MAX && !visit[brown * 2]) {
			a.brown = brown * 2; a.cony = cony + depth + 1; a.depth = depth + 1;
			q.push(a);
		}
		if (brown - 1 >= 0 && !visit[brown - 1]) {
			a.brown = brown - 1; a.cony = cony + depth + 1; a.depth = depth + 1;
			q.push(a);
		}
		if (brown + 1 < MAX && !visit[brown + 1]) {
			a.brown = brown + 1; a.cony = cony + depth + 1; a.depth = depth + 1;
			q.push(a);
		}


	}
	if (ans == 987654321)
		ans = -1;
	cout << ans << endl;

	return 0;
}