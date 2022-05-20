#include "direct_lighting_integrator.h"

namespace RT_ISICG
{
	class WhittedIntegrator : public DirectLightingIntegrator
	{
	  public:
		WhittedIntegrator( int p_nbLightSamples, int p_nbBounces )
			: DirectLightingIntegrator( p_nbLightSamples ), _nbBounces( p_nbBounces )
		{
		}
		virtual ~WhittedIntegrator() = default;

		virtual Vec3f Li( const Scene & p_scene,
						  const Ray &	p_ray,
						  const float	p_tMin,
						  const float	p_tMax ) const override;

		const IntegratorType getType() const override { return IntegratorType::WHITTED; }

		
	  protected:
		int _nbBounces=5;
	};
}


