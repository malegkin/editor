#pragma once

#include "stdafx.h"

class IObserver
{
public:
    virtual void update() = 0;
    virtual ~IObserver() = default;
};

class Observable
{
    std::vector<std::shared_ptr<IObserver>> _observers;

public:
    void addObserver(std::shared_ptr<IObserver> observer)
    {
        _observers.push_back(observer);
    }

    void notifyUpdate()
    {
        for (auto a: _observers){
            a->update();
        }
    }
};
