#pragma once

#include "effectTasks/Task.h"
#include "Context.h"
#include <GL/osmesa.h>



class OffscreenCtx :public Context{

private:
    int m_Width, m_Height, m_FrameNum;
    OSMesaContext ctx;
    GLubyte *osmesa_buffer;

public:
    OffscreenCtx(int width, int height);
    ~OffscreenCtx();

    void show(Task *task) override;
};

