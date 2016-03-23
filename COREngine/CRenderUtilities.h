#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Shapes.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"

void drawMatrix(const COR::Mat3 &mDraw);
void drawAABB(const COR::AABB &aDraw, unsigned TINT);
void drawCircle(const COR::Circle &cDraw, unsigned TINT);


void drawTransform(const Transform &tDraw);
void drawRigidbody(const Transform &tDraw, const Rigidbody &rDraw);
void drawCollider(const Transform &tDraw, const Collider &rDraw);
