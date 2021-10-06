#include<iostream>

using namespace std;

int fac(int n){
    if (n == 1 || n==0)
    {
        return 1;
    }
    else{
        return n*fac(n-1);
    }
}

int main() {
    int n;
    cout<<"Enter a number of which you want to get the factorial : ";
    cin>>n;
    cout<<"The factorial of "<<n<<" is "<<fac(n)<<endl;
    return 0;
}