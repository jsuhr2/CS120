#include <stdio.h>

int entry(int a0, int a1){
	return a0 * a1;
}

int print_table(int a0){
	int s0, s1;
	for(s0 = 0; s0 != a0; s0 = s0 +1){
		for(s1 = 0; s1 != a0; s1 = s1 +1){
			int v0 = entry(s0, s1);
			printf("%d ", v0);
		}
		printf("\n");
	}
	return 0;
}

int main(){
	print_table(5);
	print_table(6);
	return 0;
}
