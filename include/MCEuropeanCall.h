#ifndef QUANTFINANCE_MC_EUROPEANCALL_HPP
#define QUANTFINANCE_MC_EUROPEANCALL_HPP 

#include "BoxMullerSampling.h"

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

namespace QuantDaz
{
namespace MC
{

class MCEuropeanCall
{
public:
  MCEuropeanCall();
  ~MCEuropeanCall();

  void init( double& maturity,
             double& strike,
	     double& spot,
	     double& volatility,
	     double& interestRate,
	     int& numSteps,
	     int& simNum );
  bool compute();
  void storeToDatabase();

  inline const double& getMaturity() { return _T; };
  inline const double& getStrike() { return _K; };
  inline const double& getSpot() { return _S0; };
  inline const double& getVolatility() { return _sigma; };
  inline const double& getIntrestRate() { return _r; };
  inline const int&    getSteps() { return _N; };
  inline const int&    getSimNum() { return _M; };

  inline const double& getPremium();

  void setMaturity( const double& maturity );
  void setStrike( const double& strike );
  void setSpot( const double& spot );
  void setVolatility( const double& volatility );
  void setInterestRate( const double& interestRate );
  void setSteps( const int& steps );
  void setSimNum( const int& simNum );

private:

  double _T;     // maturity
  double _K;     // strike
  double _S0;    // spot
  double _sigma; // volatility
  double _r;     // interest rate
  int    _N;     // number of steps
  int    _M;     // number of simulations
  
  std::vector<double> _S;
  double              _sumPayOff;
  double              _premium;
  double              _dt;
};



} // QuantFinance 
} // MC

#endif // QUANTFINANCE_MC_EUROPEANCALL_HPP 
