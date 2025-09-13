#include <stdio.h>
#include <stdlib.h>

// Function to print binary with fixed bits
void printBinary(int num,int bits) {
    for (int i = bits-1;i>=0;i--) {
        printf("%d", (num>>i)&1);
    }
}

// Restoring Division Algorithm
void restoringDivision(int dividend, int divisor, int bitSize) {
    int A = 0;                          //Accumulator(remainder)
    int Q = abs(dividend);              //Dividend
    int M = abs(divisor);               //Divisor
    int count = bitSize;
    printf("Initial Values:\n");
    printf("A = "); printBinary(A, bitSize);
    printf("  Q = "); printBinary(Q, bitSize);
    printf("  M = "); printBinary(M, bitSize);
    printf("\n\n");

    while (count>0){
        // printf("Step %d:\n", bitSize-count+1);
        // Left shift (A, Q)
        int combined=(A<<bitSize)|Q;
        combined<<=1;
        A=(combined>>bitSize)&((1<<bitSize)-1);
        Q=combined&((1<<bitSize)-1);  
        //Subtract M FROM A
        A=A-M;
        if (A<0) {  //ie negative
            // Restore A and set Q0 = 0
            A=A+M;
            Q=Q&(~1); // set LSB = 0
        }else{
            //Set Q0 = 1
            Q=Q|1;
        }
        // printf("  Result: A = ");
        // printBinary(A, bitSize);
        // printf("  Q = ");
        // printBinary(Q, bitSize);
        // printf("\n\n");
        count--;
    }

    // Handle sign of result
    int quotient=Q;
    int remainder=A;
    if((dividend<0)^(divisor<0)){
        quotient=-quotient;
    }
    if (dividend<0){
        remainder=-remainder;
    }

    printf("Final Quotient (Decimal): %d\n", quotient);
    printf("Final Quotient (Binary) : ");
    printBinary(quotient, bitSize);
    printf("\n");

    printf("Final Remainder (Decimal): %d\n", remainder);
    printf("Final Remainder (Binary) : ");
    printBinary(remainder, bitSize);
    printf("\n");
}

int main() {
    int dividend,divisor;
    printf("Enter Dividend:");
    scanf("%d",&dividend);
    printf("Enter Divisor:");
    scanf("%d",&divisor);

    if (divisor==0){
        printf("Error: Division by zero not allowed.\n");
        return 1;
    }
    restoringDivision(dividend,divisor,8); // 8-bit
    return 0;
}
