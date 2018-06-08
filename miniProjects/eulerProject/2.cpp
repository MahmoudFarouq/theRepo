#include <stdio.h>

int main()
{
	unsigned long array[100];
	unsigned long long sum = 2;
	
	array[0] = 1; array[1] = 2;
	
	int i = 2;
	while(true){
		array[i] = array[i-1] + array[i-2];
		if(array[i] > 4000000)
			break;
		if(array[i] % 2 == 0)
			sum += array[i];
		i++;
	}
	
	printf("%u", sum);
	
	
}

