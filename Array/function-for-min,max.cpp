#include <bits/stdc++.h>
using namespace std;

pair<int, int> fun(int a[], int n)
{
	int i, l = a[0], s = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > l)
			l = a[i];
		if (a[i] < s)
			s = a[i];
	}
	return (make_pair(l, s));
}

int main()
{
	int i, n;
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++)
		cin >> a[i];

	pair<int, int> ans = fun(a, n);

	cout << ans.first << endl;
	cout << ans.second << endl;

	return 0;
}