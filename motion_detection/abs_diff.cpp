#include <hls_stream.h>
#include <ap_axi_sdata.h>
typedef ap_axis<32,1,1,1> intS;
void divide6(intS* in, intS* out) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=in
#pragma HLS INTERFACE axis register both port=out
  for (int i = 0; i < 50; i++){
  out -> data = int(in->data % 6 == 0);
      out->keep = in->keep;
      out->strb = in->strb;
      out->user = in ->user;
      out->last = in->last;
      out->id = in->id;
      out->dest = in->dest;
} }


void abs_diff(intS* in1, intS* in2, intS* out) {
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis register both port=in
#pragma HLS INTERFACE axis register both port=out
  for (int i = 0; i < 100; i++){
	int[] a = in1[i];
	int[] b = in2[i];
	int[] output;
	for (int i = 0; i < 100; i++) {
		output[i] = a[i] - b[i];
	}
	out -> data = output;
}

