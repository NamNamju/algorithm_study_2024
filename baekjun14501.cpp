#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n;
	
	cin >> n;
	vector<pair<int, int>> numbers(n);
	
	for (int i = 0; i < n; i++) {
        cin >> numbers[i].first >> numbers[i].second;
    }
	
	// 망한 코드 - 왜? => 건너뛰고 상담하는게 더 큰 값을 가져올 수도 있다는 것을 생각하지 못함.

	
	// for (int i = n-1; i > 0 ;i--) {
	// if (n - i < numbers[i].first) {
	// 		numbers.pop_back();
	// 	}
	// }

	
	// vector<int> sum(numbers.size(), 0);
	
	// for (int i = 0; i< numbers.size(); i++) {
	// 	for (int j = i; j < numbers.size(); j+=numbers[j].first) {
	// 		sum[i] += numbers[j].second;
	// 	}
	// }
	
	// auto max_it = max_element(sum.begin(), sum.end());
	
	// cout << *max_it;
	
	
	// 정답 코드 - 차라리 각 날짜까지 최대 얼마를 벌 수 있는지 구하는 방법을 구현했다.
	
	vector<int> sum(n+1,0);
	int max_element = 0;
	
	
	for (int i = 0; i < n; i++) {
		for (int j = i + numbers[i].first; j < n+1 ; j++) {
		
			max_element = max(sum[j], sum[i] + numbers[i].second);
			sum[j] = max_element;
		}
		
	}
	
	cout << sum[n];
	
	
}
