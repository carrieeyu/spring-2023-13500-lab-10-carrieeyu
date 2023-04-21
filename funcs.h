#include <iostream>
#pragma once

//----------------------ENUM---------------------------

//A variable of type Genre can assume any of the values listed in the curly braces, example: Genre myFavorite = COMEDY;
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

//----------------------CLASSES------------------------

//Stores time HH:MM in the 24-hour format
class Time { 
public:
    int h; //h for the number of hours
    int m; //m for the number of minutes
};

//Stores the movie details
class Movie { 
public: 
    std:: string title; //title of the movie
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

//stores details about the movie title and the start time
class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

//-----------------------FUNCS--------------------------

//class Time
void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);

//class Movie
void printMovie(Movie mv);

//class TimeSlot
std:: string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);

