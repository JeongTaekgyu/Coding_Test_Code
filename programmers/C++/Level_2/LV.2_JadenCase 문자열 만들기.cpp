#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int first = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			first = 0;
		}
		if ( (s[i] != ' ') && (first == 0) )
		{
			if( ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) )
				s[i] = toupper(s[i]);
			first = 1;
		}
		else if ( (s[i] >= 'A' && s[i] <= 'Z') && first == 1)
		{
			s[i] = tolower(s[i]);
		}
	}

	answer = s;

	return answer;
}
int main()
{
	string s;
	
	getline(cin, s);

	cout << solution(s) << endl;

	return 0;
}