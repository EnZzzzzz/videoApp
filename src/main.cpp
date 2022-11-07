#include "export/Window.h"
#include "effectTasks/TaskTriangle.h"
#include "effectTasks/OG7Camera2.h"

int main()
{
    int w = 1000;
    int h = 800;
    auto ctx = Context::MakeWindow(w, h, "test");

    TaskMenu taskMenu = TaskMenu();
    taskMenu.RegisterTest<TaskTriangle>("TestTriangle");
    taskMenu.RegisterTest<OG7Camera2>("OG7Camera2");
    Task* task;

    task = &taskMenu;
    ctx->show(task);

    return 0;
}