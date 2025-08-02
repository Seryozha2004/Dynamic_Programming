#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

unsigned long long factorial_recursive(int n, vector<unsigned long long>& memo)
{
	if(n==0 || n==1) return 1;
	if(memo[n]!=0) return memo[n];
	memo[n] = n * factorial_recursive(n-1, memo);
	return memo[n];
}

unsigned long long factorial_iterative(int n)
{
	unsigned long long result = 1;
	if(n==0 || n==1) return 1;
	for(int i=2; i<=n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int n;
	cout<<"Enter n (0<=n<=20): ";
	cin>>n;
	vector<unsigned long long> memo(n+1, 0);
	auto start_recursive = high_resolution_clock::now();
	unsigned long long result_recursive = factorial_recursive(n, memo);
	auto end_recursive = high_resolution_clock::now();
	auto duration_recursive = duration_cast<nanoseconds>(end_recursive - start_recursive);
	cout<<"Factorial of "<<n<<": "<<result_recursive<<endl;
	cout<<"Recursive duration: "<<duration_recursive.count()<<" nanoseconds. "<<endl<<endl;

	auto start_iterative = high_resolution_clock::now();
	unsigned long long result_iterative = factorial_iterative(n);
	auto end_iterative = high_resolution_clock::now();
	auto duration_iterative = duration_cast<nanoseconds>(end_iterative - start_iterative);
	cout<<"Factorial of "<<n<<": "<<result_iterative<<endl;
	cout<<"Iterative duration: "<<duration_iterative.count()<<" nanoseconds. "<<endl;
	return 0;
}
