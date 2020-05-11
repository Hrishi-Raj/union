#include<bits/stdc++.h>
using namespace std;

vector<int>test[10];
int temp[10];
int nodes=3;
 


void create(int x,int y)
{
    test[x].push_back(y);
    // test[y].push_back(x);

}




int find(int i)
{
    if (temp[i] == -1)  
        return i;  
    return find( temp[i]);


}
void Union(int x,int y)
{
     int xset = find(x);  
    int yset = find(y);  
    if(xset != yset) 
    {  
        temp[xset] = yset;  
    }

}


int cycle()
{
    for(int i=0;i<nodes;i++)
       temp[i]=-1;

    for(int i=1;i<=nodes;i++)
    {
        
        for(int j=0;j<test[i].size();j++)
        {
            int x = find(i); 
            cout<<i;
           
           int y = find(test[i][j]);  
           cout<<test[i][j]<<endl;
           
  
         if (x == y)  
            return 1;  
  
          Union(x,y);  
            
        }
    }



        
    return 0;  


}

int main()
{

  create(1,2);
  create(1,3);
//   create(3,2);


    if (cycle())  
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";  

    return 0;

}