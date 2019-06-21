#pragma once
class XorLinkedNode
{
private:2
	XorLinkedNode* both;
	int value;

public:
	XorLinkedNode* getNextOrPrev(XorLinkedNode* other);
	void setBoth(XorLinkedNode* prev, XorLinkedNode* next);
};

