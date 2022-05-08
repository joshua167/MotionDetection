#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <ap_int.h>

void gaussian(ap_uint<8> img[91260], ap_uint<8> output[91260]) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=img
	#pragma HLS INTERFACE s_axilite port=output

	ap_uint<8> buffer[94868];
	buffer[0] = img[0];
	buffer[1281] = img[1279];
	buffer[93586] = img[90880];
	buffer[94867] = img[92159];
	gaussian_label3:for (int i = 1; i < 1281; i++) {
		buffer[i] = img[i-1];
		buffer[93586+i] = img[90879+i];
	}
	gaussian_label1:for (int j = 1; j < 73; j++) {
		buffer[j*1282] = img[(j-1) * 1280];
		gaussian_label2:for (int k = 1; k  < 1281; k++) {
			buffer[j*1282+k] = img[(j-1)*1280 + (k-1)];
		}
		buffer[j*1282+1281] = img[j*1280-1];
	}

	double kernel[9];
	kernel[0] = 0.0947416;
	kernel[1] = 0.118318;
	kernel[2] = 0.0947416;
	kernel[3] = 0.118318;
	kernel[4] = 0.147761;
	kernel[5] = 0.118318;
	kernel[6] = 0.0947416;
	kernel[7] = 0.118318;
	kernel[8] = 0.0947416;

	gaussian_label0:for (int m = 0; m < 72; m++) {
		gaussian_label4:for (int n = 0; n < 1280; n++) {
			output[m*1280+n] = kernel[0]*buffer[m*8+n]
							 + kernel[1]*buffer[m*8+n+1]
							 + kernel[2]*buffer[m*8+n+2]
							 + kernel[3]*buffer[(m+1)*8+n]
						     + kernel[4]*buffer[(m+1)*8+n+1]
							 + kernel[5]*buffer[(m+1)*8+n+2]
							 + kernel[6]*buffer[(m+2)*8+n]
							 + kernel[7]*buffer[(m+2)*8+n+1]
						     + kernel[8]*buffer[(m+2)*8+n+2];
		}
	}

}
