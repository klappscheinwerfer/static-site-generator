#include <iostream>
#include <string>
#include <tuple>

#include "XMLNode.hpp"

// Constructors
XMLNode :: XMLNode (std::vector<std::tuple<std::string, std::string>> tags, std::string content) {
	setTags(tags);
	setContent(content);
}

// Set
void XMLNode :: setType(std::string type) {
	this -> type = type;
}

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
std::string XMLNode :: getType() const {
	return type;
}

std::vector<XMLNode*> XMLNode :: getChildren() const {
	return children;
}

std::vector<std::tuple<std::string, std::string>> XMLNode :: getTags() const {
	return tags;
}

std::string XMLNode :: getContent() const {
	return content;
}

// Methods
void XMLNode :: print() const {
	std::cout << "Type: " << type << "\n";
	std::cout << "Tags:\n";
	for(std::tuple<std::string, std::string> t : tags) {
		std::cout << "\t" << std::get<0>(t) << "\t" << std::get<1>(t) << "\n";
	}
	std::cout << "Content: " << content << std::endl;
}
