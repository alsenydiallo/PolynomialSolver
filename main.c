		#include <stdio.h>
		#include <stdlib.h>
		#include <complex.h>
		#include <math.h>

		#define MAXN 25 // max degree
		#define KMAX 150 // max number of iteration
		#define Epsilon 10e-6 // max error tolerated 
		//#define REGURGITATE 

		int main(void)
		{
			
			int n = 0;  // polynomial degree 
		  complex double c[MAXN+1];
		  double a, b;
		  while (scanf("%lf %lf", &a, &b) == 2)
		    c[n++] = a + b*I;
		  c[n] = 1;  // leading coeff implied

		#ifdef REGURGITATE  // test input
		  for (int i = 0; i < n; i++) {
		    a = creal(c[i]);
		    b = cimag(c[i]);
		    printf("%0.10f + %0.10f i\n", a, b);
		  }
		#endif

		  // .. your code here

		  	double maxVal=cabs(c[0]);
		  	complex double dz[n+1];
			complex double q[n+1];
			complex double fz=1.0;
			double dzMax=0;

			// compute the radius 
		  for(int j=1; j<n; j++){
		  		if(maxVal < cabs(c[j]))
		  			maxVal = cabs(c[j]);
		  }

		// compute the initial guess
		  double radius = 1 + maxVal;
		  complex double z[n+1];
		  double dtheta = 2*M_PI/n;
		  double theta=0.0;

		  for(int j=0; j<n; j++){
		  	
		  	z[j] = (cos(theta) + I*sin(theta)) * radius;
		  	theta += dtheta;
		}

			// compute the denometor Qj
			for(int k=1; k < KMAX; k++){

				dzMax =0.0;
				for(int j =0; j < n; j++){
					
					q[j] = 1.0;
					for(int i=0; i<n; i++)
						if(i != j)
							q[j] *= (z[j] - z[i]);
				
				}		
				
				// compute the n root and store it in z[j]
				for(int j=0; j<n; j++){
					
					// compute f(zj)
					fz = z[j] + c[n-1]; 			
					for(int i =n-2; i>=0; i--)
						fz = c[i] + (fz * z[j]);

					dz[j] = -fz/q[j]; 

					// find the max difference betwwen all the root
					if(cabs(dz[j]) > dzMax)
						dzMax = cabs(dz[j]);
				}
					// update root
				for(int i=0; i<n; i++)
					z[i] = z[i] + dz[i];

					// check if error is less than machine epsilon then stop the pressess
				if(cabs(dzMax) <= Epsilon){
					break;
				}
				
				printf("iter %d\n", k);
				for(int i=0; i<n; i++)
					printf("z[%d] = %0.9f + %0.9f i\n", i, creal(z[i]), cimag(z[i]));
			}		
				
			return 0;
		}