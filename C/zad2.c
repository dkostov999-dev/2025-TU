#include <stdio.h>
int main(){
int N;
printf("Enter the length N: ");
scanf("%d", &N);
int arr[N];
for(int i=0;i<N;i++){
printf("Enter an element: ");
scanf("%d", &arr[i]);
}
int counter = 0;
for(int j=1;j<N;j++){

if(arr[j]>arr[j-1] && arr[j]>arr[j+1])
counter+=1;

}
if(counter>0){

    printf("Yes");

}
else{

    printf("No");
}




    return 0;
}