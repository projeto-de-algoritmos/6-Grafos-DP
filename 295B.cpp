#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second

using namespace std;
using vi=vector<int>;
using pii=pair<int, int>;
using ull=unsigned long long;

long g[501][501];
long dist[501][501];
const int INF = 1e5+7;

void solve(int n, vector<int> & to_remove, vector<ull> & ans)
{
	bool is_deleted[n+1] = {false};
	for (int k = 1; k <= n; k++)
	{
		int curr = to_remove[k];
		is_deleted[curr] = true;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][curr] + dist[curr][j]);
				if (is_deleted[i] && is_deleted[j])
					ans[k] += dist[i][j];
			}
	}

	for (int i = n; i >= 1; i--)
		cout << ans[i] << " ";

	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> g[i][j];	
			dist[i][j] = g[i][j];
		}

	vector<int> to_remove(n+1);
	vector<ull> ans(n+1);
	for (int i = n; i >= 1; i--)
	{
		cin >> to_remove[i];
	}
	
	solve(n, to_remove, ans);
	return 0;
}
