#pragma once

class XorLinkedNode
{
private:
	bool both;
	int value;

public:
	XorLinkedNode(int value, XorLinkedNode* next, XorLinkedNode* prev);

	XorLinkedNode* getNextOrPrev(XorLinkedNode* other);
	void setBoth(XorLinkedNode* prev, XorLinkedNode* next);
};

