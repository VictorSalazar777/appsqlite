//
//  timeUtilitiesCpp.hpp
//  TimeLib
//
//  Created by manuel on 6/15/17.
//  Copyright © 2017 manuel. All rights reserved.
//

#ifndef timeUtilitiesCpp_hpp
#define timeUtilitiesCpp_hpp

template <typename CLOCK> void time_of_execution_with_chrono_cpp(void (*task)(void* args), void* args = nullptr);
void time_reports_cpp();
template <typename CLOCK> void printClockData();


#endif /* timeUtilitiesCpp_hpp */
