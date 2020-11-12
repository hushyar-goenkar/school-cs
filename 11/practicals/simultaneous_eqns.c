#include <stdio.h>

void main(){
	float  a1,b1,c1,a2,b2,c2,x,y;
	printf("Give values of A, B, & C of the first equation \
in the form (+ve)Ax + By = C: ");
	scanf("%f%f%f",&a1,&b1,&c1);

	printf("Give values of A, B, & C of the second equation in the form (+ve)Ax + By = C: ");
	scanf("%f%f%f",&a2,&b2,&c2);

	y=(a2*c1-a1*c2)/(a2*b1-a1*b2);
	x=(c1-b1*y)/a1;

	printf("x term is - %f \n y term is - %f \n",x,y);
}
