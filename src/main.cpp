#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

const int INITIAL_WIDTH = 500;
const int INITIAL_HEIGHT = 400;

void framebuffer_size_callback(GLFWwindow* w, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    std::cout << "Hello world." << std::endl;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(
                            INITIAL_WIDTH, INITIAL_HEIGHT,
                            "Wagmi", NULL, NULL);

    if(window == NULL) {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return 2;
    }

    glfwMakeContextCurrent(window);
    
    if(!gladLoadGL(glfwGetProcAddress)) {
        std::cout << "Failed to init GLAD." << std::endl;
        return 1;
    };

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // Rendering loop
    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
