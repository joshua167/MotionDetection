#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <ap_int.h>

void binThreshold(ap_uint<8> img[91260], ap_uint<8> output[91260]) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=img
	#pragma HLS INTERFACE s_axilite port=output

  binThreshold_label7:for (int i = 0; i < 72; i++) {
    binThreshold_label6:for (int j = 0; j < 1280; j++) {
      output[i*1280 + j] = img[i*1280 + j] > 25 ? 255 : 0;
    }
  }
}
