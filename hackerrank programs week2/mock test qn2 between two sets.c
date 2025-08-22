#include <stdio.h>
#include <stdlib.h>
 //function to find the greatest common divisor (GCD)
 int gcd(int a,int b)
 {
 while(b) 
 {
 a %= b;
 int temp=a;
a=b;
b=temp;
 }
 return a;
 }
 //function to find the least common multiple (LCM)
int lcm(int a, int b) 
 {
 if(a == 0||b == 0) 
 {
 return 0;
 }
 return(a*b)/gcd(a,b);
 }
 //main function to solve the problem
 int getTotalX(int a_count, int* a, int b_count, int* b) 
 {
 int result = 0;
 int lcm_a = a[0];
 for (int i = 1; i < a_count; i++)
 {
 lcm_a = lcm(lcm_a, a[i]);
}
 int gcd_b = b[0];
 for (int i = 1;i<b_count; i++) 
 {
 gcd_b=gcd(gcd_b,b[i]);
 }
 int multiple=lcm_a;
 while (multiple <= gcd_b) 
 {
 if (gcd_b % multiple==0) 
 {
 result++;
 }
 multiple +=lcm_a;
 }
 return result;
}
//function to handle input and call the solution function
int main() 
{
 int n,m;
 scanf("%d %d",&n,&m);
 int*a = (int*)malloc(n*sizeof(int));
 for(int i=0; i<n;i++) 
 {
 scanf("%d",&a[i]);
 }
 int*b=(int*)malloc(m*sizeof(int));
 for (int i=0;i<m; i++)
 {
 scanf("%d",&b[i]);
 }
 int total_x=getTotalX(n,a,m,b);
 printf("%d\n",total_x);
 free(a);
 free(b);
 return 0;
}