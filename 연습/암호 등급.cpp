#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	vector<int> ind(4,0);
	string input;
	int level = 0;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z' && ind[0] == 0)
		{
			level++;
			ind[0] = 1;
		}
		else if (input[i] >= 'A' && input[i] <= 'Z' && ind[1] == 0)
		{
			level++;
			ind[1] = 1;
		}
		else if (input[i] >= '0' && input[i] <= '9' && ind[2] == 0)
		{
			level++;
			ind[2] = 1;
		}
		else if( !((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) && ind[3] == 0)
		{
			level++;
			ind[3] = 1;
		}
	}

	if (input.size() >= 10)
		level++;


	switch (level)
	{
	case 1: cout << "LEVEL1" << endl;
		break;
	case 2: cout << "LEVEL2" << endl;
		break;
	case 3: cout << "LEVEL3" << endl;
		break;
	case 4: cout << "LEVEL4" << endl;
		break;
	case 5: cout << "LEVEL5" << endl;
		break;
	default:
		break;
	}

	return 0;
}