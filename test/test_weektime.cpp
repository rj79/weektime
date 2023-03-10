#include "unity.h"
#include "Weektime.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_weektime_is_default_zero() 
{
  Weektime w;
  TEST_ASSERT_EQUAL(0, w.weekday());
  TEST_ASSERT_EQUAL(0, w.hour());
  TEST_ASSERT_EQUAL(0, w.minute());
  TEST_ASSERT_EQUAL(0, w.second());
  TEST_ASSERT_EQUAL(0, w.milli());
}

void test_constructor_with_parameters() 
{
  Weektime w(1, 2, 3, 4, 5);
  TEST_ASSERT_EQUAL(1, w.weekday());
  TEST_ASSERT_EQUAL(2, w.hour());
  TEST_ASSERT_EQUAL(3, w.minute());
  TEST_ASSERT_EQUAL(4, w.second());
  TEST_ASSERT_EQUAL(5, w.milli());
}

void test_constructor_with_wraparound() 
{
  Weektime w(8, 26, 63, 64, 1005);
  TEST_ASSERT_EQUAL(1, w.weekday());
  TEST_ASSERT_EQUAL(2, w.hour());
  TEST_ASSERT_EQUAL(3, w.minute());
  TEST_ASSERT_EQUAL(4, w.second());
  TEST_ASSERT_EQUAL(5, w.milli());
}

void test_copy_constructor() 
{
  Weektime w1(1, 2, 3, 4, 5);
  Weektime w2(w1);
  TEST_ASSERT_EQUAL(1, w2.weekday());
  TEST_ASSERT_EQUAL(2, w2.hour());
  TEST_ASSERT_EQUAL(3, w2.minute());
  TEST_ASSERT_EQUAL(4, w2.second());
  TEST_ASSERT_EQUAL(5, w2.milli());
}

void test_set()
{
  Weektime w;
  w.set(1, 2, 3, 4, 5);
  TEST_ASSERT_EQUAL(1, w.weekday());
  TEST_ASSERT_EQUAL(2, w.hour());
  TEST_ASSERT_EQUAL(3, w.minute());
  TEST_ASSERT_EQUAL(4, w.second());
  TEST_ASSERT_EQUAL(5, w.milli());
}

void test_set_with_wraparound() 
{
  Weektime w(8, 26, 63, 64, 1005);
  TEST_ASSERT_EQUAL(1, w.weekday());
  TEST_ASSERT_EQUAL(2, w.hour());
  TEST_ASSERT_EQUAL(3, w.minute());
  TEST_ASSERT_EQUAL(4, w.second());
  TEST_ASSERT_EQUAL(5, w.milli());
}

void test_start_of_day() 
{
  Weektime w(3, 10, 11, 12, 999);
  Weektime d = w.start_of_day();
  TEST_ASSERT_EQUAL(3, d.weekday());
  TEST_ASSERT_EQUAL(0, d.hour());
  TEST_ASSERT_EQUAL(0, d.minute());
  TEST_ASSERT_EQUAL(0, d.second());
  TEST_ASSERT_EQUAL(0, d.milli());
}

void test_assign() 
{
  Weektime w1(3, 10, 11, 12, 999);
  Weektime w2 = w1;
  TEST_ASSERT_EQUAL(3, w2.weekday());
  TEST_ASSERT_EQUAL(10, w2.hour());
  TEST_ASSERT_EQUAL(11, w2.minute());
  TEST_ASSERT_EQUAL(12, w2.second());
  TEST_ASSERT_EQUAL(999, w2.milli());
}

void test_add() 
{
  Weektime w1(1, 23, 59, 59, 999);
  Weektime w2(0, 1, 1, 1, 2);
  Weektime w3 = w1 + w2;
  TEST_ASSERT_EQUAL(2, w3.weekday());
  TEST_ASSERT_EQUAL(1, w3.hour());
  TEST_ASSERT_EQUAL(1, w3.minute());
  TEST_ASSERT_EQUAL(1, w3.second());
  TEST_ASSERT_EQUAL(1, w3.milli());  
}

void test_add_wraparound() 
{
  Weektime w1(6, 23, 59, 59, 999);
  Weektime w2(0, 0, 0, 0, 1);
  Weektime w3 = w1 + w2;
  TEST_ASSERT_EQUAL(0, w3.weekday());
  TEST_ASSERT_EQUAL(0, w3.hour());
  TEST_ASSERT_EQUAL(0, w3.minute());
  TEST_ASSERT_EQUAL(0, w3.second());
  TEST_ASSERT_EQUAL(0, w3.milli());  
}

