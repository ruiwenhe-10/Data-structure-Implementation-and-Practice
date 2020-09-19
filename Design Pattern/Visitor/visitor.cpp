#include "visitor.h"
#include "composite.h"

#include <iostream>
#include <string>

using namespace std;

void PrintVisitor::rootNode() {
	return;
}

void PrintVisitor::sqrNode() {
	output += "^ ";
}

void PrintVisitor::multNode() {
	output += "* ";
}

void PrintVisitor::addNode() {
	output += "+ ";
}

void PrintVisitor::subNode() {
	output += "- ";
}

void PrintVisitor::opNode(Op* op) {
	output += to_string(static_cast<int>(op->evaluate()));
	output += " ";
}

void PrintVisitor::execute() {
	cout << output << endl;
}