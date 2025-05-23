cmake_minimum_required(VERSION 3.15)
project(RAY_TRACER VERSION 1.0
                   DESCRIPTION "Ray tracing in one weekend"
                   LANGUAGES CUDA CXX)

<<<<<<< HEAD
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)
=======
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_ARCHITECTURES native)
>>>>>>> 3c6a1f9 (cmakelists and intiial changes for cuda)

add_executable(Tracer main.cu)
