#include "plane_geometry.hpp"

namespace RT_ISICG
{
	bool PlaneGeometry::intersect( const Ray & p_ray, float & p_t1 ) const
	{
		/* float d = dot( getNormal(), p_ray.getDirection() );
		// Si p et r ne sont pas parallèles
		if ( d > 0 )
		{ // Attention à la comparaison avec 0
			Vec3f po = getPoint() - p_ray.getOrigin();
			p_t1 = dot( po, getNormal() ) / d;
			return true;
		}
		p_t1 = -1;
		return false;*/

		p_t1 = glm::dot( _point - p_ray.getOrigin(), _normal ) / glm::dot( p_ray.getDirection(), _normal );
		if ( p_t1 > 0 ) { return true; }
		return false;
	}
} // namespace RT_ISICG
