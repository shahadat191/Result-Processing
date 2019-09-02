/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */

#include<iostream>
#include<algorithm>
#include<iomanip>

#define input           freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output          freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)
using namespace std;


struct student{
    int id;
    double marks[10];
    double fres;
    student(){
        fres = 0.0;
        for(int i = 1; i <= 8; i++)
            marks[i] = 0.0;
    }
    
    bool operator < (const student& b)const{
        return fres > b.fres;
    }
};

double credit[] = {0.0, 19.00, 20.00, 18.75, 21.00, 20.75, 21.00, 20.00, 19.50};

int main(){
    input;
    output;
    student ict[50];
    for(int i = 1; i <= 38; i++){
        cin >> ict[i].id;
    }
    
    double totalCredit = 0.0;
    for(int i = 1; i <= 7; i++)
        totalCredit += credit[i];
    
    for(int sem = 1; sem <= 7; sem++){
        for(int i = 1; i <= 38; i++){
            cin >> ict[i].marks[sem];
        }
    }
    
    for(int i = 1; i <= 38; i++){
        double fres = 0.0;
        for(int j = 1; j <= 8; j++){
            if(j == 8){
                continue;
            }
            fres += credit[j] * ict[i].marks[j];
        }
        ict[i].fres = fres / totalCredit;
    }
    sort(ict + 1, ict + 38 + 1);

    
    cout <<"----------------------------------------------------------------------------------------------------------------------------------\n";
    printf("| Rank  |     ID     |    1st    |    2nd    |    3rd    |     4th   |    5th    |    6th    |    7th    |    8th    |    CGPA   |\n");
    cout <<"----------------------------------------------------------------------------------------------------------------------------------\n";
    for(int i = 1; i <= 38; i++){
        cout << "|  " << setw(2) << i << "   |";
        cout << "  " << ict[i].id << "   |";
        double fres = 0.0;
        for(int j = 1; j <= 8; j++){
            cout << fixed << setprecision(2);
            if(j == 8){
                cout <<"    _.__   |";
                continue;
            }
            cout <<"    "<< ict[i].marks[j] << "   |";
            fres += credit[j] * ict[i].marks[j];
        }
        cout <<"    "<< ict[i].fres << "   |" << endl;
        cout <<"----------------------------------------------------------------------------------------------------------------------------------\n";
    }

}


