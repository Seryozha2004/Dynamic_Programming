#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long fibonacci_memo(int n, vector<long long>& memo)
{
	if(n<=1) return n;
	if(memo[n]!=-1) return memo[n];
	memo[n] = fibonacci_memo(n-1, memo) + fibonacci_memo(n-2, memo);
	return memo[n];
}

long long fibonacci_tab(int n)
{
	if(n<=1) return n;
	vector<long long> dp(n+1);
	dp[0]=0;
	dp[1]=1;
	for(int i=2; i<=n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main()
{
	int n;
	cout<<"Enter n (0<=n<=90): ";
	cin>>n;
	vector<long long> memo(n+1, -1);
	auto start_memo = high_resolution_clock::now();
	long long result_memo = fibonacci_memo(n, memo);
	auto end_memo = high_resolution_clock::now();
	auto duration_memo = duration_cast<microseconds>(end_memo - start_memo);
	cout<<n<<"th Fibonacci number: "<<result_memo<<endl;
	cout<<"Memorization duration: "<<duration_memo.count()<<" microseconds."<<endl<<endl;
	
	auto start_tab = high_resolution_clock::now();
	long long result_tab = fibonacci_tab(n);
	auto end_tab = high_resolution_clock::now();
	auto duration_tab = duration_cast<microseconds>(end_tab - start_tab);
	cout<<n<<"th Fibonacci number: "<<result_tab<<endl;
	cout<<"Tabulation duration: "<<duration_tab.count()<<" microseconds. "<<endl;
	return 0;
}
