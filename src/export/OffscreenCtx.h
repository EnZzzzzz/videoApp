#pragma once

#include "effectTasks/Task.h"
#include <GL/osmesa.h>



class OffscreenCtx {

private:
    int m_Width, m_Height, m_FrameNum;
    OSMesaContext ctx;
    GLubyte *osmesa_buffer;

public:
    OffscreenCtx(int width, int height, const char *name);
    ~OffscreenCtx();

    void show(Task *&currentTask);


};

