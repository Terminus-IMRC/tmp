#include <stdio.h>
#include <stdint.h>

//typedef indexBit_t uint64_t;
typedef uint64_t indexBit_t;
//#define INDEXBIT_BASE ((indexBit_t)0x80)
#define INDEXBIT_BASE ((indexBit_t)0x01)
//#define INDEXBIT_BASE ((indexBit_t)((unsigned char)1)<<63)

int main()
{
	int i;
	indexBit_t b=0;

	printf("ib: %lu,%lX\n", INDEXBIT_BASE, INDEXBIT_BASE);

	b|=INDEXBIT_BASE;
	printf("%lu,%X\n", b, b);
	for(i=0; i<63; i++){
		b<<=(indexBit_t)1;
		b|=INDEXBIT_BASE;
		printf("%lu,%lX\n", b, b);
	}

	return 0;
}
