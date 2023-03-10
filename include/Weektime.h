#ifndef WEEKTIME_H
#define WEEKTIME_H

#include <Arduino.h>
#include <stdint.h>

enum DayOfWeek {
    MONDAY = 0,
    TUESDAY = 1,
    WEDNESDAY = 2,
    THURSDAY = 3,
    FRIDAY = 4,
    SATURDAY = 5,
    SUNDAY = 6
};

extern uint8_t FirstWeekday;

class Weektime
{
private:
    int32_t Weekday;
    int32_t Hour;
    int32_t Minute;
    int32_t Second;
    int32_t Milli;

public:
    Weektime(int32_t weekday=0, int32_t hour=0, int32_t minute=0, int32_t second=0, int32_t milli=0);
    Weektime(const Weektime& other);
    void set(int32_t weekday=0, int32_t hour=0, int32_t miute=0, int32_t second=0, int32_t milli=0);
    Weektime start_of_day() const;
    int32_t weekday() const;
    int32_t hour() const;
    int32_t minute() const;
    int32_t second() const;
    int32_t milli() const;
    Weektime& operator=(const Weektime& other);
    Weektime operator+(const Weektime& other) const;
    Weektime operator-(const Weektime& other) const;
    bool operator==(const Weektime& other) const;
    bool operator>(const Weektime& other) const;
    bool operator<(const Weektime& other) const;
    bool operator>=(const Weektime& other) const;
    bool operator<=(const Weektime& other) const;
    int32_t to_millis() const;
    String to_string() const;
};

#endif