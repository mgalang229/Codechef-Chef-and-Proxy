#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		double d;
		string s;
		cin >> d >> s;
		int proxy = 0;
		int flag = 0;
		// count the number of present days
		int count_number_of_p = count(s.begin(), s.end(), 'P');
		// calculate the current percentage
		int percentage = (count_number_of_p / d) * 100;
		if (percentage >= 75) {
			// check if current percentage is already 75%
			cout << proxy << '\n';
			continue;
		}
		// start in the 3rd day and end the loop in the d - 2 days
		for (int i = 2; i < d - 2; i++) {
			// check if Chef is present within the previous 2 days AND within the following 2 days
			if((s[i - 1] == 'P' || s[i - 2] == 'P') && (s[i + 1] == 'P' || s[i + 2] == 'P') && s[i] == 'A') {
				// if chef is present then increment the number of present days
				count_number_of_p++;
				// increment the number of proxy
				proxy++;
				// update the current percentage
				percentage = (count_number_of_p / d) * 100;
				if (percentage >= 75) {
					// break the loop if the percentage is already at least 75%
					flag = 1;
					cout << proxy;
					break;
				}
			}
		}
		// if flag is still 0 at this point, then print -1 because 75% is not achieved
		if (flag == 0) {
			cout << -1;
		}
		cout << '\n';
	}
}
