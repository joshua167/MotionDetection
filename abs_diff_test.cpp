#include <stdio.h>
#include <math.h>

int main() {
	const int N = 100;
	int a[100];
	int b[100];
	int c[100];

	for (int i=0; i<N; i++) {
		a[i] = i;
		b[i] = N-i;
	}

	abs_diff(a, b, c);

	return 0;
}
