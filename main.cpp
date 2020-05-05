#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Algorithms
{
public:
    void firstFit(int part[], int m, int job[], int n)
{

    int track[n];
    for(int i =0; i<n; i++)
        track[n]=-1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (part[j] >= job[i])
            {
                track[i] = j;
                part[j] -= job[i];
    
                break;
            }
        }
    }
    
    cout<<"******************** FIRST FIT ****************************"<<endl;
    cout << "Job Num \t Partition Assignment \t Waste \t\t Job State"<<endl;
    string status=" ";
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << setw(20);
        if (track[i] != -1)
        { cout << track[i] + 1<< setw(20) <<job[i]; status= "Running";  sum +=job[i];}
        else
        {cout << " - "<<setw(20) << " - "<<setw(20); status="Waiting";}
        cout << setw(15)<<status<<endl;
    }
    cout<< "Total Waste: "<<sum<<endl;
    cout<<"*****************************************************"<<endl<<endl;
    
    }
    
    void bestFit(int part[], int m, int job[], int n)
    {
    int track[n];
    for(int i =0; i<n; i++)
        track[n]=-1;
    
    for (int i=0; i<n; i++)
    {
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (part[j] >= job[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (part[bestIdx] > part[j])
                    bestIdx = j;
            }
        }
        
        if (bestIdx != -1)
        {
            track[i] = bestIdx;
            
            part[bestIdx] -= job[i];
        }
    }
    cout<<"******************** BEST FIT ****************************"<<endl;
    cout << "Job Num \t Partition Assignment \t Waste \t\t Job State"<<endl;
    string status=" ";
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << setw(20);
        if (track[i] != -1)
        { cout << track[i] + 1<< setw(20) <<job[i]; status= "Running";  sum +=job[i];}
        else
        {cout << " - "<<setw(20) << " - "<<setw(20); status="Waiting";}
        cout << setw(15)<<status<<endl;
    }
    cout<<"*****************************************************"<<endl<<endl;
    
        }
    
void nextFit(int part[], int m, int job[], int n)
{
    int track[n], j=0;
    for(int i =0; i<n; i++)
        track[n]=-1;
    

    for (int i = 0; i < n; i++) {
        
        while (j < m) {
            
            if (part[j] >= job[i]) {
            track[i] = j;
                
                part[j] -= job[i];
                
                break;
            }

            j = (j + 1) % m;
        }
    }
    
        cout<<"******************** NEXT FIT ****************************"<<endl;
        cout << "Job Num \t Partition Assignment \t Waste \t\t Job State"<<endl;
        string status=" ";
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            cout << " " << i+1 << setw(20);
            if (track[i] != -1)
            { cout << track[i] + 1<< setw(20) <<part[i]; status= "Running";  sum +=job[i];}
            else
            {cout << " - "<<setw(20) << " - "<<setw(20); status="Waiting";}
            cout << setw(15)<<status<<endl;
        }
        cout<<"*****************************************************"<<endl<<endl;
    }
    
    void worstFit(int part[], int m, int job[],int n)
{
    int track[n];
    for(int i =0; i<n; i++)
        track[n]=-1;

    for (int i=0; i<n; i++)
    {
        int wstIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (part[j] >= job[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (part[wstIdx] < part[j])
                    wstIdx = j;
            }
        }
        
        if (wstIdx != -1)
        {
            track[i] = wstIdx;
            part[wstIdx] -= job[i];
        }
    }
    

    
    cout<<"******************** WORST FIT ****************************"<<endl;
    cout << "Job Num \t Partition Assignment \t Waste \t\t Job State"<<endl;
    string status=" ";
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << setw(20);
        if (track[i] != -1)
        { cout << track[i] + 1<< setw(20) <<part[i]; status= "Running";  sum +=job[i];}
        else
        {cout << " - "<<setw(20) << " - "<<setw(20); status="Waiting";}
        cout << setw(15)<<status<<endl;
    }
    cout<< "Total Waste: "<<sum<<endl;
    cout<<"*****************************************************"<<endl<<endl;
}

    
};

int main()
{
    cout<<"How many Partitons would you like to add?"<<endl;
    int pSize;
    cin>>pSize;
    int p[pSize];
    
    cout<<"What will be the size of each Partiton ?"<<endl;
    for(int i=0; i<pSize; i++)
    {
        int a;
        cin>>a;
        p[i]=a;
    }
    
    cout<<"How many Jobs would you like to add?"<<endl;
    int jSize;
    cin>>jSize;
    int j[jSize];
    
    cout<<"What will be the memory needed for each job"<<endl;
    for(int i=0; i<jSize; i++)
    {
        int a;
        cin>>a;
        j[i]=a;
    }
    
    Algorithms Firstfit;
    
    Firstfit.firstFit(p,pSize,j,jSize);
    Firstfit.bestFit( p,pSize,j,jSize);
    Firstfit.nextFit(p,pSize,j,jSize);
    Firstfit.worstFit(p,pSize,j,jSize);

    
}

/*
 
 ******************** FIRST FIT ****************************
 Job Num          Partition Assignment    Waste           Job State
 1                   2                 150        Running
 2                   3                 250        Running
 3                   1                  50        Running
 Total Waste: 450
 *****************************************************
 
 ******************** BEST FIT ****************************
 Job Num          Partition Assignment    Waste           Job State
 1                   2                 150        Running
 2                   3                 250        Running
 3                   1                  50        Running
 *****************************************************
 
 ******************** NEXT FIT ****************************
 Job Num          Partition Assignment    Waste           Job State
 1                   2                 100        Running
 2                   3                  50        Running
 3                   3                   0        Running
 *****************************************************
 
 ******************** WORST FIT ****************************
 Job Num          Partition Assignment    Waste           Job State
 1                   2                  50        Running
 2                   3                  50        Running
 3                   1                   0        Running
 Total Waste: 450
 *****************************************************
 

 */

