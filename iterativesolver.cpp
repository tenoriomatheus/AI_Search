#include "iterativesolver.h"

AI_Search::IterativeSolver::IterativeSolver(State* initialState, std::function<bool(State*, State*)> searchAlgorithm, unsigned int maxSteps, bool isVerbose, bool isStepByStep) : Solver(initialState, searchAlgorithm, isVerbose, isStepByStep)
{
    _maxSteps = maxSteps;
    _initialState = initialState;
    _frontier = new Frontier(initialState, searchAlgorithm);
}
AI_Search::IterativeSolver::~IterativeSolver()
{

}

std::vector<AI_Search::Operator*> AI_Search::IterativeSolver::solve()
{
    std::vector<Operator*> listOfOperators;
    listOfOperators.clear();

    int var = 1;
    for (; var <= _maxSteps; ++var)
    {
        if (_isVerbose) std::cout << "Step " << var << std::endl;

        _frontier = new IterativeFrontier(_initialState, _frontier->getSortAlgorithm(), var);

        listOfOperators = Solver::solve();

        if (listOfOperators.size() != 0)
            break;
    }

    _stepsMade = var;

    _frontier->clearStates();

    return listOfOperators;
}

unsigned int AI_Search::IterativeSolver::getStepsMade() const
{
    return _stepsMade;
}
