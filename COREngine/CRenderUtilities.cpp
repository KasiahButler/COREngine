#include "CRenderUtilities.h"
#include "sfwdraw.h"

void drawMatrix(const COR::Mat3 &mDraw)
{
	COR::Vec2 &pos = mDraw[2].xy;
	COR::Vec2 up = pos + mDraw[1].xy;
	COR::Vec2 right = pos + mDraw[0].xy;

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
}

void drawTransform(const Transform &tDraw)
{
	COR::Vec2 hold = { 30, 30 };
	drawMatrix(tDraw.getGlobalTransform() * COR::scale(hold));
}

void drawRigidbody(const Transform &tDraw, const Rigidbody &rDraw)
{
	COR::Vec2 pos = tDraw.getPosition();
	COR::Vec2 acc = pos * rDraw.acceleration;
	COR::Vec2 vel = pos + rDraw.velocity;

	sfw::drawLine(pos.x, pos.y, acc.x, acc.y, CYAN);
	sfw::drawLine(pos.x, pos.y, vel.x, vel.y, YELLOW);
}

void drawAABB(const COR::AABB &aDraw, unsigned TINT)
{
	sfw::drawLine(aDraw.min().x, aDraw.min().y, aDraw.max().x, aDraw.min().y, TINT);
	sfw::drawLine(aDraw.min().x, aDraw.max().y, aDraw.max().x, aDraw.max().y, TINT);
	sfw::drawLine(aDraw.max().x, aDraw.min().y, aDraw.max().x, aDraw.max().y, TINT);
	sfw::drawLine(aDraw.min().x, aDraw.min().y, aDraw.min().x, aDraw.max().y, TINT);
}

void drawCircle(const COR::Circle &cDraw, unsigned TINT)
{
	sfw::drawCircle(cDraw.position.x, cDraw.position.y, cDraw.radius, 6, TINT);
}

void drawCollider(const Transform &tDraw, const Collider &cDraw)
{
	switch (cDraw.shape)
	{
	case Collider::e_Circle:
		drawCircle(tDraw.getGlobalTransform() * cDraw.circle, BLUE);
		break;
	case Collider::e_AABB:
		drawAABB(tDraw.getGlobalTransform() * cDraw.aabb, BLUE);
		break;
	}
}