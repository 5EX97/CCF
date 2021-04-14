#include<bits/stdc++.h>
using namespace std;

struct node {
	unsigned long long x, y, z;
	node():x(0), y(0), z(0) {};
};


class Solution {
public:
	vector<node> vec;
	int n, m;
	

	void play() {
		cin >> n >> m;
		unsigned long long s,a,b,c,k,l,r;   //unsigned long long能过80%     long long只能过70%
		unsigned long long temp;
		vec.resize(n+1);
		while (m--) {
			cin >> s;
			switch (s)
			{
			case 1: {
				cin >> l >> r >> a >> b >> c;
				for (int i = l; i <= r; i++) {
					vec[i].x += a;
					vec[i].y += b;
					vec[i].z += c;
				}
				break;
			}
			case 2: {
				cin >> l >> r >> k;
				for (int i = l; i <= r; i++) {
					vec[i].x = (vec[i].x * (k % 1000000007) % 1000000007);
					vec[i].y = (vec[i].y * (k % 1000000007) % 1000000007);
					vec[i].z = (vec[i].z * (k % 1000000007) % 1000000007);
				}
				break;
			}
			case 3: {
				cin >> l >> r;
				for (int i = l; i <= r; i++) {
					temp = vec[i].x;
					vec[i].x = vec[i].y;
					vec[i].y = vec[i].z;
					vec[i].z = temp;
				}
				break;
			}
			case 4: {
				cin >> l >> r;
				unsigned long long X = 0, Y = 0, Z = 0;
				for (int i = l; i <= r; i++) {
					X += vec[i].x;
					Y += vec[i].y;
					Z += vec[i].z;
				}
				X %= 1000000007;
				Y %= 1000000007;
				Z %= 1000000007;
				cout << (X*X%1000000007+Y*Y% 1000000007 +Z*Z% 1000000007)%1000000007 << endl;
				break;
			}
			default:
				break;
			}
		}
	}
};
int main()
{
	Solution a;
	a.play();
	return 0;
}