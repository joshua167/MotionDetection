#include <stdio.h>
#include <math.h>
#include <ap_axi_sdata.h>


#define N 100
typedef ap_axis<32,1,1,1> AXI_VAL;


int main () {
	AXI_VAL output;
	AXI_VAL pixels;

	int pixelInputs[N];

  for (int i=0; i<N; i++) {
	  pixelInputs[i] =  100-i;
  }

/*
	pixels = {
		pixels->data = pixelInputs;
		pixels-> keep = input->keep;
		pixels-> strb = input->strb;
		pixels->last = input->last;
		pixels->dest = input->dest;
		pixels->id = input->id;
		pixels->user = input->user;
	};
*/

	// Execute the function with latest input
    absDiff(&output, &pixels);

    for (int i = 0 ; i < N; i++) {
        printf("Output = %d", output[i]);
    }

    return 0;
}
