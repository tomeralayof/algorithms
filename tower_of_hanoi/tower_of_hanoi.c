#include <stdio.h>

void TowerOfHanoi(int n,char from_rod, char to_rod, char aux_rod);

int main()
{
	int num = 4;
	char from = 'A';
	char to = 'C';
	char aux = 'B';

	TowerOfHanoi(num, from, to, aux);	

	return 0;
}

void TowerOfHanoi(int n,char from_rod, char to_rod, char aux_rod)
{
	if (n == 1)
	{
		printf("move disk 1 from %c to %c\n ",from_rod,to_rod);
		return;
	}

	TowerOfHanoi(n-1,from_rod,aux_rod,to_rod);
	printf("move disk %d from %c to %c\n",n,from_rod,to_rod);
	TowerOfHanoi(n-1,aux_rod,to_rod,from_rod);
}