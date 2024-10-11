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
    int8_t Weekday;
    int8_t Hour;
    int8_t Minute;
    int8_t Second;
    int16_t Milli;

public:
    Weektime(int8_t weekday=0, int8_t hour=0, int8_t minute=0, int8_t second=0, int16_t milli=0);
    Weektime(const Weektime& other);
    void set(int8_t weekday=0, int8_t hour=0, int8_t miute=0, int8_t second=0, int16_t milli=0);
    Weektime start_of_day() const;
    int8_t weekday() const;
    int8_t hour() const;
    int8_t minute() const;
    int8_t second() const;
    int16_t milli() const;
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