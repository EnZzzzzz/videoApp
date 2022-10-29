#include "glad/glad.h"
#include "OffscreenCtx.h"

std::shared_ptr<Context> Context::MakeOffscreen(int w, int h) {
    return std::make_shared<OffscreenCtx>(w, h);
}

OffscreenCtx::OffscreenCtx(int width, int height) : m_Width(width), m_Height(height), m_FrameNum(0) {

    ctx = OSMesaCreateContextExt(OSMESA_RGBA, 16, 0, 0, NULL);
    if (!ctx) {
        std::cout << "OSMesa context create failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    osmesa_buffer = (GLubyte *) malloc(height * width * 4 * sizeof(GLubyte));
    if (!OSMesaMakeCurrent(ctx, osmesa_buffer, GL_UNSIGNED_BYTE, width, height)) {
        std::cout << "OSMesa make current failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!gladLoadGLLoader((GLADloadproc) OSMesaGetProcAddress)) {
        std::cout << "Glad Init Failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout <<"OpenGL context created, GL version: "<< glGetString(GL_VERSION) << std::endl;
}

void OffscreenCtx::show(Task *currentTask) {
    for (int cnt = 0; cnt < currentTask->frameCount; cnt++) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if (currentTask) {
            currentTask->OnRender();
        }

        glFlush();
    }
}

OffscreenCtx::~OffscreenCtx() {
    free(osmesa_buffer);
    OSMesaDestroyContext(ctx);
}
