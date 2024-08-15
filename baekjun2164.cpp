#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n;
	
	cin >> n;
	
	// 망한 코드 - 벡터는 시간 초과 남. erase와 push_back 때문.
	
	// vector<int> cards;
	
	// for (int i = 0; i < n; i++) {
	// 	cards.push_back(i+1);
	// }
	
	// while (cards.size() > 0) {
	// 	cards.push_back(cards[1]);
	// 	cards.erase(cards.begin(),cards.begin() + 2);
	// }
	
	// cout << cards[0];
	
	// 
	
	// 성공 코드 - Queue로 FIFO 이용
	
	queue<int> cards;

    for (int i = 1; i <= n; i++) {
        cards.push(i);
    }

    while (cards.size() > 1) {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();
	
	
}
