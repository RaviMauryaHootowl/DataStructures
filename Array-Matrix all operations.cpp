//Write a C++ program to define user defined type, say matrix, a two-dimensional array. 
Perform addition, subtraction, multiplication of two matrices. 
Also perform transpose of a matrix.*/
#include <iostream>
using namespace std;
void print_arr(int arr[10][10], int n)
{
    for (int i=0;i<n;++i)
           { cout<<"[";
               for(int j=0;j<n;++j)
               {
                   cout<<arr[i][j];
                   if(j<n-1)
                   cout<<", ";
               }cout<<"]";
               cout<<endl;
           }
}
class matrix
{
    public:
       
       int arr[10][10];
       void setmat(int arr[10][10],int n );// method prototype me parameters neccessary hai
       
};
void matrix :: setmat( int arr[10][10],int n)
       {   
           cout<<"set elements of your matrix :"<<endl;
           for (int i=0;i<n;++i)
           {
               for(int j=0;j<n;++j)
               {
                   cout<<" a"<<i+1<<j+1<<" = ";
                   cin>>arr[i][j];
               }
           }
          
       }
void addmat(int mad[10][10],int arr1[10][10],int arr2[10][10],int n)
{   
    for (int i=0;i<n;++i)
           {
               for(int j=0;j<n;++j)  //---->in this yo cant define matrix inside&return it
               {                    // c++ dont return arr ;you can use *ptr.(e.g rand print)
                   mad[i][j]=(arr1[i][j]+arr2[i][j]);
               }
         }
 }
void submat(int mad[10][10],int arr1[10][10],int arr2[10][10],int n)
{   
    for (int i=0;i<n;++i)
           {
               for(int j=0;j<n;++j)  
               {
                   mad[i][j]=(arr1[i][j]-arr2[i][j]);
               }
         }
 } 
void multmat(int mad[10][10],int arr1[10][10],int arr2[10][10],int n)
{   
    for (int i=0;i<n;++i)
           {
               for(int j=0;j<n;++j)  
               { mad[i][j]=0;
                   for(int r=0;r<n;++r)  //(ab)ij=sigma r=0->n-1 aij*bij
               {
                   mad[i][j] +=arr1[i][r]*arr2[r][j];
               }
               }
         }
 } 
void transmat(int mad[10][10],int arr[10][10],int n)
{   
    for (int i=0;i<n;++i)
           {
               for(int j=0;j<n;++j)  
               {
                   mad[i][j]=arr[j][i];
               }
         }
 } 
 
int main ()
{   int n;
    matrix m1,m2;
    cout<<"order of square matrix : ";
    cin>>n;
    m1.setmat(m1.arr,n);
    m2.setmat(m2.arr,n);
    cout<<"matrix m1 :"<<endl; 
    print_arr(m1.arr,n);
    cout<<"matrix m2 :"<<endl;
    print_arr(m2.arr,n);
    matrix m_sum;
   addmat(m_sum.arr,m1.arr,m2.arr,n);
   cout<<"matrix m1+m2 is :"<<endl;
   print_arr(m_sum.arr,n);
   matrix m_sub;
   submat(m_sub.arr,m1.arr,m2.arr,n);
   cout<<"matrix m1-m2 is :"<<endl;
   print_arr(m_sub.arr,n);
   matrix m_mult;
   multmat(m_mult.arr,m1.arr,m2.arr,n);
   cout<<"matrix m1*m2 is :"<<endl;
   print_arr(m_mult.arr,n);
   matrix m1_t,m2_t;
   transmat(m1_t.arr,m1.arr,n);
   transmat(m2_t.arr,m2.arr,n);
   cout<<"transpose of m1 :"<<endl;
   print_arr(m1_t.arr,n);
   cout<<"transpose of m2 :"<<endl;
   print_arr(m2_t.arr,n);
}    
