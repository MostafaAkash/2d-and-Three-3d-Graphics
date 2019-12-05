#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

   // Define shapes enclosed within a pair of glBegin and glEnd

    //glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-100,100,-100,100);     // To operate on Model-View matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   // gluOrtho2D(-100,100,-100,100);             // Reset the model-view matrix
glPushMatrix();
  //glTranslatef(0.0f, 0.0f, 0.5f);
 // gluOrtho2D(-100,100,-100,100);

   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2d(-70,40);     // Define vertices in counter-clockwise (CCW) order
      glVertex2d(-70, 10);     //  so that the normal (front-face) is facing you
      glVertex2d(-50,10);
      glVertex2d(-50,40);

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.2f, 0.0f, -0.0f);
   //  gluOrtho2D(-100,100,-100,100);
       glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 1.0f, 1.0f); // Red
      glVertex2d(-70,40);     // Define vertices in counter-clockwise (CCW) order
      glVertex2d(-70, 10);     //  so that the normal (front-face) is facing you
      glVertex2d(-50,10);
      glVertex2d(-50,40);

    glEnd();

glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f);

      //glOrtho(-100,100,-100,100,-200,200);
       glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 1.0f, 0.0f); // Red
      glVertex3d(-70,40,0);     // Define vertices in counter-clockwise (CCW) order
      glVertex3d(-70, 10,0);    //  so that the normal (front-face) is facing you
      glVertex3d(-50,10,0);
      glVertex3d(-50,40,0);

    glEnd();

glPopMatrix();

   glFlush();  // Render now
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      //gluOrtho2D(-100.0 * aspect, 100.0 * aspect, -100.0, 100.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
    // gluOrtho2D(-100.0, 100.0, -100.0 / aspect, 100.0 / aspect);
   }
  // gluOrtho2D(-50,50,-50,50);
  //gluOrtho2D(-100,100,-100,100);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Viewport Transform");  // Create window with the given title

   glutDisplayFunc(display);       // Register callback handler for window re-paint event

  // glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
