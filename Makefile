all: rdisk.c wdisk.c
	gcc rdisk.c -o read_bench
	gcc wdisk.c -o write_bench
