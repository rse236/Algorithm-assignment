#include<stdio.h>
#include<math.h>

#define inf 90000

void travel(int n, int W[][5], int P[][100], int* minlength) {
	int i, j, k;
	int D[n + 1][31];
	int set;
	int count = 0;
	int cnt = 0;
	int minj;
	int res;


	for (i = 2; i <= n; i++)
		D[i][0] = W[i][1];

	for (k = 1; k <= n - 2; k++)
		for (set = 4; set <= 30; set += 4, count = 0) {
			for (int m = 2; m <= n; m++) {
				if (set&(1 << m))
					count++;
			}
			if (count != k)
				continue;

			for (i = 2; i <= n; i++) {
				if (set & (1 << i))
					continue;
				for (j = 2; j <= n; j++) {
					if (set & (1 << j)) {
						if (cnt == 0 || cnt > W[i][j] + D[j][set - (1 << j)]) {
							cnt = W[i][j] + D[j][set - (1 << j)];
							P[i][set] = j;
						}
					}
				}
				D[i][set] = cnt;
				cnt = 0;

			}
		}
	set = 28;
	for (j = 2, cnt = 0; j <= n; j++) {
		if (cnt == 0 || cnt > W[1][j] + D[j][set - (1 << j)]) {
			cnt = W[1][j] + D[j][set - (1 << j)];
			P[1][set] = j;
		}
	}
	D[1][set] = cnt;
	*minlength = D[1][30 - 2];
}
