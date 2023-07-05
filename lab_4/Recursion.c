#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

int factorial( int x){          // Non Tailed recursion 
    if ( x == 0)
        return 1;
    else
        return x * factorial(x - 1);
}

int facto( int x , int a ){     // Tailed recursion 
    if( x == 0)
        return a;
    else 
        return facto(x-1,a*x);

}

int NTsum ( int x){       // Non Tailed recursion
    if (x == 0)
        return 0;
    else
        return x + NTsum(x - 1);
}

int Tsum ( int x ,int a){       //  Tailed recursion
    if (x == 0)
        return a;
    else
        return  Tsum(x - 1 , a+x);
}
int fibb(int x){
    if( x == 0 || x == 1)
        return 1;
    else 
        return fibb(x-1) + fibb(x-2);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}



int main(){
    int choice;
    int a,n,b;
    while(1){

    printf("\n\n1.Factorial \n2.Sum \n3.Fibonaci \n4.GCD \n5.exit"  );
    printf("\nEnter Your choice  ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("\nEnter the data: ");
            scanf("%d" ,&a);
            printf("\n\"From Tailed\"  The factorial of %d is %d",a,factorial(a) );
            printf("\n\"From Non Tailed\" The factorial of %d is %d",a,facto(a,1));
            break;
        
        case 2:
            printf("\nEnter the data: ");
            scanf("%d" ,&a);
            printf("\n\"From  Tailed\" The sum upto %d number is %d" ,a,NTsum(a) );
            printf("\n\"From Non Tailed\" The sum upto %d number is %d" ,a,Tsum(a,0) );
            break;            
    
        case 3:
            printf("\nEnter the number of series to be printed : ");
            scanf("%d" ,&n);
            printf("\n");
            for(int i = 0 ; i < n;i++){
                printf("%d " , fibb(i));
            } 
            break;
        case 4:
            printf("\nEnter the data: ");
            scanf("%d%d" ,&a,&b);
            printf("\nGCD(%d,%d) = %d",a,b,gcd(a,b));
            break;

        case 5:
            exit(0);
        
        default:
            printf(" \n Wrong choice ");
    }
    }
    getch();
    return 0;
}