#include <bits/stdc++.h>
using namespace std;
class Activity{
public:
    int id;
    int startTime;
    int endTime;
    Activity(){
    }
    Activity(int startTime,int endTime){
        this->startTime=startTime;
        this->endTime=endTime;
    }
};

void printActivityArray(Activity*arrayOfActivites,int numberOfActivities){
        cout<<"***********************************"<<endl;
        for(int i=0;i<numberOfActivities;i++){
            cout<<"("<<arrayOfActivites[i].id<<","<<arrayOfActivites[i].startTime<<","<<arrayOfActivites[i].endTime<<") ";

        }
        cout<<endl<<"***********************************"<<endl;
}

void greedyActivitySelector(Activity* activityList, int activityListSize ){
    int n=activityListSize;
    int k=0;
    cout<<"*********************SELECTED ACTIVITIES*******************************"<<endl;
    cout<<"("<<activityList[k].startTime<<","<<activityList[k].endTime<<") ";

    for (int m=1;m<n;m++){
        if(activityList[m].startTime>=activityList[k].endTime){
                cout<<"("<<""<<activityList[m].startTime<<","<<activityList[m].endTime<<") ";
                k=m;
        }
    }
    cout<<endl<<"*********************SELECTED ACTIVITIES *******************************"<<endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    int numberOfActivities;
    cin>>numberOfActivities;
    Activity arrayOfActivites[numberOfActivities];

    for(int i=0;i<(numberOfActivities);i++){
        int startTime,endTime;
        cin>>startTime;
        cin>>endTime;
        arrayOfActivites[i] = Activity(startTime,endTime);
    }
    //Printing the contents of the Activity Array
    printActivityArray(arrayOfActivites,numberOfActivities);
    greedyActivitySelector(arrayOfActivites,numberOfActivities);
    return 0;
}



