/*//////////////////////////////////////////////////////////////////////////////////////////////////
module:  implementation of GLDraw2D main module
purpose: implements the main function and does the OpenGL/GLUT initialization

written: U.Kuenzler
version: 2.00 - rewrite for platform independant FLTK library
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
//////////////////////////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;


// OpenGL helper includes /////////////////////////////////////////////////////////////////////////
#include <GL/glew.h>
#include <FL/glut.H>


// application helper includes ////////////////////////////////////////////////////////////////////
#include "../../_COMMON/inc/TrackBall.h"
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Drawing.h"
#include "../inc/CmdHandler.h"



void glutDisplayCB(void)
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// clear window background
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0F, 0.0F, 1.0F);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		// init coordinates to adjust for mouse input coordinates
		glTranslatef(0.0, (GLfloat)glutGet(GLUT_WINDOW_HEIGHT), 0.0);
		glScalef(1.0, -1.0, 1.0);

		// call drawing display function for figure drawing
		CDrawing::displayDrawing();
	glPopMatrix();

	glutSwapBuffers();
}
///////////////////////////////////////////////////////////////////////////////////////////////////



void initRendering()
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// clear window background
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set background color
	glClearColor( 1.0F, 1.0F, 1.0F, 1.0F );

	// set default color
	glColor3f(1.0F, 0.0F, 0.0F);

	// general init
	glDisable(GL_DEPTH_TEST);
	glDisable( GL_CULL_FACE );
	glDisable(GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// setup modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
///////////////////////////////////////////////////////////////////////////////////////////////////



void glutResizeCB(int width, int height)
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}
///////////////////////////////////////////////////////////////////////////////////////////////////


void glutKeyboardCB(unsigned char key, int x, int y)
///////////////////////////////////////////////////////////////////////////////////////////////////
{
    switch (key)
    {
        case 'q': case 'Q': case 27: // escape key
		{
			CCmdHandler::glutMainMenuCB(1);
			break;
		}
		case 9: // tabulator key
		{
			break;
		}
        case ' ':
		{
			break;
		}
        case '1':
		{
			CCmdHandler::glutMainMenuCB(0);
			break;
		}
		default:
		{
			cout << "Key not supported '" << key << "' (" << int(key) << ")" << endl;
		}
	}
	glutPostRedisplay();
}
///////////////////////////////////////////////////////////////////////////////////////////////////



int main(int argc, char** argv)
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	// init GLUT/FLTK settings
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);

	glutCreateWindow("GLDraw2D");

	// show version of OpenGL
	cout << "OpenGL Version: " << glGetString(GL_VERSION) << endl;

	// register GLUT/FLTK callbacks
	glutDisplayFunc(glutDisplayCB);
	glutKeyboardFunc(glutKeyboardCB);
	glutReshapeFunc(glutResizeCB);

	// register mouse handler callbacks
	glutMouseFunc(TrackBall::glutMouseButtonCB);
	glutMotionFunc(TrackBall::glutMouseMotionCB);
	glutSpecialFunc(TrackBall::glutSpecialFuncCB);

	// init application
	initRendering();
	CCmdHandler::initCmdHandler();
	CCmdHandler::glutInitMenu();

	try
	{
		// enter GLUT main event loop until user exits
		glutMainLoop();
	}
	catch (...)
	{
		// catch all unhandled exception and show error message
		UtilFLTK::showMessageBox( "Unknown Exception: Aborting GLDraw2D!" );
	}
	return 0;  // only for compatibility purposes
}
///////////////////////////////////////////////////////////////////////////////////////////////////
