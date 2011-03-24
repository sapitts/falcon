#ifndef DARCYMASSFLUXPRESSURE
#define DARCYMASSFLUXPRESSURE

#include "Diffusion.h"
#include "Material.h"

//Forward Declarations
class DarcyMassFluxPressure;

template<>
InputParameters validParams<DarcyMassFluxPressure>();

class DarcyMassFluxPressure : public Diffusion
{
public:

  DarcyMassFluxPressure(const std::string & name, InputParameters parameters);
    
protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  MaterialProperty<Real> &_tau_water;
};
#endif //DARCYMASSFLUXPRESSURE
