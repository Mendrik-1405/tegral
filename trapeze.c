#include <stdio.h>
#include <math.h>
float f(float x);
void getData(float* a,float* b,float* n);
void displayResult(float a,float b,float A,float n);
void displayResultrap(float a,float b,float A,float n);
float fxi(float n);
float trapeze(float a,float b,float n);
float simpson(float a,float b,float n);
int main(){
	printf("calcul d'integrale entre a et b\n");
///Entree des donnees
	float a=0, b=1;		//les bornes
	float A=1234.634;	//l'integale a calculer
	float n=10;			//nb des sous-integration des discrets
	float A2=0;			//l'integale a calculer
	float A3=0;			//l'integale a calculer
	float A4=0;			//l'integale a calculer
	getData(&a,&b,&n);
	printf("premier nbr de decoupe de n=?\n");
	scanf("%f",&n);
///calcul
	while(1>0){
	float epsi=1E-5;
	A=simpson(a,b,n);
	A2=simpson(a,b,2*n);
	A3=trapeze(a,b,n);
	A4=trapeze(a,b,2*n);
///sortie de resultat
	displayResult(a,b,A,n);
	displayResult(a,b,A2,2*n);
	displayResultrap(a,b,A3,n);
	displayResultrap(a,b,A4,2*n);
	n++;
	if(fabs(A2-A)<=epsi){
		printf("fabs=%f vs epsi=%f ",(A2-A),epsi);
		printf("resultat assez precis pour methode de simpson\n");
		break;
	}else if(fabs(A3-A4)<=epsi){
		printf("fabs=%f vs epsi=%f ",(A4-A3),epsi);
		printf("resultat assez precis pour methode de trapeze\n");
		break;
	}
	}

	return 0;
}

float trapeze(float a,float b,float n){
	float A=452;
	float h=(b-a)/n;
	A=(h/2)*(f(a)+(2*(fxi(n)))+f(b));
	//printf("h=%f",h);
	return A;
}
float simpson(float a,float b,float n){
	float A=452;
	float h=(b-a)/n;
	A=(h/2)*(f(a)+(2*(fxi(n)))+f(b));
	//printf("h=%f",h);
	return A;
}
void getData(float*a,float* b,float* n){
	*a=0;
	*b=1;
	*n=350;
}
void displayResult(float a,float b,float A,float n){
	printf("\nL'integrale de f par methode de simpson dans [%g ; %g] est A= %f\n",a,b,A);
	printf("\ten decoupant l'integrale en %f\n",n);
}
void displayResultrap(float a,float b,float A,float n){
	printf("\nL'integrale de f par methode de trapeze dans [%g ; %g] est A= %f\n",a,b,A);
	printf("\ten decoupant l'integrale en %f\n",n);
}
float fxi(float n){
	float fxi=0;
	float i;
	float xi;
	for(i=1;i<n;i++){
		xi=i/n;
		fxi=fxi+f(xi);
		//printf("%f",xi);
	}
	return fxi;
}
float fxi2(float n){
	float fxi=0;
	float i;
	float xi;
	for(i=0;i<n;i++){
		xi=i/2*n;
		fxi=fxi+f(xi);
		//printf("%f",xi);
	}
	return fxi;
}
float f(float x){
	return exp(sin(5*x));
}
