#pragma once

#include <memory>
#include "effectTasks/Task.h"


class Context {
public:
    static std::shared_ptr<Context> MakeWindow(int w, int h, const char *name);

    static std::shared_ptr<Context> MakeOffscreen(int w, int h);

    virtual void show(Task *task) {};
};
