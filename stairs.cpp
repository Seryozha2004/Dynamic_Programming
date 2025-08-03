#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int stairsRecursive(int n, vector<int>& memo)
{
	if(n<=2) return n;
	if(memo[n] != -1) return memo[n];
	memo[n] = stairsRecursive(n-1, memo) + stairsRecursive(n-2, memo);
	return memo[n];
}

int stairsIterative(int n)
{
	if(n<=2) return n;
	vector<int> dp(n+1);
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main()
{
	int n;
	cout<<"Enter the number of stairs (1<=n<=45): ";
	cin>>n;
	vector<int> memo(n+1, -1);
	auto start_recursive = high_resolution_clock::now();
	int ways_recursive = stairsRecursive(n, memo);
	auto end_recursive = high_resolution_clock::now();
	auto duration_recursive = duration_cast<microseconds>(end_recursive - start_recursive);
	cout<<"Possible ways: "<<ways_recursive<<endl;
	cout<<"Recursive duration: "<<duration_recursive.count()<<" microseconds."<<endl<<endl;

	auto start_iterative = high_resolution_clock::now();
	int ways_iterative = stairsIterative(n);
	auto end_iterative = high_resolution_clock::now();
	auto duration_iterative = duration_cast<microseconds>(end_iterative - start_iterative);
	cout<<"Possible ways: "<<ways_iterative<<endl;
	cout<<"Iterative duration: "<<duration_iterative.count()<<" microseconds."<<endl;
	return 0;
}
