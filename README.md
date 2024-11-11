# t1s_dump
Console mode program to dump T1S data.</br>
This is TCP/IP program which based on UDP protocal.</br>
## Usage
$ git clone https://github.com/s887432/t1s_dump.git</br>
$ cd t1s_dump</br>
$ mkdir build</br>
$ cd build</br>
You need to modify CROSS_COMPILER path</br>
$ cmake .. -DARCH=$ARCH</br>
where if build for Cortex series (SAMA5, SAMA7), the ARCH=cortex</br>
if build for ARM9 series (SAM9x60, SAM9x7), the ARCH=arm9</br>
$ make </br>
the output will be generated in arm9_bin or cortex_bin</br>

Have Fun!!!</br>
Patrick Lin
