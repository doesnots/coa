#include<stdio.h>
#include<conio.h>
clrscr();
int main(){
int oct1,oct2,temp1,temp2,max,min,carry=0,sum=0,mid,i=0,po=1;
printf("Enter OCTAL NUMBER 1 : \t");
scanf("%d",&oct1);
printf("Enter OCTAL NUMBER 2 : \t");
scanf("%d",&oct2);
if(oct1>oct2){
max=oct1;
min=oct2;
}
else
{
max=oct2;
min=oct1;
}
while(max>0){
temp1=max%10;
max=max/10;
temp2=min%10;
min=min/10;
mid=(temp1 + temp2 + carry)%8;
carry=(temp1 + temp2 + carry)/8;
sum=po*mid +sum;
po=po*10;
if(max==0 && carry>0){
sum=po*carry+sum;
}
}
printf("OCTAL ADDITION = \t %d ",sum);
return 0;
}
