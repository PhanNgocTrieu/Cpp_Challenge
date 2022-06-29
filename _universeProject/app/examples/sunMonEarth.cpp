#include "_common_dic.h"
#include "_button.h"

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

// Is called whenever a mouse button is pressed/released via GLFW
void mouse_callback(GLFWwindow* window, int button, int action, int modifier)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_1) {
        std::cout << "Already Pressed Here!" << std::endl;
    }
}


void drawingCircle(GLfloat red, GLfloat green, GLfloat blue) {
    
    float xPos = 0;
    float yPos = 0;
    float radius = 1.0f;   

    int steps = 360;
    float angles = 3.1415926 * 2 / steps;

    float prevX = xPos;
    float prevY = yPos - radius;
    
    for (int i = 0; i <= steps; i++) {

        float newX = radius * sin(angles*i);
        float newY = -radius * cos(angles*i);

        glColor3f(red, green, blue);
        glBegin(GL_TRIANGLES);
        glColor3f(0, 0.5f, 0.5f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(prevX, prevY, 0.0f);
        glVertex3f(newX, newY, 0.0f);
        glEnd();

        prevX = newX;
        prevY = newY;
    }
}

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

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_callback);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
 

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.2,0.2,0.2);

    float angle = 0;
    float angleMoon = 0;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        angle += 1;
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        // The sun
        drawingCircle(1.0,1.0,1.0);

        {
            // The earth
            glPushMatrix();
            glRotatef(angle,0,0,1);
            glTranslatef(0,2,0);
            glScalef(0.2,0.2,1);
            drawingCircle(0, 0.3, 1);

            {
                // The moon
                glPushMatrix();
                glRotatef(angleMoon, 0,0,1);
                glTranslatef(0,3,0);
                glScalef(0.5,0.5,1);
                drawingCircle(0.5,0.5,0.5);
                glPopMatrix();
                angleMoon += 3;
            }

            glPopMatrix();

        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();


        /**
         * Revert bit
         */
        // toggle = !toggle;
    }

    glfwTerminate();

    return 0;
}