#include <vector>
#include <string>
#include <tuple>

#include "XMLNode.hpp"

class SiteTree {
	private:
		XMLNode* root;
	public:
		SiteTree();

		void setRoot(XMLNode* root);

		XMLNode* getRoot() const;

		void print() const;
};