void test_subtract() 
{
  Weektime w1(2, 1, 1, 1, 1);
  Weektime w2(0, 1, 1, 1, 2);
  Weektime w3 = w1 - w2;
  TEST_ASSERT_EQUAL(1, w3.weekday());
  TEST_ASSERT_EQUAL(23, w3.hour());
  TEST_ASSERT_EQUAL(59, w3.minute());
  TEST_ASSERT_EQUAL(59, w3.second());
  TEST_ASSERT_EQUAL(999, w3.milli());  
}

void test_subtract_wraparound() 
{
  Weektime w1(0, 0, 0, 0, 0);
  Weektime w2(0, 0, 0, 0, 1); 
  Weektime w3 = w1 - w2;
  TEST_ASSERT_EQUAL(6, w3.weekday());
  TEST_ASSERT_EQUAL(23, w3.hour());
  TEST_ASSERT_EQUAL(59, w3.minute());
  TEST_ASSERT_EQUAL(59, w3.second());
  TEST_ASSERT_EQUAL(999, w3.milli());  
}

void test_equal()
{
  Weektime w1(1, 2, 3, 4, 5);
  Weektime w2(1, 2, 3, 4, 5);

  Weektime w3(0, 2, 3, 4, 5); 
  Weektime w4(1, 0, 3, 4, 5);
  Weektime w5(1, 2, 0, 4, 5);
  Weektime w6(1, 2, 3, 0, 5);
  Weektime w7(1, 2, 3, 4, 0);

  TEST_ASSERT_TRUE(w1 == w1);
  TEST_ASSERT_TRUE(w1 == w2);

  TEST_ASSERT_FALSE(w1 == w3);
  TEST_ASSERT_FALSE(w1 == w4);
  TEST_ASSERT_FALSE(w1 == w5);
  TEST_ASSERT_FALSE(w1 == w6);
  TEST_ASSERT_FALSE(w1 == w7);
}

void test_less()
{
  Weektime w1(1, 1, 1, 1, 1);
  Weektime w2(0, 1, 1, 1, 1);
  Weektime w3(1, 0, 1, 1, 1);
  Weektime w4(1, 1, 0, 1, 1);
  Weektime w5(1, 1, 1, 0, 1);
  Weektime w6(1, 1, 1, 1, 0);
  TEST_ASSERT_TRUE(w2 < w1);
  TEST_ASSERT_TRUE(w3 < w1);
  TEST_ASSERT_TRUE(w4 < w1);
  TEST_ASSERT_TRUE(w5 < w1);
  TEST_ASSERT_TRUE(w6 < w1);

  TEST_ASSERT_FALSE(w1 < w2);
  TEST_ASSERT_FALSE(w1 < w3);
  TEST_ASSERT_FALSE(w1 < w4);
  TEST_ASSERT_FALSE(w1 < w5);
  TEST_ASSERT_FALSE(w1 < w6);
}

void test_greater()
{
  Weektime w1(1, 1, 1, 1, 1);
  Weektime w2(2, 1, 1, 1, 1);
  Weektime w3(1, 2, 1, 1, 1);
  Weektime w4(1, 1, 2, 1, 1);
  Weektime w5(1, 1, 1, 2, 1);
  Weektime w6(1, 1, 1, 1, 2);
  TEST_ASSERT_TRUE(w2 > w1);
  TEST_ASSERT_TRUE(w3 > w1);
  TEST_ASSERT_TRUE(w4 > w1);
  TEST_ASSERT_TRUE(w5 > w1);
  TEST_ASSERT_TRUE(w6 > w1);

  TEST_ASSERT_FALSE(w1 > w2);
  TEST_ASSERT_FALSE(w1 > w3);
  TEST_ASSERT_FALSE(w1 > w4);
  TEST_ASSERT_FALSE(w1 > w5);
  TEST_ASSERT_FALSE(w1 > w6);
}

