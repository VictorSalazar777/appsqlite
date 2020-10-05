//
//  timeUtilitiesCpp.cpp
//  TimeLib
//
//  Created by manuel on 6/15/17.
//  Copyright © 2017 manuel. All rights reserved.
//

#include "timeUtilitiesCpp.hpp"
#include <chrono>
#include <iostream>
#include <iomanip>

// http://www.informit.com/articles/article.aspx?p=1881386&seqNum=2
template void time_of_execution_with_chrono_cpp<std::chrono::system_clock>(void (*task)(void* args), void* args);
template void time_of_execution_with_chrono_cpp<std::chrono::steady_clock>(void (*task)(void* args), void* args);
template void time_of_execution_with_chrono_cpp<std::chrono::high_resolution_clock>(void (*task)(void* args), void* args);
template <typename CLOCK>
void time_of_execution_with_chrono_cpp(void (*task)(void* args), void* args) {
  //  std::chrono::milliseconds milli;
  //  std::chrono::microseconds micro;
  //  std::chrono::nanoseconds nano;
    
    auto to = CLOCK::now();
    //std::chrono::high_resolution_clock::now();
    //std::chrono::steady_clock::now();
    task(args);
    auto tf = CLOCK::now();
    auto diff = tf - to;
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(diff);
    std::cout << "chrono: time spent is: " << duration.count() << " ns" << std::endl;
}

void time_reports_cpp() {
    using namespace std;
    using namespace std::chrono;
    milliseconds ms(7255042);
    
    // split into hours, minutes, seconds, and milliseconds
    hours   hh = duration_cast<hours>(ms);
    minutes mm = duration_cast<minutes>(ms % hours(1));
    seconds ss = duration_cast<seconds>(ms % minutes(1));
    milliseconds msec = duration_cast<milliseconds>(ms % seconds(1));
   
    // and print durations and values:
    cout << "raw: " << &hh << "::" << &mm << "::" << &ss << "::" << &msec << endl;
    cout << "     " << setfill('0') << setw(2) << hh.count() << "::"
    << setw(2) << mm.count() << "::"
    << setw(2) << ss.count() << "::"
    << setw(3) << msec.count() << endl;
}

// explicit instatiation vs specialization
// https://stackoverflow.com/questions/28354752/template-vs-template-without-brackets-whats-the-difference
// template <> void foo<int>(int& t); declares a specialization of the template, with potentially different body.
// template void foo<int>(int& t); causes an explicit instantiation of the template, but doesn't introduce a specialization. It just forces the instantiation of the template for a specific type


// explicit instatiations
template void printClockData<std::chrono::system_clock>();
template void printClockData<std::chrono::steady_clock>();
template void printClockData<std::chrono::high_resolution_clock>();

template <typename C>
void printClockData()
{
    std::cout << "- precision: ";
    
    // if time unit is less or equal one millisecond
    typedef typename C::period P; // type of time unit
    if (std::ratio_less_equal<P, std::milli>::value) {
        
        // convert to and print as milliseconds
        typedef typename std::ratio_multiply<P, std::kilo>::type TT;
        std::cout << std::fixed << double(TT::num) / TT::den << " milliseconds" << std::endl;
    }
    else {
        // print as seconds
        std::cout << std::fixed << double(P::num) / P::den << " seconds" << std::endl;
    }
    std::cout << "- is_steady: " << std::boolalpha << C::is_steady << std::endl;
}
