#include "XorLinkedNode.h"

XorLinkedNode* XorLinkedNode::getNextOrPrev(XorLinkedNode* other) {
	return (XorLinkedNode*)(other ^ this->both);
}