void test_less_or_equal()
{
  Weektime w1(1, 1, 1, 1, 1);
  Weektime w2(0, 1, 1, 1, 1);
  Weektime w3(1, 0, 1, 1, 1);
  Weektime w4(1, 1, 0, 1, 1);
  Weektime w5(1, 1, 1, 0, 1);
  Weektime w6(1, 1, 1, 1, 0);
  
  TEST_ASSERT_TRUE(w1 <= w1);

  TEST_ASSERT_TRUE(w2 <= w1);
  TEST_ASSERT_TRUE(w3 <= w1);
  TEST_ASSERT_TRUE(w4 <= w1);
  TEST_ASSERT_TRUE(w5 <= w1);
  TEST_ASSERT_TRUE(w6 <= w1);

  TEST_ASSERT_FALSE(w1 <= w2);
  TEST_ASSERT_FALSE(w1 <= w3);
  TEST_ASSERT_FALSE(w1 <= w4);
  TEST_ASSERT_FALSE(w1 <= w5);
  TEST_ASSERT_FALSE(w1 <= w6);
}

void test_greater_or_equal()
{
  Weektime w1(1, 1, 1, 1, 1);
  Weektime w2(2, 1, 1, 1, 1);
  Weektime w3(1, 2, 1, 1, 1);
  Weektime w4(1, 1, 2, 1, 1);
  Weektime w5(1, 1, 1, 2, 1);
  Weektime w6(1, 1, 1, 1, 2);
  
  TEST_ASSERT_TRUE(w1 >= w1);

  TEST_ASSERT_TRUE(w2 >= w1);
  TEST_ASSERT_TRUE(w3 >= w1);
  TEST_ASSERT_TRUE(w4 >= w1);
  TEST_ASSERT_TRUE(w5 >= w1);
  TEST_ASSERT_TRUE(w6 >= w1);

  TEST_ASSERT_FALSE(w1 >= w2);
  TEST_ASSERT_FALSE(w1 >= w3);
  TEST_ASSERT_FALSE(w1 >= w4);
  TEST_ASSERT_FALSE(w1 >= w5);
  TEST_ASSERT_FALSE(w1 >= w6);
}

void test_to_millis()
{
  Weektime w;
  TEST_ASSERT_EQUAL(0, w.to_millis());

  w.set(0, 0, 0, 0, 1);
  TEST_ASSERT_EQUAL(1, w.to_millis());

  w.set(0, 0, 0, 1, 0);
  TEST_ASSERT_EQUAL(1000, w.to_millis());

  w.set(0, 0, 1, 0, 0);
  TEST_ASSERT_EQUAL(60000, w.to_millis());

  w.set(0, 1, 0, 0, 0);
  TEST_ASSERT_EQUAL(3600000, w.to_millis());

  w.set(1, 0, 0, 0, 0);
  TEST_ASSERT_EQUAL(86400000, w.to_millis());

  w.set(1, 1, 1, 1, 1);
  TEST_ASSERT_EQUAL(90061001, w.to_millis());
}

void test_to_string()
{
  Weektime w(0, 10, 40, 50, 500);
  TEST_ASSERT_EQUAL_STRING("Mon 10:40:50.500", w.to_string().c_str());

  FirstWeekday = SUNDAY;
  TEST_ASSERT_EQUAL_STRING("Sun 10:40:50.500", w.to_string().c_str());

  FirstWeekday = MONDAY;
  TEST_ASSERT_EQUAL_STRING("Mon 10:40:50.500", w.to_string().c_str());
}

int runUnityTests(void) 
{
  UNITY_BEGIN();
  RUN_TEST(test_weektime_is_default_zero);
  RUN_TEST(test_constructor_with_parameters);
  RUN_TEST(test_constructor_with_wraparound);
  RUN_TEST(test_copy_constructor);
  RUN_TEST(test_set);
  RUN_TEST(test_set_with_wraparound);
  RUN_TEST(test_start_of_day);
  RUN_TEST(test_assign);
  RUN_TEST(test_add);
  RUN_TEST(test_add_wraparound);
  RUN_TEST(test_subtract);
  RUN_TEST(test_subtract_wraparound);
  RUN_TEST(test_equal);
  RUN_TEST(test_less);
  RUN_TEST(test_greater);
  RUN_TEST(test_less_or_equal);
  RUN_TEST(test_greater_or_equal);
  RUN_TEST(test_to_millis);
  RUN_TEST(test_to_string);
  return UNITY_END();
}

int main(void) 
{
  return runUnityTests();
}
