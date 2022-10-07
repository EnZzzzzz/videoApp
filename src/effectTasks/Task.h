#pragma once

#include <string>
#include <vector>
#include <functional>
#include <iostream>


class Task {
public:
    int frameCount;
    Task():frameCount(1) {}

    virtual ~Task() {}

    virtual void OnUpdate(float deltaTime) {}

    virtual void OnRender() {}

    virtual void OnImGuiRender() {}
};

