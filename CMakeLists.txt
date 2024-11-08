cmake_minimum_required(VERSION 3.5)

project(file_trans)

#SET(CMAKE_C_COMPILER   /opt/arm-buildroot-linux-gnueabihf/bin/arm-buildroot-linux-gnueabihf-gcc)
#SET(CMAKE_CXX_COMPILER /opt/arm-buildroot-linux-gnueabihf/bin/arm-buildroot-linux-gnueabihf-g++)

SET(CMAKE_C_COMPILER   /home/user/Workarea/buildroot_2024.04/9x60_curiosity/buildroot-at91/output/host/bin/arm-buildroot-linux-gnueabi-gcc)
SET(CMAKE_CXX_COMPILER /home/user/Workarea/buildroot_2024.04/9x60_curiosity/buildroot-at91/output/host/bin/arm-buildroot-linux-gnueabi-g++)

#SET(CMAKE_C_COMPILER   gcc)
#SET(CMAKE_CXX_COMPILER g++)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(t1s_dump ${PROJECT_SOURCE_DIR}/src/main.c)

