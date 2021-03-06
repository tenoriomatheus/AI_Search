#pragma once

#include <climits>
#include <minimaxstate.h>
#include <algorithm>

template <typename T>
class MiniMax
{
    int _limit;

    int max(int first, int second)
    {
        int out = first;
        if (first < second)
            out = second;
        return out;
    }

    int min(int first, int second)
    {
        int out = first;
        if (first > second)
            out = second;
        return out;
    }

    int valMax(MiniMaxState<T>* state)
    {
        if (isTerminal(state))
            return state->genUtility();

        int val = INT_MIN;
        state->genSuccessors();
        std::vector<MiniMaxState<T>*> successors = state->getSuccessors();
        for (MiniMaxState<T>* s : successors)
        {
            val = max(val, valMin(s));
        }
        state->setUtility(val);
        return val;
    }

    int valMin(MiniMaxState<T>* state)
    {
        if (isTerminal(state))
            return state->genUtility();

        int val = INT_MAX;
        state->genSuccessors();
        std::vector<MiniMaxState<T>*> successors = state->getSuccessors();
        for (MiniMaxState<T>* s : successors)
        {
            val = min(val, valMax(s));
        }
        state->setUtility(val);
        return val;
    }

    bool isTerminal(MiniMaxState<T>* state)
    {
        bool out = false;
        if (_limit < 0)
        {
            out = state->isFinal();
        }
        else
        {
            out = state->isFinal() || state->getDepth() >= _limit;
        }
        return out;
    }

    MiniMaxState<T>* findNextState(MiniMaxState<T>* state, int value)
    {
        std::vector<MiniMaxState<T>*> successors = state->getSuccessors();
        MiniMaxState<T>* out = nullptr;

        for(MiniMaxState<T>* s : successors)
        {
            if (s->getUtility() == value)
            {
                out = s;
            }
        }

        return out;
    }
public:
    MiniMax(int limit) : _limit(limit)
    {
    }
    virtual ~MiniMax()
    {
    }

    MiniMaxState<T>* getNextMovment(MiniMaxState<T>* currentState)
    {
        int val = valMax(currentState);
        MiniMaxState<T>* out = findNextState(currentState, val);
        return out;
    }
};
