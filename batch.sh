#!/bin/bash

i=0
n=4
size=524288
while [ $i -lt $n ]
do
    ./write_bench $1 8192 $size >> WRITE_Bench.dat
    ./read_bench $1 $size >> READ_Bench.dat
    let i=i+1
done
