//ASSIGNMENT 1
//QUESTION 1


#include<iostream>
using namespace std;
#define MAX 100
int arr[MAX];
int main(){ 
    int n;
    
    do{
    cout << "Enter the number of operation you want to perform" << endl;
    cout << "1.Create"<< endl << "2.Display"<< endl << "3.Insert" << endl << "4.Delete" << endl << "5.Linear Search" <<endl<< "6.Exit"<<endl; 
    cin >> n;
    switch(n){
        case 1:
        int x;
        cout<<"Enter the number of elements:"<< endl;
        cin >> x;
        for(int i=0;i<x;i++){
            cin >> arr[i];
        }
        break;

        case 2:
        cout << "Array elements:";
        for(int i=0;i<x;i++){
            cout << arr[i] << " "; 
        } 
        break;

        case 3:
        int pos,val;
        cout << "Enter position and value to insert:"<<endl;
        cin >> pos>>val;
        for(int i=x;i>pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=val;
        x++;
        break;

        case 4:
        int pos2;
        cout << "Enter position to delete"<< endl;
        cin >> pos2;
        for(int i=pos2;i<x-1;i++){
            arr[i]=arr[i+1];
        }
    x--;
    break;
        
       case 5:{
       int ele,found=0;
       cout << "Enter element to search:"<<endl;
       cin >> ele;
       for(int i=0;i<x;i++){
        if(arr[i]==ele){
            cout << "Element found at position " << i+1 << endl;
            found=1;
        }
       }
       if(found==0) cout<< "Element not found"<<endl;
        break;
       } 
        case 6:
        cout<<"Exiting."<<endl;
        break;
        default:
    cout<<"Invalid number."<<endl; 
    }
}while(n!=6);
    return 0;
}

//QUESTION 2
#include<iostream>
using namespace std;
int main(){
    int n;
    cout <<"Enter the no. of elements:";
    cin>>n;
    int arr[n];
     cout << "Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                for(int k=j+1;k<n-1;k++){
                    arr[k-1]=arr[k];
                }
            n--;
            j--;
            }
        }
    }
cout << "Array after removing duplicate elements is:"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<< " ";
    }
    return 0;
} 

//QUESTION 3
// THE OUTPUT OF THE GIVEN PROGRAM IS 10000

//QUESTION 4
//PART A
#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter no. of elements:";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array:";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    // Reversing elements of array
    for(int i=0;i<n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    cout << "Array after reversing its elements:";
    for(int i=0;i<n;i++){
        cout << arr[i]<< " ";
    }
    return 0;
}

//PART B

#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout << "Enter no. of rows and columns of first array";
    cin >> n >> m;
    int arr[n][m];
    cout << "Enter elements of first array:";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
     int p,q;
    cout << "Enter no. of rows and columns of second array";
    cin >> p >> q;
    int brr[p][q];
    cout << "Enter elements of second array:";
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin >> brr[i][j];
        }
    }
    // Multiplication
    int res[n][q];
    if(m!=p) cout << "Multiplication not possible!";
    int k=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            res[i][j]=0;
            for(int k=0;k<m;k++){
                res[i][j]+= arr[i][k]*brr[k][j];
            }
        }
    }
    cout << "Product of matrices is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            cout << res[i][j] << " ";
        }
    cout <<endl;
    }
    return 0;
}

//PART C

#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout << "Enter rows and columns of array:";
    cin >> n >> m ;
    int arr[n][m];
    cout << "Enter elements of array:";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        } 
    }
    //Transpose
    int t[m][n];   // can do it in same matrix but it is valid only for square matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           t[j][i]=arr[i][j];
    }
    }
    cout << "Array after transpose:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << t[i][j]<<" ";
        }
    cout << endl;
    }
    return 0;
}


//QUESTION 5

#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout << "Enter no. of rows and columns:";
    cin >> n >> m;
    int arr[n][m];
    cout << "Enter elements of array:";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    // sum of every row
    int sum;
    for(int i=0;i<n;i++){
     sum=0;
        for(int j=0;j<m;j++){
          sum+=arr[i][j];
        }
    cout << "Sum of row " << i+1 << " is " << sum<<endl;;
   }
   // sum of every column
   for(int j=0;j<m;j++){
    sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i][j];
    }
    cout << "Sum of column "<< j+1 << "is " << sum << endl;
   }
    return 0;
}



