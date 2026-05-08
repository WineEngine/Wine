#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "util.h"

GLFWwindow* window;

int
main(int argc, char *argv[])
{
    if (!glfwInit())
        error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    
    window = glfwCreateWindow( 1024, 768, PROGNAME, NULL, NULL);
    if( window == NULL ){
        glfwTerminate();
        error("Failed to open GLFW window" );
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        error("Failed to initialize GLAD");
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do{
        glClear( GL_COLOR_BUFFER_BIT );
        glfwSwapBuffers(window);
        glfwPollEvents();
    
    }
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
       glfwWindowShouldClose(window) == 0 );
    return 0;
}
