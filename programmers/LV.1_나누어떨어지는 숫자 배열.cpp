#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	int i;

	for (i = 0; i < arr.size(); i++)
	{
		if (arr[i] % divisor == 0)
		{
			answer.push_back(arr[i]);
		}
	}

	if (answer.size() == 0)
	{
		answer.push_back(-1);
	}
	else {
		sort(answer.begin(), answer.end());
	}

	return answer;
}
int main()
{
	vector<int> arr;
	int n;
	int divisor;

	std::cin >> n;
	std::cin >> divisor;

	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	for (int i = 0; i < solution(arr, divisor).size(); i++)
	{
		std::cout << solution(arr, divisor)[i] << std::endl;
	}

	return 0;
}