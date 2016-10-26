#!/bin/bash

i=0
n=4
size=524288
while [ $i -lt $n ]
do
    sync && echo 1 > /proc/sys/vm/drop_caches
    ./write_bench $1 >> WRITE_Bench.dat
    sync && echo 1 > /proc/sys/vm/drop_caches
    ./read_bench $1 >> READ_Bench.dat
    let i=i+1
done
