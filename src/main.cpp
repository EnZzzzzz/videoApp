#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "export/OffscreenCtx.h"
#include "export/Window.h"
#include "effectTasks/TaskTriangle.h"

int main()
{
//    OffscreenCtx ctx = OffscreenCtx(630, 360, "test");
    auto ctx = Window(630, 360, "test");

    Task* task;
    TaskTriangle tri = TaskTriangle();

    task = &tri;
    ctx.show(task);

    return 0;
}