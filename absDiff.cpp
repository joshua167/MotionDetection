#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <cstdlib>

typedef ap_axis<32,1,1,1> AXI_VAL;
typedef int coef_t;
typedef int acc_t;
#define N 100 //921600

void absDiff (AXI_VAL *output, AXI_VAL* input) {
	#pragma HLS INTERFACE axis register both port=input
	#pragma HLS INTERFACE axis register both port=output
	#pragma HLS INTERFACE ap_ctrl_none port=return


	int img1[N];
	int img2[N];
	int outArr[N];

	for (int i=0;i<N/2;i++) {
		img1[i] = input->data;
	}
	for (int i=0;i<N/2;i++) {
		img2[i] = input->data;
	}

	for (int i = 0; i < N/2; i++) {
		outArr[i] = abs(img1[i] - img2[i]);
	}
	for (int j=0;j<=N/2;j++) {
	  output->data = outArr[j];
	  output-> keep = input->keep;
	  output-> strb = input->strb;
	  output->last = input->last;
	  output->dest = input->dest;
	  output->id = input->id;
	  output->user = input->user;
	}
}
