#include <stdio.h> 
#include <mpi/mpi.h>
#include <math.h> 
#include <time.h> 
#include <omp.h>
    int main(int argc, char * * argv) {
        int i, j, n, p, count, flag, limit, myid, numprocs, local_n;
        clock_t t1, t2;
        MPI_Status status;
        MPI_Init(NULL, NULL);
        MPI_Comm_size(MPI_COMM_WORLD, & numprocs);
        MPI_Comm_rank(MPI_COMM_WORLD, & myid);

        if (myid == 0) {
            printf("Enter the number\n");
            scanf("%d", & n);
            MPI_Send( & n, 1, MPI_INTEGER, 1, 1, MPI_COMM_WORLD);
            printf("First %d prime numbers are \n", n);
        } else {
            MPI_Recv( & n, 1, MPI_INTEGER, 0, 1, MPI_COMM_WORLD, & status);
        }
        t1 = clock();
        if (n >= 1) {
            if (myid == 0)
                printf("%d ", 2);
            n = n - 1;
            j = myid -1; 
            limit = (int) sqrt((float) p);
            local_n = n / numprocs;
            omp_set_num_threads(4);
            if (myid == 0)
                local_n = local_n + n % numprocs;	
	#pragma omp parallel for private (flag,i,limit,p)
        for (count = 0; count < local_n; count++) {
            #pragma omp critical 
            {
                j=j+numprocs;
                p = 2 * j + 1;
	    }
                limit = (int) sqrt((float) p);
	    
            while (1) {
                flag = 1;

                for (i = 2; i <= limit; i++) {
                    if (p % i == 0) //Will be true if p is not prime
                    {
                        flag = 0;
                        break;
                    }

                }
                if (flag == 1) {
                    printf("%d from process %d\n",p,omp_get_thread_num()) ;
                    break;
                }
		#pragma omp critical 
		{
                    j=j+numprocs;
                    p = 2 * j + 1;
		}
                    limit = (int) sqrt((float) p);
		
            }
        }
        MPI_Finalize();
        t2 = clock();
        printf("\nTEMPS = %f \n", (float)(t2 - t1) / CLOCKS_PER_SEC);
        return 0;
    }
}