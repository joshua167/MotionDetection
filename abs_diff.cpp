#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

void abs_diff(int a[100], int b[100], int c[100]);

#define N 100

void abs_diff(int a[100], int b[100], int c[100]) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=a
#pragma HLS INTERFACE s_axilite port=b
#pragma HLS INTERFACE s_axilite port=c

	for (int i=0; i<N; i++) {
		c[i] = abs(a[i] - b[i]);
	}
}
