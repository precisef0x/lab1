#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
	uint32_t N;
        uint8_t *array;
	scanf("%u", &N);
	array = (uint8_t*) malloc(N*8);
	for(int i=0; i<N; i++) scanf("%u", &array[i]);
	
cycle:;	int diff=0;
	for(int i=0; i<N-1; i++)
	{
		if(array[i] > array[i+1])
		{
			diff++;
			uint8_t temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
		}
	}
	if(diff) goto cycle;
	
	for(int i=0; i<N; i++) printf("%u ", array[i]);
	
	free(array);
	return 0;
}
