# include "MCEuropeanCall.h"

using QuantDaz::Sampler::BoxMullerSampling;

void QuantDaz::MC::MCEuropeanCall::init( double& maturity,
	                 double& strike,
			 double& spot,
			 double& volatility,
			 double& interestRate,
			 int& numSteps,
			 int& simNum )
{
  std::cout << "=================================\n";
  std::cout << "Monte Carlo European Call Options\n";
  std::cout << "=================================\n";
  this->setMaturity( maturity );
  this->setStrike( strike );
  this->setSpot( spot );
  this->setVolatility( volatility );
  this->setInterestRate( interestRate );
  this->setSteps( numSteps );
  this->setSimNum( simNum );
  
  _sumPayOff = 0;
  _premium = 0;
  _dt = _T / _N;
}

bool QuantDaz::MC::MCEuropeanCall::compute()
{
  if ( _T && _K && _S0 && _sigma && _r && _N && _M )
  {
    // for each simulation
    for ( int i = 0; i < _M; i++ )
    {
      // initialise simulation path
      _S[0] = _S0;
      double epsilon;

      // integrate over time dt
      for ( int j = 0; j < _N; i++ )
      {
	// draw from Gaussian
	BoxMullerSampling BMSampler;
        epsilon = BMSampler.getResult();
        _S[i+1] = _S[i] * ( 1 + ( _r * _dt ) + _sigma * sqrt( _dt) * epsilon );	
      }

      // sum over payoff
      _sumPayOff += std::max( _S[_N] - _K, 0.0 ); 
    }
    
    // Calculate premium
    _premium = exp( -( _r * _T ) ) * ( _sumPayOff / _M );
    std::cout << "Premium : " << _premium << "\n";

    return 0;
  }
  else
  {
    std::cout << "Some variables are not set. Please double check" << std::endl;
    return 1;
  }
}

inline const double& QuantDaz::MC::MCEuropeanCall::getPremium()
{
  if ( _premium )
  {
    return _premium;
  }
}

void QuantDaz::MC::MCEuropeanCall::setMaturity( const double& maturity )
{
  _T = maturity;
  std::cout << "Setting Maturity to [" << maturity << "]." << std::endl;
}

void QuantDaz::MC::MCEuropeanCall::setStrike( const double& strike )
{
  _K = strike;
  std::cout << "Setting Strike Price to [" << strike << "]." << std::endl;
}

void QuantDaz::MC::MCEuropeanCall::setSpot( const double& spot )
{
  _S0 = spot;
  std::cout << "Setting Spot Price to [" << spot << "]" << std::endl;
}

void QuantDaz::MC::MCEuropeanCall::setVolatility( const double& volatility )
{
  _sigma = volatility;
  std::cout << "Setting Volatility to [" << volatility << "]" << std::endl;
}

void QuantDaz::MC::MCEuropeanCall::setInterestRate( const double& interestRate )
{
  _r = interestRate;
  std::cout << "Setting Interest Rate to [" << interestRate << "]" << std::endl;
}

void QuantDaz::MC::MCEuropeanCall::setSteps( const int& steps )
{
  _N = steps;
  std::cout << "Setting Number of Steps to [" << steps << "]" << std::endl;
}

void QuantDaz::MC::MCEuropeanCall::setSimNum( const int& simNum )
{
  _M = simNum;
  std::cout << "Setting Number of Simulations to [" << simNum << "]" << std::endl;
}

