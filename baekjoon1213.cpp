#include <bits/stdc++.h>

using namespace std;

int main() {
	string mystr;
	getline(cin, mystr);
	
	
	
	// 망한코드 - 전체 문자를 고려하지 않고 부분마다 고려하기 때문에 일관성이 떨어짐. 또한 정렬은 팰린드롬에서 그렇게 쓸데가 없음.
	
	// sort(mystr.begin(), mystr.end());
	
	// for (int i = 0; i < mystr.length(); ++i) {
	// 	string newStr = mystr.substr(0, i + 1);
	// 	// cout << newStr << '\n';
	// 	for (int j = 0; j <= i; j++) {
	// 		if (newStr[j] == newStr[newStr.length() - j - 1]) {
	// 			continue;
	// 		} else {
	// 			if (newStr.length() % 2 != 0) {
	// 				char changeStr = newStr[j];
	// 				mystr.erase(j, 1);
	// 				mystr.insert(newStr.length() / 2, 1, changeStr);
	// 			} else {
	// 				char changeStr = newStr[j];
	// 				mystr.erase(j, 1);
	// 				mystr.insert(newStr.length() / 2 - 1, 1, changeStr);
	// 			}
	// 		}
	// 	}
	// }
	
	// 성공 코드 - 각 문자 출현 횟수 세기, 왼쪽 오른쪽 나누어서 생각.
	
	vector<int> count(26, 0);
    for (char c : mystr) count[c - 'A']++;
    
    string left, middle;
	int odd_count = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
			odd_count++;
            middle = string(1, 'A' + i);  // 홀수인 문자 하나를 중간에 배치
            count[i]--;  // 이 문자를 하나 사용했으므로 카운트를 줄임
        }
        left += string(count[i] / 2, 'A' + i);
    }
	

    // 홀수 개의 문자가 두 개 이상인 경우 불가능
    if (odd_count > 1 || middle.length() > 1) {
        mystr= "I'm Sorry Hansoo";
    } else {
		
		string right = left;
		reverse(right.begin(), right.end());

		mystr = left + middle + right;
		
	}
	
	
	cout << mystr;
	
	
	
	return 0;
}
