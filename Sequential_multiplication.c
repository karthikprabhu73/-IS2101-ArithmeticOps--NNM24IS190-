#include<stdio.h>
#include<stdlib.h>
int absolute(int x){
    return (x<0)?-x:x;
}
void shiftAddMultiplication(int multiplicand, int multiplier, int bitSize){
    int A = 0;                          // Accumulator
    int Q = absolute(multiplier);       // Multiplier (positive version)
    int M = absolute(multiplicand);     // Multiplicand (positive version)
    int count = bitSize;
    while(count>0){
         // If Q0 (LSB of multiplier) = 1, then A=A+M
         if(Q&1){
            A=A+M;
            printf("Step %d: Q0=1 -> A = A + M = %d\n",bitSize-count+1,A);
         }
         else{
            printf("step:%d Q0=0 -> No addition, A = %d\n",bitSize-count+1,A);
         }
        Q =(A&1)<<(bitSize-1)|(Q>>1);       //Shifted the LSB OF A by doing (A&1) and adding it MSB of Q and shifting Q.
        A=A>>1;
        printf("After shifting: A=%d, Q = %d\n",A,Q);
        count--;
    }
    int product=(A<<bitSize)|Q;           //  combining accumilator and M
        if((multiplicand < 0)^(multiplier < 0)){        
        product = -product;                         //handle negative (if either multiplicand or multiplier is negatuve)
    }
    printf("\nFinal Product: %d\n",product);
}
int main(){
    int M,Q;
    printf("Enter Multiplicand:");
    scanf("%d",&M);
    printf("Enter Multiplier:");
    scanf("%d",&Q);

    shiftAddMultiplication(M,Q,8);  // Using 8-bit size
    return 0;
}