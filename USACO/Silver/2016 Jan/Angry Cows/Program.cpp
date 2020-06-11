#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

int N, K, R;
vector <int> A, B;
int main()
{
	ifstream fin;
	fin.open("angry.in");
	fin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int temp;
		fin >> temp;
		A.push_back(temp);
		B.push_back(temp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int time;
	int high = B[N - 1];
	int low = 1;
	int ans;

	while ((high - low) > 1)
	{
		time = 0;
		for(int i = 0; i < A.size(); i++) B.push_back(A[i]);
		if ((high + low) % 2 == 0) R = (high + low) / 2;
		else R = (high + low + 1) / 2;
		int range = 2 * R;

		while (B.size() > 0)
		{
			int num = B[0];
			B.erase(B.begin());
			time++;
			while (B[0] <= num + range && B.size() > 0) B.erase(B.begin());
		}
		if (time > K) low = R;
		else
		{
			ans = R;
			high = R;
		}
	}
	ofstream fout;
	fout.open("angry.out");
	fout << ans;
	return 0;
}
