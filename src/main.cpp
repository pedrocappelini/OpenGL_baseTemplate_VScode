#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "DISPLAY", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to open GLFW window" << endl;
        return -1;
    }
    
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    int windowWidth = 800;
    int windowHeight = 600;
    
    int windowPosX = (mode->width - windowWidth) / 2;
    int windowPosY = (mode->height - windowHeight) / 2;
    
    glfwSetWindowPos(window, windowPosX, windowPosY);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glClearColor(0.678f, 0.847f, 0.902f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
