#include "Graphics.h"
#include "Mouse.h"
#include "Game.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1050, 650, "Tic Tac Toe", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSetWindowPos(window, 450, 200);

        int row;
        int col;
        HWND game = glfwGetWin32Window(window);
        if (game == GetForegroundWindow())
        {
            drawBoard();
            glBegin(GL_LINES); //splits the board into 9 parts
            glVertex2f(-0.33f, 1); glVertex2f(-0.33f, -1);
            glVertex2f(0.33f, 1); glVertex2f(0.33f, -1);
            glVertex2f(-1, -0.33f); glVertex2f(1, -0.33f);
            glVertex2f(-1, 0.33f); glVertex2f(11, 0.33f);
            glEnd();
            if (GetAsyncKeyState(VK_LBUTTON) & 0x01 && CheckValidity())
            {
                row = getRowIndex();
                col = getColIndex();
                play(row, col);
                CheckEnding();
            }
            // Execute Game
        }

      



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void drawX(float starting_x, float starting_y)
{
    glBegin(GL_LINES);

    glVertex2f(starting_x, starting_y); glVertex2f(starting_x + 0.3, starting_y - 0.3);
    glVertex2f(starting_x, starting_y - 0.3); glVertex2f(starting_x + 0.3, starting_y);

    glEnd();
}

void drawO(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}