#include <iostream>
#include "funcs.h"

//printer function that prints a Time value on the screen in HOURS:MINUTES format
void printTime(Time time) {
    std:: cout << time.h << ":" << time.m;
}

/*Tasks A and B: Zamansky Instructions
1. Write these functions in a .cpp file, run from main and test through 2. tests via doctests.
There should be no user input.
*/

/*Task A
1. int minutesSinceMidnight(Time time); return the number of minutes from 0:00AM until time
2. int minutesUntil(Time earlier, Time later); {10,30}, {13, 40}-> {10:30AM}, (13:40PM)-> 190 minutes in between the two times
*/
int minutesSinceMidnight(Time time){

  //initializing vars hour and minutes from time's interval(hour:min)
  int hour = time.h;
  int minutes = time.m;

  int hourToMinutes = (hour*60); //convert hour(s) to mins
  int totalMinutes = (hourToMinutes + minutes); //get the total minutes for the time

  return totalMinutes;
}

int minutesUntil(Time earlier, Time later){

  //getting the earlier and later time's minutes
  int earlierMins = minutesSinceMidnight(earlier);
  int laterMins = minutesSinceMidnight(later);

  //difference between the times
  int intervalBtwn = laterMins - earlierMins;

  return intervalBtwn;
}

//--------------------------------------------------------------------

/*Task B
- Time addMinutes(Time time0, int min) --> ({8,10}, 75)
- 75 should be broken down into an hour and 15 mins
- add that to the current time to get ({9,15}) as output
*/
Time addMinutes(Time time0, int min){

  //initializing vars to represent time0's interval(hour(s):min)
  int givenHour = time0.h;
  int givenMinutes = time0.m;

  int addHour = min/60; //quotient
  int addMinutes = min % 60; //remainder

  //adding the new hour(s) and minutes
  int newHour = givenHour + addHour;
  int newMinutes = givenMinutes + addMinutes;

  if(newMinutes == 60){
    newHour++;
  }
  else if(newMinutes > 60){
    int newNew = newMinutes-60;
    newHour+=1;
    newMinutes = newNew;
  }

  //updates old hour(s) and minutes to the new one, after min
  time0.h = newHour;
  time0.m = newMinutes;

  return time0;
}

//-----------------------between B and C-------------------------
void printMovie(Movie mv){
    std:: string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std:: cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//--------------------------------------------------------------------

/*Task C: Zamansky Instructions
1. The printTimeSlot function should be renamed getTimeSlot and it should return a std::string. Run from main and test via doctests.
*/

/*Task C
- rename to getTimeSlot(Timeslot ts);
- return a std:: string
- for output, it should be (title, genre, duration) --> [start time, end time])
*/
std:: string getTimeSlot(TimeSlot ts){

  std::string g;
    switch (ts.movie.genre)
      {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
      }

  std:: string result;
  
  Time start = ts.startTime;
  Time end = addMinutes(ts.startTime, ts.movie.duration);

  std:: string colon = ":";
  
  std:: string startTime = std:: to_string(ts.startTime.h) + colon + std:: to_string(ts.startTime.m);
  std:: string endTime = std:: to_string(end.h) + colon + std:: to_string(end.m);

  result = ts.movie.title + " " + g + " (" + std::to_string(ts.movie.duration) + " min) [starts at " + startTime + ", ends by " + endTime + "]";
	return result;

}
//--------------------------------------------------------------------

/*Task D and E: Zamansky Instructions
1. Write and test these as per usual - that is, no user input, run from main, test via doctest.
*/

/*Task D
- TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
- function should produce and return a new TimeSlot for the movie nextMovie, scheduled immediately after the time slot ts
- if the movie scheduled in ts starts at 14:10 and lasts 120 minutes, then the time slot for the next movie should start at exactly 16:10
*/

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  TimeSlot newMovie; //new TimeSlot for nextMovie to store the next scheduled time

  newMovie.movie = nextMovie;
  newMovie.startTime = addMinutes(ts.startTime, ts.movie.duration);
  newMovie.movie = nextMovie;
 
  return newMovie;
}


/*Task E
- return true if the two time slots overlap, otherwise return false
- take into account the starting times of the time slots and the duration of the scheduled movies.
*/

/*
- use minutesUntil to check which time slot is earlier, then find the how long is the interval between their starting times. They overlap if the movie duration > than the interval between the time slots’ starting times. Alternatively, converting times into minutes since midnight can be a good idea as well.
*/

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  
  int ts1start = minutesSinceMidnight(ts1.startTime);
  int ts2start = minutesSinceMidnight(ts2.startTime);
  int ts1duration=minutesSinceMidnight(addMinutes(ts1.startTime, ts1.movie.duration));
  //int ts2duration=minutesSinceMidnight(addMinutes(ts2.startTime,ts2.movie.duration));

  if(ts1start < ts2start){
   if(ts1duration > (ts2start)){
     return true;
   }
  }
  return false;
    /*
  else if(ts2end >(ts1start)){
    return false;
  }
  */
  
}


