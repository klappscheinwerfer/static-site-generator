#include "sitetree.hpp"

SiteTree :: SiteTree () {
	setRoot(NULL);
}

void SiteTree :: setRoot (XMLNode* root) {
	this -> root = root;
}

XMLNode* SiteTree :: getRoot () const {
	return root;
}

void SiteTree :: print () const {
	XMLNode* n = root;
	while (n != NULL) {
    	n -> getChildren();
		for(XMLNode* x : n -> getChildren()) {
			x -> print();
		}
	}
}
