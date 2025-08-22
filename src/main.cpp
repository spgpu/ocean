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

    /***************************/

    const char *vshaderSource =
        "#version 430 \n"
        "void main(void) \n"
        "{ gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";

    const char *fshaderSource =
        "#version 430 \n"
        "out vec4 color; \n"
        "void main(void) \n"
        "{ color = vec4(1.0, 0.0, 0.0, 1.0); }";

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vshaderSource, NULL);
    glCompileShader(vShader);
    
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fshaderSource, NULL);
    glCompileShader(fShader);    

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);
        
    /***************************/

    GLuint vao[1];
    glGenVertexArrays(1, vao);
    glBindVertexArray(vao[0]);
    
    // Rendering loop
    while(!glfwWindowShouldClose(window)) {

        // This could be a function handling all keys.
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(vfProgram);
        glDrawArrays(GL_POINTS, 0, 1);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
