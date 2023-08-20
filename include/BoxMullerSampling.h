# ifndef BOXMULLERSAMPLING_H
# define BOXMULLERSAMPLING_H

#include <cstdlib>
#include <cmath>

namespace QuantDaz
{
namespace Sampler
{

class BoxMullerSampling
{
public:
  BoxMullerSampling();
  inline double getResult()
  {
    if ( !_result ) return _result;
    return 0.0;
  };

private:

  double _x;
  double _y;
  double _result;
};

}
}

# endif 
