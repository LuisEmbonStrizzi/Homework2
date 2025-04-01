#pragma once

#include <string>

using namespace std;

class DetermineTime {
    private: 
        int hrs;
        int mins;
        int secs;
        string part_day;
    
    public:
        DetermineTime();
        DetermineTime(int HHh);
        DetermineTime(int HHh, int MMm);
        DetermineTime(int HHh, int MMm, int SSs);
        DetermineTime(int HHh, int MMm, int SSs, string part_day);
    
        void setHour(int h);
        void setMins(int m);
        void setSecs(int s);
        void setPartOfDay(string part_day);
    
        int getHour() const;
        int getMins() const;
        int getSecs() const;
        string getPartOfDay() const;
    
        void showTime() const;
        void showTime24h() const;
};

