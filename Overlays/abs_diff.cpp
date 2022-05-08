#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <ap_int.h>

void abs_diff(ap_uint<8> a[92160], ap_uint<8> b[92160], ap_uint<8> c[92160]);

#define N 92160 //408960 //921600 //2073600

void abs_diff(ap_uint<8> a[92160], ap_uint<8> b[92160], ap_uint<8> c[92160]) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=a
	#pragma HLS INTERFACE s_axilite port=b
	#pragma HLS INTERFACE s_axilite port=c

	abs_diff_label3:for (int i = 0; i < N; i++) {
		c[i] = abs(a[i] - b[i]);
	}
}
