/*
c++ -o main_06 `root-config --cflags --glibs` main_06.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "TH1F.h"
#include "TCanvas.h"

float fgaus (float x) 
  {
    return exp (-0.5 * x * x) ; 
  }

float rand_range (float min, float max)
  {
    return min + (max - min) * rand () / static_cast<float> (RAND_MAX) ;
  } 

float rand_TCL (float xMin, float xMax, int N = 10)
  {
    double y = 0. ; 
    for (int i = 0 ; i < N ; ++i)
      y += rand_range (xMin, xMax) ;
    y /= N ;
    return y ;
  }

int main (int argc, char ** argv)
  {
    TCanvas c1 ("c1", "c1", 100, 100, 1000, 1000) ;

    TH1F h ("h", "eventi pseudo-casuali Gaussiani", 200, -1.5, 1.5) ;

    for (int j = 0 ; j < 1000000 ; ++j)
      h.Fill (rand_TCL (-1., 1., 10)) ;

    std::cout << "numero di eventi:    " << h.GetEntries () << std::endl ;
    std::cout << "media:               " << h.GetMean ()    << std::endl ;
    std::cout << "deviazione standard: " << h.GetRMS ()     << std::endl ;

    return 0 ;
  }
