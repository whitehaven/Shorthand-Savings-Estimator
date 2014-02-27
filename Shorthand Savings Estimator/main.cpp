//
//  main.cpp
//  Shorthand Savings Estimator
//
//  Created by Alex Crist on 2/12/14.
//  Copyright (c) 2014 WH External Projects. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "cstatrun.h"

using namespace std;

int main(int argc, const char * argv[])
{
    const int DICTIONARY_SIZE = 18620;
    
    //Read in dictionary file
    string words[DICTIONARY_SIZE];
    
    ifstream fin ("/Users/WhiteHaven/Documents/Computer Science/Shorthand Savings Estimator/Shorthand Savings Estimator/US.txt");
    
    if (!fin.is_open()) // Make sure file opened okay, if not, report error 1
    {
        return 1;
    }
    
    //read in entire dictionary, 1 string/word
    for (int i = 0; i < DICTIONARY_SIZE; i++)
    {
        fin >> words[i];
    }
    
    cout << "For " << DICTIONARY_SIZE << " normal words, " << endl;
    
    //Count words, total characters
    double sumlength = 0;
    double meanlength;
    double stdev;
    int lengths[DICTIONARY_SIZE];
    
    for ( int k = 0; k < DICTIONARY_SIZE; k++)
    {
            lengths[k] = (int) words[k].length();
            sumlength += (int) words[k].length();
    }
    
    meanlength = (double) sumlength / DICTIONARY_SIZE;
    
    stdev = StandardDev(lengths, DICTIONARY_SIZE);
    
    //compute statistics
    cout << "**Original Dictionary**" << endl;
    cout << " __________________ " << endl;
    cout << " |Total Characters: " << sumlength << endl;
    cout << " |Mean Word Length: " << meanlength << endl;
    cout << " |  Standard Dev  : " << stdev << endl;
    cout << " ------------------ " << endl;
    
    //Process dictionary file
    
    for ( int l = 0; l < DICTIONARY_SIZE; l++)
    {
        //note that first letter is always left using m = 1 not m = 0
        for (int m = 1; m < words[l].length(); m++)
        {
            if ( (words[l].length() >= 3) )
            {
                if ( (words[l].at(m) == 'a') || (words[l].at(m) == 'e') || (words[l].at(m) == 'i') || (words[l].at(m) == 'o') || (words[l].at(m) == 'u') )
                {
                    words[l].erase(m,1);
                    
                    if ( m < words[l].length() && ((words[l].at(m) == 'a') || (words[l].at(m) == 'e') || (words[l].at(m) == 'i') || (words[l].at(m) == 'o') || (words[l].at(m) == 'u')) )
                    {
                        //use de-increment
                        words[l].erase(m,1);
                    }
                    
                }
            }
        }
    }
    
    //Count words, total characters again
    
    int fsumlength = 0;
    double fmeanlength;
    double fstdev;
    
    for ( int k = 0; k < DICTIONARY_SIZE; k++)
    {
        lengths[k] = (int) words[k].length();
        fsumlength += (int) words[k].length();
    }
    
    fmeanlength = (double) fsumlength / DICTIONARY_SIZE;
    
    //compute statistics
    fstdev = StandardDev(lengths, DICTIONARY_SIZE);
    
    //print results for shorthand dictionary
    cout << endl;
    cout << "**Teetotal Shorthand Dictionary**" << endl;
    cout << " __________________ " << endl;
    cout << " |Total Characters: " << fsumlength << endl;
    cout << " |Mean Word Length: " << fmeanlength << endl;
    cout << " |  Standard Dev  : " << fstdev << endl;
    cout << " ------------------ " << endl;
    
    cout << endl;
    cout << ((1-(fsumlength / sumlength))) * 100.0 << "% reduction in characters." << endl;

    ofstream fout ( "/Users/WhiteHaven/Documents/Computer Science/Shorthand Savings Estimator/Shorthand Savings Estimator/Shorthanded Dictionary.txt");
    cout << endl;
    cout << "-Check for Shorthanded Dictionary.txt for results." << endl;
    for ( int n = 0; n < DICTIONARY_SIZE; n++)
    {
        fout << words[n] << endl;
    }
            //Ext: shorten -tion to alpha
            //Maybe add some proper nouns
        //Output shorthand'd dictionary
        //Count words, total chars, compute statistics
    
    return 0;
}