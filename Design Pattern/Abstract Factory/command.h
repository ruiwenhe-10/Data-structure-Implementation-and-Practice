#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		
		double execute() {
			return root->evaluate();
		};
		
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
		OpCommand(){
			root = 0;
		};
		
		OpCommand(double a){
			root = new Op(a);
		};
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
		AddCommand(){
			root = 0;
		};
		AddCommand(Command* cmdPtr, double number){
			root = new Add(cmdPtr->get_root(), new Op(number));
		};
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
		SubCommand(){
			root = 0;
		};
		SubCommand(Command* cmdPtr, double number){
			//Op* newChild = new Op(number);
			root = new Sub(cmdPtr->get_root(),  new Op(number));
		};
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
		MultCommand(){
			root = 0;
		};
		MultCommand(Command* cmdPtr, double number){
		//	Op* newChild = new Op(number);
			root = new Mult(cmdPtr->get_root(),  new Op(number));
		};
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
		SqrCommand(){
			root = 0;
		};
		SqrCommand(Command* cmdPtr){
			//Op* newChild = new Op(number);
			root = new Sqr(cmdPtr->get_root());//, newChild);
		};
};

#endif //__COMMAND_CLASS__