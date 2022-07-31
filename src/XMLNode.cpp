#include "XMLNode.hpp"

// Constructors
XMLNode :: XMLNode (std::vector<std::tuple<std::string, std::string>> tags, std::string content) {
	setTags(tags);
	setContent(content);
}

// Set
void XMLNode :: setChildren(std::vector<XMLNode*> children) {
	this -> children = children;
}

void XMLNode :: setTags(std::vector<std::tuple<std::string, std::string>> tags) {
	this -> tags = tags;
}

void XMLNode :: setContent(std::string content) {
	this -> content = content;
}

// Get
std::vector<XMLNode*> XMLNode :: getChildren() const {
	return children;
}

std::vector<std::tuple<std::string, std::string>> XMLNode :: getTags() const {
	return tags;
}

std::string XMLNode :: getContent() const {
	return content;
}
