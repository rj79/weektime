#include "Weektime.h"

#ifndef min
#define min(x, y) x < y ? x : y
#endif

#ifndef max
#define max(x, y) x > y ? x : y
#endif

const char* _weekdays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

uint8_t FirstWeekday = MONDAY;

Weektime::Weektime(int32_t weekday, int32_t hour, int32_t minute, int32_t second, int32_t milli):
    Weekday(weekday),
    Hour(hour),
    Minute(minute),
    Second(second),
    Milli(milli)
{
    set(Weekday, Hour, Minute, Second, Milli);
}

Weektime::Weektime(const Weektime& other)
{
    Weekday = other.Weekday;
    Hour = other.Hour;
    Minute = other.Minute;
    Second = other.Second;
    Milli = other.Milli;
}

void Weektime::set(int32_t weekday, int32_t hour, int32_t minute, int32_t second, int32_t milli)
{
    Weekday = weekday % 7;
    Hour = hour % 24;
    Minute = minute % 60;
    Second = second % 60;
    Milli = milli % 1000;
}

Weektime Weektime::start_of_day() const {
    return Weektime(Weekday);
}

int32_t Weektime::weekday() const
{
    return Weekday;
}

int32_t Weektime::hour() const
{
    return Hour;
}

int32_t Weektime::minute() const
{
    return Minute;
}

int32_t Weektime::second() const
{
    return Second;
}

int32_t Weektime::milli() const
{
    return Milli;
}

Weektime& Weektime::operator=(const Weektime& other)
{
    Weekday = other.Weekday;
    Hour = other.Hour;
    Minute = other.Minute;
    Second = other.Second;
    Milli = other.Milli;
    return *this;
}

Weektime Weektime::operator+(const Weektime& other) const
{
    int32_t ms = Milli;
    int32_t s = Second;
    int32_t m = Minute;
    int32_t h = Hour;
    int32_t w = Weekday;

    ms += other.Milli;
    while (ms >= 1000) {
        ms -= 1000;
        s += 1;
    }
    s += other.Second;
    while (s >= 60) {
        s -= 60;
        m += 1;
    }
    m += other.Minute;
    while (m >= 60) {
        m -= 60;
        h += 1;
    }
    h += other.Hour;
    while (h >= 24) {
        h -= 24;
        w += 1;
    }
    w += other.Weekday;
    while (w >= 7) {
        w -= 7;
    }
    return Weektime(w, h, m, s, ms);
}

Weektime Weektime::operator-(const Weektime& other) const
{
    int32_t ms = Milli;
    int32_t s = Second;
    int32_t m = Minute;
    int32_t h = Hour;
    int32_t w = Weekday;

    ms -= other.Milli;
    while (ms < 0) {
        ms += 1000;
        s -= 1;
    }
    s -= other.Second;
    while (s < 0) {
        s += 60;
        m -= 1;
    }
    m -= other.Minute;
    while (m < 0) {
        m += 60;
        h -= 1;
    }
    h -= other.Hour;
    while (h < 0) {
        h += 24;
        w -= 1;
    }
    w -= other.Weekday;
    while (w < 0) {
        w += 7;
    }
    return Weektime(w, h, m, s, ms);
}

bool Weektime::operator==(const Weektime& other) const
{
    return (Milli == other.Milli) &&
    (Second == other.Second) &&
    (Minute == other.Minute) &&
    (Hour == other.Hour) &&
    (Weekday == other.Weekday); 
}

bool Weektime::operator>(const Weektime& other) const
{
    return to_millis() > other.to_millis();
}

bool Weektime::operator<(const Weektime& other) const
{
    return to_millis() < other.to_millis();
}

bool Weektime::operator>=(const Weektime& other) const
{
    return to_millis() >= other.to_millis();
}

bool Weektime::operator<=(const Weektime& other) const
{
    return to_millis() <= other.to_millis();
}

int32_t Weektime::to_millis() const 
{
    return ((((Weekday * 24 + Hour) * 60 + Minute) * 60 + Second) * 1000 + Milli);
}

String Weektime::to_string() const
{
    char s[64];
    uint8_t day = (Weekday + FirstWeekday) % 7;
    snprintf(s, sizeof(s), "%s %02i:%02i:%02i.%03i", _weekdays[day], Hour, Minute, Second, Milli);
    return String(s);
}
