#pragma once

#include "Task.h"

class TaskTriangle : public Task{
public:
    TaskTriangle();
    ~TaskTriangle();

    void OnRender() override;

private:


};

