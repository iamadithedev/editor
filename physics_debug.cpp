#include "physics_debug.hpp"

PhysicsDebug::PhysicsDebug()
    : _index { }
{
}

void PhysicsDebug::drawLine(const btVector3& a, const btVector3& b, const btVector3& color)
{
    rgb rgb { color.x(), color.y(), color.z() };

    _geometry.add_vertex({{ a.x(), a.y(), a.z() }, rgb });
    _geometry.add_vertex({{ b.x(), b.y(), b.z() }, rgb });

    _geometry.add_face({ _index++, _index++ });
}

int32_t PhysicsDebug::getDebugMode() const
{
    return btIDebugDraw::DBG_DrawWireframe;
}

void PhysicsDebug::flushLines()
{
    _geometry.end();
}

void PhysicsDebug::clearLines()
{
    _geometry.reset();
    _geometry.begin();

    _index = 0;
}

const geometry::line& PhysicsDebug::geometry() const
{
    return _geometry;
}
