#include <stdio.h> 
#include <math.h> 
#include <time.h>

    void main() {
        int i, j, n, p, count, flag, limit;
        clock_t t1, t2;
        printf("Enter the number\n");
        scanf("%d", & n);
        printf("First %d prime numbers are \n", n);
        t1 = clock();
        p = 2;
	printf("%d ",p);
        j = 0;

        for (count = 0; count < n; count++) {

            j++;
            p = 2 * j + 1;
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
                    printf("%d ",p) ;
                    break;
                }
                j++;
                p = 2 * j + 1;
                limit = (int) sqrt((float) p);
            }

        }

        t2 = clock();
        printf("\nTEMPS = %f \n", (float)(t2 - t1) / CLOCKS_PER_SEC);

    }