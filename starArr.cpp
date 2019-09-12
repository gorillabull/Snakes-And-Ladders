



#include <climits>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>


using namespace std;



int main(){
    vector<pair<int,int>> ResPairs; //store final pairs 
    vector<pair<int,int>> AllPairs;

    //s = 50 
    int s = 50; 
    //init pairs 
    for (size_t i = 1; i <= 50 ; i++)
    {
        for (size_t j = 1; j <= 50 ; j++)
        {
            pair<int,int> p = make_pair(i,j);
            AllPairs.push_back(p    );


        }
        
    }
    cout<<AllPairs.size()<<endl;
    
    for(pair<int,int> &x : AllPairs){
        int A,B;
        A=B=1;

        for (size_t i = 1; i <= 50 ; i++){
            A = x.first * i;
            for (size_t j = 1; j <= 50 ; j++)
            {
               B = x.second*  i;
                if (A+B == s)
                {
                    ResPairs.push_back(make_pair(A,B));
                }
            }
            
            

            
        }
         
       
        
    }
    
    cout<<ResPairs.size();
    for(pair<int,int> &a : ResPairs){
        cout<<a.first<< " "<<a.second<<endl;
    }
    
    return 0; 
}