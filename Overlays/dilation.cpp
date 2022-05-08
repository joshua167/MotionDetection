#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <ap_int.h>
#include <string.h>
#include <math.h>

int background = 0;
int foreground = 1;

void dilation(ap_uint<8> input[92160], ap_uint<8> output[92160]);

#define N 92160 //408960 //921600 //2073600

void dilation(ap_uint<8> input[92160], ap_uint<8> output[92160]) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=input
	#pragma HLS INTERFACE s_axilite port=output

    printf("Image Will Be Dilated\n");
    int length = 92160;
    /* structuring element */
    int sel = 100;
    int flag;
    int kernel[sel];

    dilation_label3:for (int i = 0; i < length; i++) {
    	flag = 0;

    	dilation_label1:for (int j = 0; j < sel; j ++) {
    		kernel[j] = 1;
    	}

    	if ((i + sel) < length) {
    		dilation_label2:for (int j = 0; j < sel; j++) {
    			if (input[i + j] == kernel[j]) {
    				flag = 1;
    				output[i + (sel / 2)] = foreground;
    				break;
    			}
    			else
    				output[i + (sel / 2)] = background;
    		}
    	}
    }

    printf("Image Dilation Successful.\n");
}

