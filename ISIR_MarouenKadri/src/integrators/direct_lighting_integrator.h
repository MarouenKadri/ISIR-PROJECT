#pragma once
#include "base_integrator.hpp"

namespace RT_ISICG
{
	class DirectLightingIntegrator : public BaseIntegrator
	{
	  public:
		DirectLightingIntegrator( int p_nbLightSamples ) : BaseIntegrator(), _nbLightSamples( p_nbLightSamples ) {}
		virtual ~DirectLightingIntegrator() = default;

		virtual Vec3f Li( const Scene & p_scene,
						  const Ray &	p_ray,
						  const float	p_tMin,
						  const float	p_tMax ) const override;

		virtual Vec3f _directLighting( const Scene & p_scene, const Ray & p_ray, const HitRecord & ht ) const;

		const IntegratorType getType() const override { return IntegratorType::DIRECT_LIGHT; }

		const int getNbLightSamples() const { return _nbLightSamples; }

	  private:
		int _nbLightSamples=32;
	};
} // namespace RT_ISICG
