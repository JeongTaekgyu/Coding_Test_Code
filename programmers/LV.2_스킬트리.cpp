#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int cnt;
	int fail = 0;

	// i,k  : skill_trees[i][k]
	// j    : skill[j];
	// cnt  : skill[j] == skill_trees[i][j]
	// fail : ������ �ȸ��� �� 
	for (int i = 0; i < skill_trees.size(); i++)
	{
		cnt = 0;
		fail = 0;
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			for (int k = cnt; k < skill.size(); k++)	// k = cnt �� ������ �տ� skill ���� �˻��Ѱ� �� �˻��� �ʿ���
			{
				if (skill_trees[i][j] == skill[k])
				{
					if (k == cnt)
					{
						cnt++;	// �� ���� ������ �´��� üũ�� �ַ���
						break;
					}
					else {
						fail = 1;
						break;
					}
				}
			}
			if (fail)
				break;
		}
		if ( fail == 0 )
		{
			cout << skill_trees[i] << endl;
			answer++;
		}
	}

	return answer;
}
int main()
{
	string skill="CBD";
	vector<string> skill_trees;
	
	cout << skill << endl;
	cout << skill.size() << endl;

	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");

	for (int i = 0; i < skill_trees.size(); i++)
		cout << skill_trees[i] << endl;
	cout << skill_trees.size() << endl;
	// �� skill_trees(4); �̶� skill_trees; �ѰŶ� ����� �ٸ���?
	// skill_trees(4)�� 4ĭ ���͵ż� ��µǰ�
	// skill_trees; �� ���;��� ��µǳ�..
	// �� �� �� �ƾƾƾƾƾ�!!!! ���ʿ� vector<string> skill_trees(4); �� ���������� 
	// 4���� ������ ����ǰ� �� �Ŀ� push_back �����ϱ� 4���� ������ ��µ��� ����!!! 

	cout << endl << solution(skill, skill_trees) << endl;


	/*for(int i = 0; i < 3; i++)
		cin >> skill[i];

	for (int i = 0; i < 4; i++)
		getline(cin, skill_trees[i]);

	cout << endl;

	for (int i = 0; i < 3; i++)
		cout << skill[i] << endl;;

	for (int i = 0; i < 4; i++)
		cout << skill_trees[i] << endl;
		*/
}