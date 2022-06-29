#include <iostream>
#include <fstream>
#include <string>
#include <GLFW/glfw3.h>
#include "_common_dic.h"
#include <math.h>
#define GL_SILENCE_DEPRECATION 1

// vertex shader source

const GLchar* vertex120 = R"END(
#version 120
attribute vec4 inPosition;
attribute vec4 inColor;
uniform vec4 matrix;
varying vec4 outColor;
void main()
{
    outColor = inColor;
    gl_Position = inPosition;
}
)END";

// fragment shader source

const GLchar* raster120 = R"END(
#version 120
varying vec3 outColor;
void main()
{
    gl_FragColor = vec4(outColor,1);
}
)END";


const GLfloat vertices[] = {
    -1.0f, 1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    -1.0f, 1.0f, 0.0f

};

const GLfloat colors[] = {
    0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f
};

int main() {
    std::cout << __LINE__ << std::endl;
    GLFWwindow* window;
    
    // initializing
    if (glfwInit() == GLFW_FALSE) {
        return 0;
    }
    std::cout << __LINE__ << std::endl;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800,800,"Application GUI", 0, 0);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    std::cout << __LINE__ << std::endl;
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    // Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex120, 0);
    glCompileShader(vertexShader);
    std::cout << __LINE__ << std::endl;
    GLint compilationStatus;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compilationStatus);
    if (compilationStatus == GL_FALSE) {
        GLchar message[256];
        glGetShaderInfoLog(vertexShader, sizeof(message), 0, &message[0]);
        std::cout << message << std::endl;
        exit(1);
    }
    std::cout << __LINE__ << std::endl;
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

    std::cout << __LINE__ << std::endl;
    // Shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    std::cout << __LINE__ << std::endl;
    glLinkProgram(shaderProgram);

    std::cout << __LINE__ << std::endl;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &compilationStatus);

    if (compilationStatus == GL_FALSE) {
        std::cout << __LINE__ << std::endl;
        GLchar message[256];
        glGetShaderInfoLog(shaderProgram, sizeof(message), 0, &message[0]);
        std::cout << message << std::endl;
        exit(1);
    }

    glUseProgram(shaderProgram);
    std::cout << __LINE__ << std::endl;
    // VBO Setup
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    GLuint colorsBuffer;
    glGenBuffers(1, &colorsBuffer);


    // send data co GPU
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, colorsBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colorsBuffer), colors, GL_STATIC_DRAW);
    

    // Setting up attributes
    GLint attribPosition = glGetAttribLocation(shaderProgram, "inPosition");
    glEnableVertexAttribArray(attribPosition);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

    GLint attribColor = glGetAttribLocation(shaderProgram, "inColor");
    glEnableVertexAttribArray(attribColor);
    glBindBuffer(GL_ARRAY_BUFFER, colorsBuffer);
    glVertexAttribPointer(attribColor, 3, GL_FLOAT, GL_FALSE, 0, 0);


    // Uniform

    GLuint attributeMatrix = glGetUniformLocation(shaderProgram, "matrix");

    float alpha = 0;

    std::cout << __LINE__ << std::endl;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        std::cout << __LINE__ << std::endl;
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        float sa = 0.5 * sin(alpha);
        float ca = 0.5 * cos(alpha);
        alpha += 0.1;

        const GLfloat matrix[] = {
            sa, -ca, 0, 0,
            ca, sa, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
        std::cout << __LINE__ << std::endl;
        glUniformMatrix4fv(attributeMatrix, 1, GL_FALSE, matrix);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        std::cout << __LINE__ << std::endl;
        /* Poll for and process events */
        glfwPollEvents();
    }

    std::cout << __LINE__ << std::endl;
    glfwTerminate();
}
