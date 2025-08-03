#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

unsigned long long countPaths(int m, int n)
{
	vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));
	for(int i=0; i<=m; i++) dp[i][0]=1;
	for(int j=0; j<=n; j++) dp[0][j]=1;
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	return dp[m][n];
}

int main()
{
	int m, n;
	cout<<"Enter size od grid (mxn) (1<=m,n<=100): ";
	cin>>m>>n;
	auto start = high_resolution_clock::now();
	unsigned long long result = countPaths(m, n);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout<<"Possible ways from start to end: "<<result<<endl;
	cout<<"Duration: "<<duration.count()<<" microseconds."<<endl;
}
