//Determine grade(via marks of six subjects) of a student.
#include <stdio.h>
void main() {
	int m, p, c, b, com, eng, avg = 0;

	printf("Input the marks(out of 100) for maths, physics, chemistry, biology, computer science, and english respectively: \n");
	scanf("%d%d%d%d%d%d", &m, &p, &c, &b, &com, &eng);
	avg = (m + p + c + b + com + eng)/6;

	if(avg >= 85) printf("A");
	else if(avg >= 70) printf("B");
	else if(avg >= 55) printf("C");
	else if(avg >= 40) printf("D");
	else	printf("F");
	printf("\n");
}
