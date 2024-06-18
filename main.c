#include <stdio.h>
#include <leif/leif.h>
#include <GLFW/glfw3.h>

int WIDTH = 800;
int HEIGHT = 600;

GLFWwindow* window; 
bool isRunning = true;

void onKeyPressed(GLFWwindow*,int,int,int,int);
void onSizeChanged(GLFWwindow*,int,int);

int main(){
  glfwInit();
  
  window = glfwCreateWindow(WIDTH,HEIGHT,"TODO",NULL,NULL);
 
  glfwMakeContextCurrent(window);
  glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

  lf_init_glfw(WIDTH,HEIGHT,window);

  glfwSetKeyCallback(window, onKeyPressed);
  glfwSetWindowSizeCallback(window,onSizeChanged);

  while(!glfwWindowShouldClose(window) && isRunning){
     glClear(GL_COLOR_BUFFER_BIT);
     glClearColor(0.1f,0.1f,0.1f,1.0f);

     lf_begin();

     lf_div_begin(((vec2s){0, 0}),((vec2s){WIDTH, HEIGHT}),false);
     lf_text("Hello World!");
     lf_div_end();

     lf_end();

     glfwPollEvents();
     glfwSwapBuffers(window);
  }

  printf("The app has been closed...");

  free(window);

  return 0;
}

void onKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods){
   if(key == GLFW_KEY_ESCAPE){
      glfwDestroyWindow(window);
      isRunning = false;
      free(window);   
   }
}

void onSizeChanged(GLFWwindow* window, int width, int height){
   WIDTH = width;
   HEIGHT = height;
}
