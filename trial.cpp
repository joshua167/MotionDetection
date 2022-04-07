#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <cstdlib>

typedef ap_axis<32,1,1,1> AXI_VAL;
typedef int data_t;
typedef int coef_t;
typedef int acc_t;
#define N 100
void abs_diff (AXI_VAL *y, coef_t c[N],AXI_VAL* img1,AXI_VAL* img2) {
#pragma HLS INTERFACE m_axi depth=11 port=c
/*#pragma HLS RESOURCE variable=c core=RAM_1P_BRAM
#pragma HLS INTERFACE bram port=c*/
#pragma HLS INTERFACE axis register both port=img1
#pragma HLS INTERFACE axis register both port=img2
#pragma HLS INTERFACE axis register both port=y
#pragma HLS INTERFACE ap_ctrl_none port=return
 //static data_t output[N];

for (int i=0;i<=N;i++) {
#pragma HLS UNROLL
  y->data = abs(img1->data - img2->data);
  y-> keep = img1->keep;
  y-> strb = img1->strb;
  y->last = img1->last;
  y->dest = img1->dest;
  y->id = img1->id;
  y->user = img1->user;
}
}
