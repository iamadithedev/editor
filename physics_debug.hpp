#pragma once

#include "mesh_geometry.hpp"

class PhysicsDebug final : public btIDebugDraw
{
public:
    PhysicsDebug();

    [[nodiscard]] const MeshGeometry<vertex::debug>& geometry() const;

private:
    void clearLines() final;
    void flushLines() final;

    void drawLine(const btVector3 &a, const btVector3 &b, const btVector3 &color) final;

    [[nodiscard]] int32_t getDebugMode() const final;

    MeshGeometry<vertex::debug> _geometry;
    int32_t                     _index;
};