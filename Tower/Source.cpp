#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	int a, b, c ;
	int ma[100005] = {};
	map<int,vector<int> > v;
	cin >> a >> b >> c;
	for (int i = 0; i < c; i++) {
		int d, e;
		cin >> d >> e;
		v[min(d - 1,e-1)].push_back(max(d-1,e-1));
	}
	ma[0] = a + 1;
	int ans = 1;
	for (int i = 0; i < b; i++) {
		if (ma[i]) {
			ans = i + 1;
			for (int j = 0; j < v[i].size(); j++) {
				if (ma[v[i][j]]< ma[i] - 1)
					ma[v[i][j]] = ma[i] - 1;
			}
		}
	}
	printf("%d", ans);
}