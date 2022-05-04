#include <cmath>

void binaryThreshold(int img[91260], int output[91260]) {
  
  for (int i = 0; i < 72; i++) {
    for (int j = 0; j < 1280; j++) {
      output[i*1280 + j] = img[i*1280 + j] > 25 ? 255 : 0;
    }
  }
}
