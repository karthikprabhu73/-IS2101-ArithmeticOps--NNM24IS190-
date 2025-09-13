#include <stdio.h>
#include <stdlib.h> 
// Function to print binary numbers
void printBinary(int num,int bits) {
    unsigned mask=1u<<(bits-1);
    for (int i=0;i<bits;i++){
        printf("%d",(num&mask)?1:0);     //   suppose num is 1, 1stloop:  0001 & 1000 is 0 , 2nd: 0001 & 0100 is 0 , 3rd:0001 & 0010 is 0 and 4th loop: 0001 & 0001 is 1 so final printed value is 0001
        mask>>=1;
    }
}
// Non-Restoring Division
void nonRestoringDivision(int dividend, int divisor, int bits){
    int A=0;            // Accumulator
    int Q=dividend;     // Dividend (will hold quotient)
    int M=divisor;      // Divisor
    int n=bits;         // Number of bits
    // printf("Initial Values:\n");
    // printf("A="); printBinary(A,n+1); printf("\n");
    // printf("Q="); printBinary(Q,n); printf("\n");
    // printf("M="); printBinary(M,n); printf("\n\n");
    for(int i=0;i<n;i++){
        // Left shift A and Q
        A=(A<<1)|((Q>>(n-1))&1);          //shifting A by one then shifting the Q by 4 bits so as to get the MSB which then is placed in A
        Q=(Q<<1)&((1<<n)-1);  // Keep Q within n bits
        printf("Step %d:\n", i+1);
        printf("After shift: A = "); printBinary(A, n+1);
        printf(", Q = "); printBinary(Q, n); printf("\n");
        // Perform A = A - M if A >= 0, else A = A + M
        if(A>=0){
            A=A-M;  
            if (A>=0)
                Q=Q|1; // Set last bit of Q to 1
        }else{
            A=A+M;
            if(A>=0)
                Q=Q|1;   
        }
        printf("After operation: A = "); printBinary(A, n+1);
        printf(", Q = "); printBinary(Q, n); printf("\n\n");
    }
    // Final correction if A < 0
    //restoring the multiplicand
    if (A<0) {
        A=A+M;
    }
    printf("Final Quotient Q = "); printBinary(Q, n); printf(" (%d)\n", Q);
    printf("Final Remainder A = "); printBinary(A, n+1); printf(" (%d)\n", A);
}
int main(){
    int dividend,divisor,bits;
    printf("Enter Dividend: ");
    scanf("%d", &dividend);
    printf("Enter Divisor: ");
    scanf("%d", &divisor);
    printf("Enter number of bits: ");
    scanf("%d", &bits);               
    nonRestoringDivision(dividend, divisor, bits);
    return 0;
}
