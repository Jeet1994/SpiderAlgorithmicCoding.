#include<stdio.h>
#include<conio.h>

ascending_natural(int n)
{
    if(n == 0) return;

    ascending_natural(n-1);
    printf("%d ", n);
}

main()
{
    int N;

    printf("Enter the n'th number: ");
    scanf("%d", &N);

    printf("Numbers from 1 to %d in ascending order: \n", N);
    ascending_natural(N);

    getch();
    return(0);
}
