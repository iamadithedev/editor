#pragma once

#include "mesh_geometry.hpp"
#include "mesh_primitive.hpp"

using line = mesh_primitive<2>;

class PhysicsDebug final : public btIDebugDraw
{
public:
    PhysicsDebug();

    [[nodiscard]] const MeshGeometry<mesh_vertex::debug, line>& geometry() const;

private:
    void clearLines() final;
    void flushLines() final;

    void drawLine(const btVector3 &a, const btVector3 &b, const btVector3 &color) final;

    [[nodiscard]] int32_t getDebugMode() const final;

    MeshGeometry<mesh_vertex::debug, line> _geometry;
    uint32_t                               _index;
};