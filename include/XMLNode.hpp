#ifndef XMLNODE_HPP
#define XMLNODE_HPP

#include <vector>
#include <string>
#include <tuple>

class XMLNode {
	private:
		std::string type;
		std::vector<XMLNode*> children;
		std::vector<std::tuple<std::string, std::string>> tags; 
		std::string content;
	public:
		XMLNode(std::vector<std::tuple<std::string, std::string>>, std::string);

		void setType(std::string);
		void setChildren(std::vector<XMLNode*>);
		void setTags(std::vector<std::tuple<std::string, std::string>>);
		void setContent(std::string);

		std::string getType() const;
		std::vector<XMLNode*> getChildren() const;
		std::vector<std::tuple<std::string, std::string>> getTags() const;
		std::string getContent() const;

		void print() const;
};

#endif
