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
	vector<int> numbers(n);
	
	for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
	
	sort(numbers.begin(), numbers.end());
	
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		sum+= numbers[i] * (n - i);
	}
	
	cout << sum;

}
