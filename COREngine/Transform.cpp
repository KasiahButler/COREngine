#include "Transform.h"

Transform::Transform()
	: parent(nullptr), scale({ 1, 1 }), position({ 0,0 }), angle(0) {}

Transform::~Transform() 
{
	auto t = children; 
	for each(Transform *child in t) child->setParent(parent);
	setParent(nullptr); 
}

void Transform::setParent(Transform *nParent)
{
	//Free from the original parent if we have one
	if (parent) parent->children.remove(this);

	//check the new parent for null and add this object to its children
	if (nParent) nParent->children.push_front(this);

	//Set objects parent as new parent
	parent = nParent;
}

COR::Mat3 Transform::getGlobalTransform() const
{
	return (parent ? parent->getGlobalTransform() : COR::Mat3::identity())
		* COR::translate(position) * COR::scale(scale) * COR::rotate(angle);
}