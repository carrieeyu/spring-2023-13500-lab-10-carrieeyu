#include <iostream>
#include "funcs.h"

int main(){
  Time time0 = {8, 10};
  Time time1 = {3, 10};
  Time time2 = {12, 59};
  Time time3 = {4,17};
  Time taskB = {8, 10};

  //between task B and C
  //from class TimeSlot
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

  

  //before Tasks
  std:: cout << "(Hour:Minutes format)" << std:: endl;
  printTime(time1);
  std:: cout << " " << std:: endl; //3:10
  printTime(time2);
  std:: cout << " " << std:: endl; //12:59
  printTime(time3);
  std:: cout << " " << std:: endl; //4:17

  std:: cout << "-----------------------------------------" << std:: endl;

  //-------------------------Task A
  std:: cout << "(Task A: p1)" << std:: endl;
  std:: cout << "The total minutes from 0:00 to 3:10 is: " << minutesSinceMidnight(time1) << std:: endl; //190 minutes
  std:: cout << "The total minutes from 0:00 to 12:59 is: " << minutesSinceMidnight(time2) << std:: endl; //190 minutes
  std:: cout << "The total minutes from 0:00 to 4:17 is: " << minutesSinceMidnight(time3) << std:: endl; //190 minutes
  
  std:: cout << "(Task A: p2)" << std:: endl;
  std:: cout << "The interval between 3:10 and 12:59 is: " << minutesUntil(time1, time2) << std:: endl; //589
  std:: cout << "The interval between 12:59 and 4:17 is: " << minutesUntil(time2, time3) << std:: endl; //-522
  std:: cout << "The interval between 3:10 and 4:17 is: " << minutesUntil(time1, time3) << std:: endl; //67

  std:: cout << "-----------------------------------------" << std:: endl;
  
  //-------------------------Task B
  std:: cout << "(Task B)" << std:: endl;
  Time newTime0 = addMinutes(time0, 75);
  std:: cout << "75 minutes after 8:10 is: " << newTime0.h << ":" << newTime0.m << std:: endl; //9:25

  Time newTime1 = addMinutes(time1, 3);
  std:: cout << "3 minutes after 3:10 is: " << newTime1.h << ":" << newTime1.m << std:: endl; //3:13

  Time newTime3 = addMinutes(time3, 123);
  std:: cout << "123 minutes after 4:17 is: " << newTime3.h << ":" << newTime3.m << std:: endl; //6:

  Time newtaskB = addMinutes(taskB, 75); 
  std:: cout << "75 minutes after 8:10 is: " << newtaskB.h << ":" << newtaskB.m << std:: endl; //9:25

std:: cout << "-----------------------------------------" << std:: endl;

  //---------Between task B and task C
  std:: cout << "(Between task B and task C)" << std:: endl;
  printMovie(movie1);
  std:: cout << " " << std:: endl;
  printMovie(movie2);
  std:: cout << " " << std:: endl;
  printMovie(movie3);
  std:: cout << " " << std:: endl;

  std:: cout << "-----------------------------------------" << std:: endl;
  
  //-------------------------Task C
  std:: cout << "(Task C)" << std:: endl;
  std:: cout << getTimeSlot(morning) << std:: endl; //9:15
  std:: cout << getTimeSlot(daytime) << std:: endl; //14:29
  std:: cout << getTimeSlot(evening) << std:: endl; //18:59
  std:: cout << getTimeSlot(myTimeSlot1) << std:: endl; //23:3
  std:: cout << getTimeSlot(myTimeSlot2) << std:: endl; //5:26

  std:: cout << "-----------------------------------------" << std:: endl;
  
  //-------------------------Task D
  std:: cout << "(Task D)" << std:: endl;

  /*COMBINE C AND D for complete comparison
  std:: cout << getTimeSlot(scheduleAfter(evening, movie2)) << std:: endl;
  std:: cout << getTimeSlot(scheduleAfter(myTimeSlot1, movie4)) << std:: endl;
  std:: cout << getTimeSlot(scheduleAfter(daytime, movie2)) << std:: endl;
  */

  std:: cout << scheduleAfter(evening, movie2).startTime.h << std:: endl;
  std:: cout << scheduleAfter(evening, movie2).startTime.m << std:: endl;

  std:: cout << scheduleAfter(myTimeSlot1, movie4).startTime.h << std:: endl;
  std:: cout << scheduleAfter(myTimeSlot1, movie4).startTime.m << std:: endl;

  std:: cout << scheduleAfter(daytime, movie2).startTime.h << std:: endl;
  std:: cout << scheduleAfter(daytime, movie2).startTime.m << std:: endl;
  
  //-------------------------Task E
  
  std:: cout << "-----------------------------------------" << std:: endl;
  std:: cout << "(Task E)" << std:: endl;
  std::cout << timeOverlap(morning, daytime) << std::endl; 
  std::cout << timeOverlap(evening, daytime) << std::endl; 
  std::cout << timeOverlap(morning, myTimeSlot2) << std::endl; 
}




