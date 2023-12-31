#include "glfw/include/GLFW/glfw3.h"
#include <iostream>

int main()
{
    GLFWwindow *window;

    if(!glfwInit())
    {
        fprintf(stder, "Failed to initialized GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(300, 300, "Gears"), NULL, NULL);

    if(!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /*Main Loop*/
    while(!glfwWindowShouldClose(window))
    {
        //Draw gears
        //draw();

        //Update animation
        //animate()

        //Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Terminate GLFW
    glfwTerminate();

    return 0;
}