#include "direct_lighting_integrator.h"

namespace RT_ISICG
{
	Vec3f DirectLightingIntegrator::Li( const Scene & p_scene,
										const Ray &	  p_ray,
										const float	  p_tMin,
										const float	  p_tMax ) const
	{
		HitRecord hitRecord;
		if ( p_scene.intersect( p_ray, p_tMin, p_tMax, hitRecord ) )
		{
			return this->_directLighting( p_scene, p_ray, hitRecord );
		}
		else
		{
			return _backgroundColor;
		}
	}

	Vec3f DirectLightingIntegrator::_directLighting( const Scene &	   p_scene,
													 const Ray &	   p_ray,
													 const HitRecord & hitRecord ) const
	{
		Vec3f li_color = Vec3f(0,0,0) ; 
		LightList llist		 = p_scene.getLights();
		Vec3f	  basecolor;

		for ( int i = 0; i < llist.size(); i++ )
		{
			for ( int j = 0; j < _nbLightSamples; j++ )
			{
				LightSample light_sample		   = llist[ i ]->sample( hitRecord._point );
				Ray			shadow_ray	 = Ray( hitRecord._point, light_sample._direction );
				shadow_ray.offset( hitRecord._normal );

				if ( !p_scene.intersectAny( shadow_ray, 0.f, light_sample._distance ) )
				{
					basecolor = hitRecord._object->getMaterial()->shade( p_ray, hitRecord, light_sample );
					li_color += basecolor* ( llist[ i ]->getFlatColor() * light_sample._radiance* glm::max( 0.f, glm::dot( hitRecord._normal, light_sample._direction ) ) );
				}
			}
		}
		li_color /= float( _nbLightSamples * llist.size() );
		return glm::clamp( li_color, 0.f, 1.f );
	}

} // namespace RT_ISICG
