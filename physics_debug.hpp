#pragma once

#include "mesh_utils.hpp"

class PhysicsDebug final : public btIDebugDraw
{
public:
    PhysicsDebug();

    [[nodiscard]] const line_geometry& geometry() const;

private:
    void clearLines() final;
    void flushLines() final;

    void drawLine(const btVector3 &a, const btVector3 &b, const btVector3 &color) final;

    [[nodiscard]] int32_t getDebugMode() const final;

    line_geometry _geometry;
    uint32_t      _index;
};