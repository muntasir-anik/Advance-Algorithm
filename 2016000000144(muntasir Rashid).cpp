#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ,m ;
    int horseman,butter;
    while(cin >> n >> m)
    {
        horseman = 0;
        butter = 0;
        for(int i = n+1; i < m; i++){
            if(i%3==0)
                horseman+=1;
            if (i%7==0)
                butter+=2;
        }
        if(horseman == butter)
            cout << "DRAW" << endl;
        else if(horseman > butter)
            cout << "BoJack Rocks !!!" << endl;
        else
            cout << "Mr. Peanutbutter Rules !!!" << endl;
    }
}
