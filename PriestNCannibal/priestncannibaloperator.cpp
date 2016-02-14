#include "priestncannibaloperator.h"

PriestNCannibalOperator::PriestNCannibalOperator(State<PriestNCannibalId*>* startState, int priestAmount, int cannibalAmount, bool isStartToGoal)
    : Operator<PriestNCannibalId*>(startState), _priestAmount(priestAmount), _cannibalAmount(cannibalAmount), _isStartToGoal(isStartToGoal)
{
}

PriestNCannibalOperator::~PriestNCannibalOperator()
{
}

int PriestNCannibalOperator::getPriestAmount() const
{
    return _priestAmount;
}

int PriestNCannibalOperator::getCannibalAmount() const
{
    return _cannibalAmount;
}

bool PriestNCannibalOperator::isStartToGoal() const
{
    return _isStartToGoal;
}
