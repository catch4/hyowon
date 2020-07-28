#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int indegree[32002];

int main() {

	int n, m;
	queue <int> queue;
	vector <int> v[32002];

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		indegree[b]++;
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!indegree[i])
			queue.push(i);
	}

	while (!queue.empty())
	{
		int temp = queue.front();
		queue.pop();

		printf("%d ", temp);

		for (int i = 0; i < v[temp].size(); i++) {
			indegree[v[temp][i]]--;
			
			if (!indegree[v[temp][i]])
				queue.push(v[temp][i]);
		}
	}

	return 0;
}