#include<iostream>
using namespace std;

class Time {
private:
    long int m_time_raw;
public:
    Time() {
        this->m_time_raw = 0;
    }

    Time(int sec) {
        this->m_time_raw = sec;
    }

    void show() {
        int hour = m_time_raw / 3600;
        int minuts = (m_time_raw - (hour * 3600)) / 60;
        int second = (m_time_raw - (hour * 3600) - (minuts * 60));
        cout << "Duration: " << hour << "Hr : " << minuts << "Min: " << second << "Sec " << endl;
    }

    void add(Time& other) {
        this->m_time_raw += other.m_time_raw;
    }

    void setRaw(int sec){
        this->m_time_raw = sec;
    }

    Time operator+(Time& other) {
        return Time(this->m_time_raw + other.m_time_raw);
    }
};

int main() {
    Time time(3661);
    time.show();
    Time f(62);
    time = time + f;
    time.show();
}