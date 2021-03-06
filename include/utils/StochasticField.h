/****************************************************************/
/*             DO NOT MODIFY OR REMOVE THIS HEADER              */
/*          FALCON - Fracturing And Liquid CONvection           */
/*                                                              */
/*       (c)     2012 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef STOCHASTICFIELD_H
#define STOCHASTICFIELD_H

#include "Moose.h"

// libmesh includes. Need to include point instead of forward declaring to get Real
#include "libmesh/point.h"

#include <vector>

/**
 * This class parses data from a file and returns it for a given xyz point.
 *
 * FILE FORMAT:
 * Line 1: comment
 * Line 2: nx =      640, ny =      320, nz =        1
 * Line 3: dx = 0.4687E-03 m, dy = 0.4687E-03 m, dz = 0.1000E+01 m
 * Line 4 plus nx*ny*nz more lines: one number per line
 */
class StochasticField
{
public:
  /**
   * Construct a new grid of data parsed from the passed filename.
   */
  StochasticField(std::string fname);
  ~StochasticField() {}

  /**
   * Returns the value in the grid at point p without interpolating.
   */
  Real value(Point p);

private:
  int _nx;
  int _ny;
  int _nz;
  Real _dx;
  Real _dy;
  Real _dz;
  std::vector<Real> _data;
};

// temporary: for testing
//void test_sf(std::string fname);

#endif // STOCHASTICFIELD_H
