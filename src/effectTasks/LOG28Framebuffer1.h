#pragma once


#include "Task.h"

class LOG28Framebuffer1 : public Task{

public:
    LOG28Framebuffer1();

    ~LOG28Framebuffer1();

    void OnRender() override;

    void OnImGuiRender() override;
};
