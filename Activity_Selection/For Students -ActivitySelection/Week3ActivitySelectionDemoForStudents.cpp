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


bool compareEndTime(const Activity& a1, const Activity& a2) {
    return a1.endTime < a2.endTime;
}


void printActivityArray(const vector<Activity>& arrayOfActivites,int numberOfActivities){
        cout<<"***********************************"<<endl;
        for(int i=0;i<numberOfActivities;i++){
            cout<<"("<<arrayOfActivites[i].id<<","<<arrayOfActivites[i].startTime<<","<<arrayOfActivites[i].endTime<<") ";

        }
        cout<<endl<<"***********************************"<<endl;
}

void greedyActivitySelector(const vector<Activity>& activityList) {
    int n = activityList.size();
    if (n == 0) {
        return;
    }

    int k = 0;
    cout << "*********************SELECTED ACTIVITIES*******************************" << endl;
    cout << "(" << activityList[k].startTime << "," << activityList[k].endTime << ") ";

    for (int m = 1; m < n; m++) {
        if (activityList[m].startTime >= activityList[k].endTime) {
            cout << "(" << activityList[m].startTime << "," << activityList[m].endTime << ") ";
            k = m;
        }
    }

    cout << endl << "*********************SELECTED ACTIVITIES *******************************" << endl;


int main(){
    freopen("in.txt", "r", stdin);
    int numberOfActivities;
    cin>>numberOfActivities;
    vector<Activity> activities;

    // Read activities from input
    for (int i = 0; i < numberOfActivities; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        activities.push_back(Activity(startTime, endTime));
    }

    sort(activities.begin(), activities.end(),compareEndTime);

    //  sort(arrayOfActivities, arrayOfActivities + numberOfActivities, compareEndTime); For Array sort
    // sending array to another function recive as pointer like Type* nameofarray
    //Printing the contents of the Activity Array
    printActivityArray(arrayOfActivites,numberOfActivities);
    greedyActivitySelector(arrayOfActivites,numberOfActivities);
    return 0;
}



