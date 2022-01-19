#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check[50];
int answer = 100;

bool checkDiff(string a, string b)
{
	int diff = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			diff++;
		}
	}
	if (diff == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DFS(string begin, string target, vector<string> words, bool * check, int time)
{
	//cout << begin << endl;

	for (int i = 0; i < words.size(); i++)
	{
		if (checkDiff(begin, words[i])) // 다른 단어가 1개면
		{
			if (target == words[i])
			{
				cout << "answer : " << answer << endl;
				if (answer > time + 1)
				{
					answer = time + 1;
					cout << "target : " << target << ",  answer : " << answer << endl;
					return;
				}
			}
			if (check[i] == false)
			{
				check[i] = true;
				cout << "if: "<< begin << ",  time : " << time << endl;
				DFS(words[i], target, words, check, time + 1);
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) {

	int tmp = 0;
	bool check[50] = { false };

	DFS(begin, target, words, check, 0);

	if (answer == 100)
		return 0;
	else
		return answer;
}

int main()
{
	vector<string> words;
	string begin;
	string target;
	int n;

	cin >> begin;
	cin >> target;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string stemp;

		cin >> stemp;
		words.push_back(stemp);
	}

	cout << solution(begin, target, words) << endl;

	return 0;
}
