#include "ASFExpression.h"

ASFExpression::ASFExpression(const vector<string> items):Action(EXPRESSION){

	tokens = items;
}

/* <A.P.> The execution of an expression relies on the variable table and variable stack stack provided by another entity.
   The former contains variables considered by the expression, while the latter is used to actually execute the expression.
   At the end, the variable stored in the variable table and aimed at containing the expression result is updated */
void ASFExpression::execute( map<string, Variable*> *varTable, stack<Variable> *stack_){

	Variable left_operand, right_operand;

	for(int i = 0; i < tokens.size(); i++){


		/* Declare an iterator to visit the variable table */
		std::map<std::string, Variable *>::iterator iter = varTable->find(tokens[i]);

		/* An operand has been found */
		if( iter != varTable->end() ){

			/* Insert the operand into the stack */
			stack_->push( *(iter->second) );

		}else{ // An operator has been found

			string op = tokens[i];

			if( !operatorModifier(op) ){

				/* Retrieve the operands */
				right_operand = stack_->top();
				stack_->pop();

				left_operand = stack_->top();
				stack_->pop();
				
				/* Perform the operation and insert the result into the stack */
				if( op == "+")
					stack_->push( left_operand + right_operand);
				else if( op == "-")
					stack_->push( left_operand - right_operand);
				else if( op == "*")
					stack_->push( left_operand * right_operand);
				else if( op == "/")
					stack_->push( left_operand / right_operand);
				else if( op == "%")
					stack_->push( left_operand % right_operand);
				else if( op == "==")
					stack_->push( left_operand == right_operand);
				else if( op == ">")
					stack_->push( left_operand > right_operand);
				else if( op == "<")
					stack_->push( left_operand < right_operand);
				else if( op == ">=")
					stack_->push( left_operand >= right_operand);
				else if( op == "<=")
					stack_->push( left_operand <= right_operand);
				else if( op == "!=")
					stack_->push( left_operand != right_operand);
				else if( op == "&&")
					stack_->push( left_operand && right_operand);
				else if( op == "||")
					stack_->push( left_operand || right_operand);



			}else{ // The operator include an assignment
				i++;
				string where = tokens[i];

				/* Declare an iterator to visit the variable table */
				std::map<std::string, Variable *>::iterator iter = varTable->find(where);

				Variable value;

				value = stack_->top();
				stack_->pop();

				if( op == "=")
					*(iter->second) = value;
				else if( op == "+=")
					*(iter->second) += value;
				else if( op == "-=")
					*(iter->second) -= value;
				else if( op == "*=")
					*(iter->second) *= value;
				else if( op == "/=")
					*(iter->second) /= value;
				else if( op == "%=")
					*(iter->second) %= value;
					
			}
			
		}

	}// END FOR

}

/* <A.P.> Return true if the considered operator includes an assigment, false otherwise */
bool ASFExpression::operatorModifier( const string op ){

	if( op == "=" || op == "+=" || op == "-="  || op == "*=" || op == "/=" || op == "%="  )
		return true;

	return false;
}
