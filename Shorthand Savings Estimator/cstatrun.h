//
//  cstatrun.h
//  Shorthand Savings Estimator
//
//  Created by Alex Crist on 2/12/14.
//  Copyright (c) 2014 WH External Projects. All rights reserved.
//

#ifndef Shorthand_Savings_Estimator_cstatrun_h
#define Shorthand_Savings_Estimator_cstatrun_h

#include <cmath>

double StandardDev( int terms[] , int arraysize)
{
    double mean;
    int total = 0;
    
    for ( int i = 0; i < arraysize; i++)
    {
        total += terms[i];
    }
    
    mean = (double) total / arraysize;
    
    double stdev = 0;
    double variation = 0;
    
    for ( int k = 0; k < arraysize; k++)
    {
        variation += pow( mean - terms[k], 2 );
    }
    
    stdev = sqrt( variation / ( arraysize-1 ) );
    
    return stdev;
}

#endif
