#include<iostream>
#include<string>

using namespace std;

void func(string s1, string s2) {
	int i = 0, j;
	
	if (s1.size() > s2.size()) {
		swap(s1, s2);
	}


	

	int count = 0;
	int p1 = 0, q1 = 0;
	int p2 = 0, q2 = 0;
	while (i < s1.size()) {
		int sum = 0;

		for (j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				p1 = i;
				break;
			}
		}
		
		while (i < s1.size() && j < s2.size()) {
			if (i + 1 == s1.size() || j + 1 == s2.size()) {
				q1 = i + 1;
				break;
			}
			if (s1[i + 1] == s2[j + 1]) {
				i++;
				j++;
				sum++;
				q1 = i;
			}
			else {
				
				break;
			}
		}
		
		if (sum > count) {
			count = sum;
			p2 = p1;
			q2 = q1;
		}
		
		
		i++;
	}
	if (count == 0) {
		cout << 0 << endl;
	}
	else {
		cout << count + 1 << endl;
	}
	
	while (p2 < q2) {
		cout << s1[p2];
		p2++;
	}
	if (p2 == q2) {
		return;
	}
	
}



int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		func(s1, s2);
		cout << endl;
	}


	//cin >> s1 >> s2;
	//func(s1, s2);
	return 0;
}


