#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
void main (){
int i,N,j,trouve;
printf("entrez-le nombre N :");
scanf("%d",&N);
i=1;
double debut,fin;
debut=omp_get_wtime();
omp_set_num_threads(4);
#pragma omp parallel for private (trouve,j) lastprivate(fin)

for (int cpt=1;cpt<N;cpt++)
	{
	trouve=0;
	while ( trouve == 0 )
		{ 
i=i+2;
			for ( j=2; j<= sqrt((double)i) ;j++)
			{
	
	   		   if (i%j==0) break;
      
	       		}

			if (j>sqrt((double)i)) 
{printf("%d|",i); 
trouve=1;}
			
		}
	}




fin = omp_get_wtime()-debut;
printf("time = %f ",(float)(fin));

}