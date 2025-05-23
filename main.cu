#include <ctime>
#include <fstream>
#include <iostream>

#include "camera.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"


#define checkCudaErrors(val) check_cuda((val), #val, __FILE__, __LINE__)
void check_cuda(cudaError_t result, char const* const func, const char* const file,
                int const line) {
  if (result) {
    std::cerr << "CUDA error = " << static_cast<unsigned int>(result) << " at " << file << ":"
              << line << " '" << func << "' \n";
    // Make sure we call CUDA Device Reset before exiting
    cudaDeviceReset();
    exit(99);
  }
}

void writeToFile(int image_width, int image_height, vec3* fb, size_t s) {
  std::ofstream output("image.ppm");
  output << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (size_t i = 0; i < image_width * image_height; ++i){
    output << int(255.99 * fb[i].x()) << ' ' << int(255.99 * fb[i].y()) << ' ' << int(255.99*fb[i].z()) << '\n';
  }
}

__global__ void render(vec3* fb, int image_width, int image_height) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    if ((i >= image_width) || (j >= image_height)) return;
    int idx = j * image_width + i;

    fb[idx] = vec3(float(i) / (image_width - 1), float(j) / (image_height - 1), 0.0f);
}

int main() {

  // Image + CUDA buffer

  int image_width = 1200;
  int image_height = 600;

  int num_pixels = image_width * image_height;
  size_t fb_size = num_pixels * sizeof(vec3);
  vec3* fb;
  checkCudaErrors(cudaMallocManaged((void**)&fb, fb_size));

  int t_width = 8;
  int t_height = 8;

  dim3 blocks(image_width / t_width + 1, image_height / t_height + 1);
  dim3 threads(t_width, t_height);

  // Render
  clock_t start, stop;
  start = clock();
  render<<<blocks, threads>>>(fb, image_width, image_height);
  checkCudaErrors(cudaDeviceSynchronize()); // Blocks until all threads have completed.
  stop = clock();
  std::cout << (double)(stop - start) / CLOCKS_PER_SEC << '\n';

  writeToFile(image_width, image_height, fb, fb_size);
  checkCudaErrors(cudaFree(fb));
}
