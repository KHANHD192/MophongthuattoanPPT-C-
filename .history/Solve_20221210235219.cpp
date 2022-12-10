#include<bits/stdc++.h>
#include <stdlib.h>

void import(int n,float a[]){
  // mang a co kich thuoc n+1, luu chi so cua da thuc bac n 
      for(int i = n ; i>=0; i--){
         printf("he so cua x^%d la:",i);
               scanf("%f",&a[i]);
      } 
      printf("\n");

 }
 void export1(float a[],int n){ //xuat ra man hinh ham fx
          printf("fx =");
              printf(" %.1fx^%d ",a[n],n);
         for(int i = n-1 ;i >=0 ; i--){
            if(a[i] >=0){
              if(i==1){
                   printf("+ %.1fx",a[i]);
              }else if (i == 0){
                     printf("+ %.1f",a[i]);
              }else{
              printf("+ %.1fx^%d",a[i],i);
              }
            } 
            else{
              if(i==1){
                   printf(" %.1fx",a[i]);
              }else if (i == 0){
                     printf(" %.1f",a[i]);
              }else{
              printf(" %.1fx^%d",a[i],i);
              }
            } 
        
 }
 }
//  float Fx(float x,float a[],int n){ // x la gia tri de thay vao fx
//    float sumFx=0.0;
//       for(int i = n ; i>= 0; i--){
//          sumFx+= a[i]*(float)pow((float)x,i);
//       }
//       return sumFx;
//       }
      // tinh gia tri x cua ham fx su dung luoc do hoocne
      float Fx(float x, float A[],int n) {
      float KetQua = A[n];
   for(int i=n-1; i>=0; i--)
      KetQua=KetQua*x + A[i];
   return KetQua;
}
 float Newton(float x0,float B[],float A[],int n,float esilon,int m){ //  m la min tren f(x)'
         float xn = x0 - (Fx(x0,A,n)/Fx(x0,B,n-1));
         if(abs(Fx(xn,A,n)) < esilon*m){ // cong thuc sai so f(x)/m < esilon
           return xn;
         }else{
           x0 = xn ;
           return Newton(x0,B,A,n,esilon,m);
         }
 }
 // tim min max dua theo cach dung table trong casio
  float min(int a, int b , float A[],int n){
        float min= 0;
        for(float i = a ; i <= b ; i+=((a-b)/19)){
                      if(Fx(i,A,n) < min){
                        min = Fx(i,A,n);
                      }
        }
        return min;
  }

 float binary(float a, float b, float esilon,float A[],int n){
      float e = b - a ;
      float c = (float)(a + b)/2 ;
     if(e < esilon ){
       return b;
     }
     if((Fx(c,A,n) * Fx(a,A,n)) < 0){
         b = c;
         return binary(a,b,esilon,A,n);
     }else{
        a = c;
         return binary(a,b,esilon,A,n);
     }
     
   }
int main (){
    int n;
    float A[n+1];
    float B[n];
    float C[n-1];
    j: printf("\nMENU THUC HIEN TINH NGHIEM GAN DUNG CUA DA THUC BAC N\n");
     printf("\t\t1.Nhap da thuc\n");
     printf("\t\t2.Xuat da thuc\n");
     printf("\t\t3.Thuc hien tinh voi NEWTON\n");
     printf("\t\t4.Thuc hien tinh voi BINARY\n");
     printf("\t\t5.Thoat\n");
   
    //  float b[n];
     printf("Lua chon cua ban :");
     fflush(stdin);
     int k;
     scanf("%d",&k);
     switch(k){
      case 1 :{
         printf("nhap bac cua da thuc :");
        fflush(stdin);
         scanf("%d",&n);
        import(n,A);
         for(int i = 0 ; i < n;i++){  // dao ham cap 1
        B[i] = A[i+1] *(float)(i+1);
    }
      for(int i = 0 ; i < n-1;i++){ // dao ham cap 2 
        C[i] = B[i+1] *(float)(i+1);
    }
         goto j;
      }
      case 2 :{
        printf("da thuc bac %d ma ban vua nhap la :\n",n);
        export1(A,n);
        printf("\n");
        goto j;
      }
      case 3 :{
        float a,b,e;
        float x0;
   k:      printf("thuc hien nhap khoang phan li [a,b]\n");
         printf("nhap a :");
         scanf("%f",&a);
         printf("nhap b :");
         scanf("%f",&b);
         if(Fx(a,A,n)*Fx(b,A,n) >0){
                printf("Khoang phan li khong hop le !\n Vui long nhap lai\n");
                goto k;       
         }
         // chon X0
         if((Fx(a,A,n)*Fx(a,C,n-2)) > 0){
                  x0 = a;
         }else{
                  x0 = b;
         }
         printf("nhap sai so tuyet doi :");
         scanf("%f",&e);
         printf("\n \t\tKET QUA CUA CHUONG TRINH:\n");
         float m  = min(a,b,B,n); // min cua f(x)''
         printf("Nghiem gan dung cua phuong trinh la %f",Newton(x0,B,A,n,e,m));
         printf("\n\n");
         goto j;
      }
      case 4 :{
        float a,b,e;
         printf("thuc hien nhap khoang phan li [a,b]\n");
         printf("nhap a :");
         scanf("%f",&a);
         printf("nhap b :");
         scanf("%f",&b);
          if(Fx(a,A,n)*Fx(b,A,n) > 0){
                printf("Khoang phan li khong hop le !\n Vui long nhap lai\n");       
         }
         printf("nhap sai so tuyet doi :");
         scanf("%f",&e);
         printf("\n \t\tKET QUA CUA CHUONG TRINH:\n");
         printf("Nghiem gan dung cua phuong trinh la %f",binary(a,b,e,A,n));
         printf("\n\n");
         goto j;
      }
      case 5 :{
        printf("\n Ket thuc chuong trinh !\n");
        break;
      }
   
}
}