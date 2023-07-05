

// #include<stdio.h>
// #include<conio.h>
// #include<math.h>
// void TOH( int n  , char sou , char help , char des ){
// 	if(n > 0){
// 		TOH(  n-1  ,  sou ,  des ,  help );
// 		printf("Moved disk %d from %c to %c \n" , n , sou , des);
// 		TOH(n-1 , help , sou , des);
// 	}

// }
// int main(){

// 	TOH(3 ,'a' , 'b' ,'c');
//     getch();
//     return 0;
// }
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    int result = gcd(num1, num2);
    
    printf("GCD: %d\n", result);
    
    return 0;
}



