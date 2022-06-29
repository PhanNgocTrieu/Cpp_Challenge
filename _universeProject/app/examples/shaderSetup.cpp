#include "_common_dic.h"
#include "_button.h"

// // Is called whenever a key is pressed/released via GLFW
// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
// {
//     if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
//         glfwSetWindowShouldClose(window, GL_TRUE);
//     }
// }

// // Is called whenever a mouse button is pressed/released via GLFW
// void mouse_callback(GLFWwindow* window, int button, int action, int modifier)
// {
//     double xpos, ypos;
//     glfwGetCursorPos(window, &xpos, &ypos);
//     if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_1) {
//         std::cout << "Already Pressed Here!" << std::endl;
//     }
// }


const GLchar* vertex120 = R"END(
#version 120
attribute vec4 inColor;
attribute vec4 inPosition;
uniform mat4 matrix;
varying vec4 outColor;
void maind() {
    outColor = inColor;
    gl_Position = inPosition * matrix; // * inPosition;
}
)END";

const GLchar* raster120 = R"END(
#version 120
varying vec4 outColor;
void maind() {
    gl_FragColor = outColor;
}
)END";


int main(int argc, char** argv) {
    
    GLFWwindow* window;
    
    // initializing
    if (glfwInit() == GLFW_FALSE) {
        return 0;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800,800,"Application GUI", 0, 0);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // glfwSetKeyCallback(window, key_callback);
    // glfwSetMouseButtonCallback(window, mouse_callback);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    // Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex120, 0);
    glCompileShader(vertexShader);

    GLint compilationStatus;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compilationStatus);
    if (compilationStatus == GL_FALSE) {
        GLchar message[256];
        glGetShaderInfoLog(vertexShader, sizeof(message), 0, &message[0]);
        std::cout << message << std::endl;
        exit(1);
    }

    // Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &raster120, 0);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compilationStatus);
    if (compilationStatus == GL_FALSE) {
        GLchar message[256];
        glGetShaderInfoLog(fragmentShader, sizeof(message), 0, &message[0]);
        std::cout << message << std::endl;
        exit(1);
    }

    
    // Shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &compilationStatus);
    if (compilationStatus == GL_FALSE) {
        GLchar message[256];
        glGetShaderInfoLog(shaderProgram, sizeof(message), 0, &message[0]);
        std::cout << message << std::endl;
        exit(1);
    }

    glUseProgram(shaderProgram);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   

        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}