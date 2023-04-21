#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

Time time0 = {8,10};
Time expectedTime0 = {9,25};

Time time1 = {3,10};
Time expectedTime1 = {3,13};

Time time2 = {12, 59};

Time time3 = {4,17};
Time expectedTime3 = {6,20};

Time taskB = {8, 10};
Time expectedtaskB = {9,25};

Movie movie1 = {"Back to the Future", COMEDY, 116}; //movie1 = Movie movie
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Joker", THRILLER, 122};
  Movie movie4 = {"Harry Potter and the Half-Blood Prince", ROMANCE, 153};
  Movie movie5 = {"Captain America: The Winter Solider", ACTION, 136};
  TimeSlot morning = {movie1, {9, 15}}; //{9, 15} = Time startTime
  //TimeSlot morning = {movie1, {3, 130}}; //5,10 but doesnt work
  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie2, {16, 45}}; 
  TimeSlot myTimeSlot1 = {movie4, {20, 30}};
  TimeSlot myTimeSlot2 = {movie5, {3, 10}};

//Task A; p1
TEST_CASE("Hours:Minutes --> Minutes"){
  CHECK(minutesSinceMidnight(time1) == 190);
  CHECK(minutesSinceMidnight(time2) == 779);
  CHECK(minutesSinceMidnight(time3) == 257);
}
//Task A; p2
TEST_CASE("Interval between two times"){
  CHECK(minutesUntil(time1, time2) == 589);
  CHECK(minutesUntil(time2, time3) == -522);
  CHECK(minutesUntil(time1, time3) == 67);
}

//Task B
TEST_CASE("Additional hour(s) and minutes to orig."){
  Time newTime0 = addMinutes(time0, 75);
  CHECK(newTime0.h == expectedTime0.h);
  CHECK(newTime0.m == expectedTime0.m);

  Time newTime1 = addMinutes(time1, 3);
  CHECK(newTime1.h == expectedTime1.h);
  CHECK(newTime1.m == expectedTime1.m);

  Time newTime3 = addMinutes(time3, 123);
  CHECK(newTime3.h == expectedTime3.h);
  CHECK(newTime3.m == expectedTime3.m);

  Time newtaskB = addMinutes(taskB, 75);
  CHECK(newtaskB.h == expectedtaskB.h);
  CHECK(newtaskB.m == expectedtaskB.m);
}

//Task C
TEST_CASE("Start and End time of movie"){
  CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
  
  
  CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
  CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
  CHECK(getTimeSlot(myTimeSlot1) == "Harry Potter and the Half-Blood Prince ROMANCE (153 min) [starts at 20:30, ends by 23:3]");
  CHECK(getTimeSlot(myTimeSlot2) == "Captain America: The Winter Solider ACTION (136 min) [starts at 3:10, ends by 5:26]");

}


//Task D
TEST_CASE("New time Slots"){
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Joker", THRILLER, 122};
  Movie movie4 = {"Harry Potter and the Half-Blood Prince", ROMANCE, 153};

  TimeSlot daytime = {movie2, {12, 15}}; 
  TimeSlot evening = {movie2, {16, 45}}; 
  TimeSlot myTimeSlot1 = {movie4, {20, 30}};
  

  CHECK(scheduleAfter(evening, movie2).startTime.h == 18);
  CHECK(scheduleAfter(evening, movie2).startTime.m == 59);

  CHECK(scheduleAfter(myTimeSlot1, movie4).startTime.h == 23);
  CHECK(scheduleAfter(myTimeSlot1, movie4).startTime.m == 3);

  CHECK(scheduleAfter(daytime, movie2).startTime.h == 14);
  CHECK(scheduleAfter(daytime, movie2).startTime.m == 29);
}

//Task E
TEST_CASE("Overlapping Times"){
  CHECK(timeOverlap(morning, daytime) == 0);
  CHECK(timeOverlap(evening, daytime) == 0);
  CHECK(timeOverlap(morning, myTimeSlot2) == 0);
}
