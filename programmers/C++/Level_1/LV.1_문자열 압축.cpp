// ex) -> ababcdcdababcdcd 를 2ababcdcd 로 바꾸는게 아니라 그 길이인 9를 구하는 것이다.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = s.length();

	for (int i = 1; i <= s.length() / 2; i++)
	{	// 문자열의 절반까지만 검사하면 된다.
		int pos = 0;
		int len = s.length();

		while(1)
		{
			string unit = s.substr(pos, i); // pos 인덱스부터 i 길이만큼 가져온다.
			pos += i;

			if (pos >= s.length())
				break;

			int cnt = 0;
			while(1)
			{
				if (unit.compare(s.substr(pos, i)) == 0) { // 동일한 문자열 이라면
					cnt++;
					pos += i;
				}
				else {break;}
			}
			
			if (cnt > 0) { // 압축된게 있다면
				len -= i * cnt; // (문자열 길이 x 반복된 횟수)만큼 빼준다.
				
				if(cnt < 9)len += 1;
				else if (cnt < 99) len += 2;
				else if (cnt < 999) len += 3;
				else len += 4; // 한개의 문자로만 이루어진 길이가 1000인 문자열의 경우;
			}
		}
		answer = min(answer, len); // 제일 작은걸 답으로 한다.
	}

	return answer;
}

int main()
{
	string s;

	cin >> s;

	printf("%d\n", solution(s));

	return 0;
}