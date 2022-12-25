#include <iostream>
#include <ctime>
#include <string.h>
#include "Date.h"

using namespace std;

Date :: Date(){}
Date :: ~Date(){}
void Date ::today(){
    time_t baygio = time(0);  
    tm *ltm = localtime(&baygio);
    this->Y = 1900 + ltm->tm_year;
    this->M = 1 + ltm->tm_mon;
    this->D = ltm->tm_mday;
}
Date Date ::SetDayFromStr(string x){
    string x1[3];
    int j = 0;
    int k = x.size();
    for(int i = 0; i < k; i++){
        if(x[i] != '-'){
            x1[j] += x[i];
        }else{
            j++;
        }
    }
    this->D = atoi(x1[0].c_str());
    this->M = atoi(x1[1].c_str());
    this->Y = atoi(x1[2].c_str());
    return (*this);
}
string Date ::SetDayFromNum(){
    string a;
    a = to_string(this->D) + "-" + to_string(this->M) + "-" + to_string(this->Y);
    return a;
}
istream &operator >> (istream &is, Date &s1){
    cout << endl;
    cout << "\t\t\t- Day: "; is >> s1.D;
    cout << "\t\t\t- Month: "; is >> s1.M;
    cout << "\t\t\t- Year: "; is >> s1.Y;
    return is;
}
ostream &operator << (ostream &os, const Date &s1){
    cout << s1.D << "/" << s1.M << "/" << s1.Y;
    return os;
}
bool Date ::operator==(const Date &s1){
    if(s1.D == this->D && s1.M == this->M && s1.Y == this->Y){
        return true;
    }else{
        return false;
    }
}
Date Date ::operator+(int Month){
    int Day31[7] = {1, 3, 5, 7, 8, 10, 12};
    int Day30[4] = {4, 6, 9, 11};
    Date b;
    if(Month == 12){
        b.D = this->D;
        b.M = this->M;
        b.Y = this->Y + 1;
    }else{
        int k = this->M + Month;
        b.D = this->D;
        if(b.M > 12 && b.M < 24){
            b.M = k - 12;
            b.Y = this->Y++;
        }else if(b.M > 24){
            b.M = k - 24;
            b.Y = this->Y + 2;
        }
        if(b.D == 31){
            if(b.M == 4 || b.M == 6 || b.M == 9 || b.M == 11){
                b.M++;
                b.D = 1;
            }if(b.M == 2){
                b.M ++;
                b.D = 3;
            }
        }
        if(b.D == 30 && b.M == 2){
            b.M ++;
            b.D = 2;
        }
    }
    return b;
}
bool Date :: operator > (const Date &s1){
    if(this->Y > s1.Y){
        return true;
    }else if( this-> Y == s1.Y){
        if(this->Y > s1.Y){
            return true;
        }else if(this->Y < s1.Y){
            return false;
        }else if(this-> Y == s1.Y){
            if(this->D >= s1.D){
                return true;
            }else{
                return false;
            }
        }
    }
}