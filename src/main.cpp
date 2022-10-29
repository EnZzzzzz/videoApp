#include "export/Window.h"
#include "effectTasks/TaskTriangle.h"

int main()
{
    int w = 630;
    int h = 360;
    auto ctx = Context::MakeWindow(w, h, "test");

    Task* task;
    TaskTriangle tri = TaskTriangle();

    task = &tri;
    ctx->show(task);

    return 0;
}