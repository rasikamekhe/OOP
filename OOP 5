#include<iostream>
using namespace std;
template<class T>
void Ssort(T A[],int n){
    T temp;
    int i,k,m,j,min;
    
    for(i=0;i<n-1;i++){
        min=i;
    
    for(j=i+1;j<n;j++){
        if(A[j]<A[min]){
            min=j;
        }
    }
    temp=A[i];
    A[i]=A[min];
    A[min]=temp;
    }

   for(int k=0;k<n;k++){
        
        cout<<"\n"<<A[k];
    }   


}

int main(){
    int A[10];
    float B[10];

    int ch,op,n;
    do{
        cout<<"--MENU--";
        cout<<"\n1.Integer values";
        cout<<"\n1.Float values";
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        cout<<"Enter your array size: ";
        cin>>n;
        

        switch(ch){
            case 1:
            cout<<"Enter array elements: ";
            for(int k=0;k<n;k++){
                cin>>A[k];
            }   
            cout<<"Sorted integer values..";
            Ssort(A,n);
            break;

            case 2:
            cout<<"Enter array elements: ";
            for(int m=0;m<n;m++){
                cin>>B[m];
            }  
            cout<<"Sorted float values.."<<endl;
            Ssort(B,n);

            break;
        }
        cout<<"\nDo you want to perform again? Yes:press 1, No:press 0 \t";
        cin>>op;
    }
    while(op==1);
    return 0;
}
