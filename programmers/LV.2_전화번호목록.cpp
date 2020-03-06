#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for (int i = 0; i < phone_book.size(); i++)
	{
		for (int j = 0; j < phone_book.size(); j++)
		{
			if (phone_book[i].size() <= phone_book[j].size() && i != j)
			{
				// phone_book[j]�� 0��° �ε������� phone_book[i].size()���� ��ŭ  phone_book[i]�� ������ ���Ѵ�.
				if (phone_book[j].compare(0, phone_book[i].size(), phone_book[i]) == 0)
				{	// if ( phone_book[j].substr(0,phone_book[i].size()) == phone_book[i] ) �� ������...
					// ������ substr �� ����ð��� �� ������ �Ⱦ���.(�Ľ��� ���� �Ⱦ��ٰ� �Ѵ�.)
					answer = false;	// ������ ������ �� �̻� for�� ���� �ʰ� false�� ��ȯ�Ѵ�.
					return answer;
				}
			}
		}
	}

	return answer;
}
int main()
{
	vector<string> phone_book
		= {"119",
			"97674223",
			"1195524421"};

	//cout << solution(phone_book) << endl;

	// ����� compare�� ���Ǵ�
	// b1.comapre(n��° �ε�������, a1�� ũ��, a1)
	// �� '0' �̸� ����
	/*
	string a1 = "123";
	string b1 = "123456";

	if (b1.substr(0, 3) == "123")
	{
		cout << "1 ����" << endl;
	}
	cout << "a1.size() : " << a1.size() << endl;
	if (b1.compare(0, a1.size(), a1) == 0)
	{
		cout << "2 ����" << endl;
	}*/

	return 0;
}