#include <bits/stdc++.h>
using namespace std;

class StateOfHealth{
    public:
        int present_capacity;
        int rated_capacity;
    
    StateOfHealth(int pr_cap, int rat_cap){
        present_capacity = pr_cap;
        rated_capacity = rat_cap;
    }
    
    double calSOH(int pr_capacity, int rat_capacity){
        double temp = 100 * pr_capacity / (double) rat_capacity;
        
        return temp;
    }
    
};

int main()
{
    int healthy=0, exchange=0, failed=0;
    
    vector<StateOfHealth> batteries;
    
    int n;
    cout<<"Enter the number of batteries : ";
    cin>>n;
    
    cout<<"Enter each battery present capacity followed by rated capacity "<<endl;
    
    for(int i=0;i<n;i++)
    {
        int pr_cap;
        int rat_cap;
        
        cin>>pr_cap;
        cin>>rat_cap;
        
        if(rat_cap==0){
            cout<<"Rated capacity can't be zero "<<endl;
            i--;
            
        }
        else{
            StateOfHealth battery = StateOfHealth(pr_cap, rat_cap);
            batteries.push_back(battery);
        }
        
    }
    
    
    for(auto it : batteries)
    {
        double battery_soh = it.calSOH(it.present_capacity, it.rated_capacity);
        
        if(battery_soh>=80.0)
        {
            healthy++;
        }
        else if(battery_soh>=62.0)
        {
            exchange++;
        }
        else{
            failed++;
        }
    }
    
    cout<<"Healthy batteries : "<<healthy<<endl;
    cout<<"Exchange batteries : "<<exchange<<endl;
    cout<<"Failed batteries : "<<failed<<endl;
    return 0;
}
