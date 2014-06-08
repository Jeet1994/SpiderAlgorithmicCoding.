#include<stdio.h>
#include<conio.h>

descending_natural(int n)
{
    if(n == 0) return;

    printf("%d ", n);
    descending_natural(n-1);
}

main()
{
    int N;

    printf("Enter the n'th number: ");
    scanf("%d", &N);

    printf("Numbers from 1 to %d in descending order: \n", N);
    descending_natural(N);

    getch();
    return(0);
}
