#pragma once

#include "LOG28Framebuffer1.h"


LOG28Framebuffer1::LOG28Framebuffer1() {
    glEnable(GL_DEPTH_TEST);
}

void LOG28Framebuffer1::OnRender() {
    Task::OnRender();
}

void LOG28Framebuffer1::OnImGuiRender() {
    Task::OnImGuiRender();
}

LOG28Framebuffer1::~LOG28Framebuffer1() {

}

