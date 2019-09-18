#include <iostream>
using namespace std;

class List{
    int arr[100];
    int siz = 0;
    int c=0;

public:

    int add(int x){
        arr[siz] = x;
        siz++;
    }

    int len(){
        return siz;
    }

    void Remove(int rem){
        /**remove x if x is on the array
        //i.e. if array = {10, 20, 30, 40, 50}
        //then calling remove(20) will result in
        //array = {10, 30, 40, 50}
        //remove(5) won't change the array, as 5 is not in the array
        //array = {10, 30, 40, 50}*/
        c=0;
        bool flag=false;

        for(int x=0; x<siz; x++)
        {

            if(arr[x]==rem)
            {

               x++;
               flag=true;


            }
            else{
               arr[c]=arr[x];
               c++;

            }
        }
        c++;

        if(!flag)
        {
            c--;
            cout<< "Elemenet not found"<<endl;
        }
        else
        {
            cout<<"Remove successfully"<<endl;
        }
        //std::fill( std::begin( arr ), std::end( arr ), 0 );
       //cout<<sizeof(arr)<<endl;

    }

    void removeIndex(int a){

        //remove a-th element if array size > a
        //i.e. if array = {10, 20, 30, 40, 50}
        //then calling removeIndex(2) will result in
        //deleting array[2] = 30
        //so resulting array = {10, 20, 40, 50}
        //remove(5) won't change the array, as size of array is 4
        //array = {10, 20, 40, 50}
    }

    void print(){
        //will print every elements of the array
        for(int x=0; x<siz;x++)
        {
            if(arr[x]!=NULL)
            cout<<arr[x]<<" ";
        }
    }
};

int main(){
    List l;
    l.add(10);//l = {10}
    l.add(20);//l = {10, 20}
    l.add(30);//l = {10, 20, 30}
    l.add(40);//l = {10, 20, 30, 40}
    l.add(50);//l = {10, 20, 30, 40, 50}
    l.Remove(40);//l = {10, 20, 30, 50}
    l.removeIndex(1);//l = {10, 30, 50}
    l.removeIndex(1);//l = {10, 50}
    l.print();
    //will output
    //10 50
}
