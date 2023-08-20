#include "BoxMullerSampling.h"


QuantDaz::Sampler::BoxMullerSampling::BoxMullerSampling()
{
  double xySq = 0;
  while ( xySq >= 1.0 )
  {
    _x = 2.0 * ( rand() / static_cast<double>(RAND_MAX)) - 1;
    _y = 2.0 * ( rand() / static_cast<double>(RAND_MAX)) - 1;
    xySq = ( _x * _x ) + ( _y * _y );
  }
  _result = _x * sqrt( -2 * log(xySq) / xySq );
}

