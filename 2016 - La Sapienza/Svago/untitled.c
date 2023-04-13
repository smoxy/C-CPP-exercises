#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	short* data=(short*)malloc(1 * sizeof(short));
	printf("sizeof(data) = %d bytes\n", (sizeof(*data)));
	*data = 32767;
	*(data+1) = -32768;
	*(data+2) = 32767;
	*(data+3) = -32768;
	*(data+4) = 32767;
	*(data+5) = 666;
	
	printf("Memory location of data:\t%p\t= %hd\nMemory location of (data+1):\t%p\t= %hd\nMemory location of (data+2):\t%p\t= %hd\nMemory location of (data+3):\t%p\t= %hd\nMemory location of (data+4):\t%p\t= %hd\nMemory location of (data+5):\t%p\t= %hd\n", data, *data, (data+1), *(data+1), (data+2), *(data+2), (data+3), *(data+3), (data+4), *(data+4), (data+5), *(data+5));
	printf("sizeof(data) = %d bytes", (sizeof(*data)));
	printf("\n\n\n");
	printf("%hd\n",*(data));
	printf("%hd\n",*(data+1));
	printf("%hd\n",*(data+2));
	printf("%hd\n",*(data+3));
	printf("%hd\n",*(data+4));
	printf("%hd\n",*(data+5));
	
}
