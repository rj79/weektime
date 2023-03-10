# About
Library for working with week-based time definitions. The Weektime is defined by the tuple (weekday, hour, minute, second, millisecond).
Useful for things like alarm clocks and other applications that work with week-based time definitions.

# Usage
```C++
// Second day of week, 10 hours, 15 minutes, 30 seconds, 600 milliseconds
Weektime w(1, 10, 15, 30, 600);
w.weekday();   // Returns 1
w.hour();      // Returns 10
w.minute();    // Returns 15
w.second();    // Returns 30
w.milli();    // Returns 600

// Addition
Weektime delta(1, 2, 10, 40, 20);
Weektime w2 = w + delta;

w2.weekday();  // Returns 2
w2.hour();     // Returns 12
w2.minute();   // Returns 26
w2.second();   // Returns 10
w2.milli();    // Returns 620

// Subtraction
Weektime w3 = w - delta;
w3.weekday();  // Returns 0
w3.hour();     // Returns 8
w3.minute();   // Returns 4
w3.second();   // Returns 50
w3.milli();    // Returns 580

// Comparison
w == w;        // Evaluates to true
w2 > w;        // Evaluates to true
w2 <= w3;      // Evaluates to false

// Return Weektime object corresponding to start of day
Weektime sod = w.start_of_day();
sod.weekday(); // Returns 2
sod.hour();    // Returns 0
sod.minute();  // Returns 0
sod.second();  // Returns 0
sod.milli();   // Returns 0

// Convert to milliseconds since start of week
w.to_millis(); // Returns 123330600

// Convert to string
w.to_string(); // Returns "Tue 10:15:30.600"
```

### Wrap around
When adding or subtracting two Weektime objects and the result would end up in the "next" or "previous" week, the result will wrap around.
```C++
// Example of wraparound when subtracting
Weektime w(0, 0, 0, 0, 0);
Weektime delta(0, 0, 0, 0, 1);
Weektime w2 = w - delta;
w2.weekday();  // Returns 6
w2.hour();     // Returns 23
w2.minute();   // Returns 59
w2.second();   // Returns 59
w2.milli();    // Returns 999

// Example of wraparound when adding
Weektime w3 = w2 + delta;
w2.weekday();  // Returns 0
w2.hour();     // Returns 0
w2.minute();   // Returns 0
w2.second();   // Returns 0
w2.milli();    // Returns 0
```

### First day of week
There is a global variable called FirstWeekday which can be set to control the formatting of ```to_string()```. FirstWeekday has no impact on Weektime arithmetics or comparators. The default FirstWeekday value is MONDAY. Changing the day can be done as follows:
```C++
FirstWeekday = SUNDAY;
Weektime w(0, 8, 15, 0, 200);
w.to_string(); // Will return "Sun 08:15:00.200"
```

