/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of command handler class
purpose: this class handles all commands and events from user and mouse

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/




// system includes ////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;


// OpenGL helper includes /////////////////////////////////////////////////////////////////////////
#include <FL/glut.H>


// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/TrackBall.h"
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Geom.h"
#include "../inc/Drawing.h"
#include "../inc/CmdHandler.h"


// static data definitions ////////////////////////////////////////////////////
CDrawing::EFigType CCmdHandler::_DrwawingFigure = CDrawing::FIG_POINT;



void CCmdHandler::initCmdHandler()
///////////////////////////////////////////////////////////////////////////////
{
	TrackBall::registerMouseButton(CCmdHandler::MouseButtonCB);
	TrackBall::registerMouseMotion(CCmdHandler::MouseMotionCB);
}


void CCmdHandler::MouseButtonCB(int x1, int y1, int x2, int y2)
///////////////////////////////////////////////////////////////////////////////
{
	CDrawing::appendFigure(_DrwawingFigure, 
		CPoint((float)x1,(float)y1), CPoint((float)x2,(float)y2));
}


void CCmdHandler::MouseMotionCB(int x1, int y1, int x2, int y2)
///////////////////////////////////////////////////////////////////////////////
{
	CDrawing::removeFigure();
	CDrawing::appendFigure(_DrwawingFigure, 
		CPoint((float)x1,(float)y1), CPoint((float)x2,(float)y2));
}


void CCmdHandler::glutInitMenu()
///////////////////////////////////////////////////////////////////////////////
{
	// create file sub menu
	int file_menu = glutCreateMenu(glutFileMenuCB);
	glutAddMenuEntry(" Open ...", 1);
	glutAddMenuEntry(" Save As ...", 2);


	// create view sub menu
	int view_menu = glutCreateMenu(glutViewMenuCB);
	glutAddMenuEntry("  Clear All ", 1);
	glutAddMenuEntry("  Show Listing ", 2);

	// create draw sub menu
	int draw_menu = glutCreateMenu(glutDrawMenuCB);
	glutAddMenuEntry("  Points ", 1);
	glutAddMenuEntry("  Lines  ", 2);
	glutAddMenuEntry("  Rectangles ", 3);
	glutAddMenuEntry("  Circles", 4);

	// create main menu
	glutCreateMenu(glutMainMenuCB);
	glutAddMenuEntry(" Commands ", 0);
	glutAddSubMenu  ("  File", file_menu);
	glutAddSubMenu  ("  View", view_menu);
	glutAddSubMenu  ("  Draw", draw_menu);
	glutAddMenuEntry("  Exit", 1);

	// attach menu to right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
// MenuHandler::glutInitMenu() ////////////////////////////////////////////////




void CCmdHandler::glutMainMenuCB(int item)
///////////////////////////////////////////////////////////////////////////////
{
	switch (item)
	{
	case 0:
		{
			break;
		}
	case 1:
		{
			exit(0);
			break;
		}
	case 2:
		{
			break;
		}
	default:
		{
			cout << "ERROR: invalid glutMainMenuCB() item!" << endl;
		}
	}
	glutPostRedisplay();
}
///////////////////////////////////////////////////////////////////////////////




void CCmdHandler::glutFileMenuCB(int item)
///////////////////////////////////////////////////////////////////////////////
{
	switch (item)
	{
	case 0:
		{
			break;
		}
	case 1: // open drawing file
		{
			// get file path to open a GLDraw2D drawing file
			string filter = "GLDraw2D Drawing\t *.drw\n";
			string filepath;
			if (UtilFLTK::getFilePath(filepath, filter, ".\res", true) )
			{
				glutSetCursor(GLUT_CURSOR_WAIT);
				CDrawing::loadDrawingFile(filepath);
				glutSetCursor(GLUT_CURSOR_INHERIT);
			}
			break;
		}
	case 2: // save drawing file
		{
			// get file path to save a GLDraw2D drawing file
			string filter = "GLDraw2D Drawing\t *.drw\n";
			string filepath;
			if ( UtilFLTK::getFilePath(filepath, filter, "", false) )
			{
				glutSetCursor(GLUT_CURSOR_WAIT);
				CDrawing::saveDrawingFile(filepath);
				glutSetCursor(GLUT_CURSOR_INHERIT);
			}
			break;
		}
	default:
		{
		}
	}

	glutPostRedisplay();
}
///////////////////////////////////////////////////////////////////////////////



void CCmdHandler::glutViewMenuCB(int item)
///////////////////////////////////////////////////////////////////////////////
{
	switch (item)
	{
	case 0:
		{
			break;
		}
	case 1:
		{
			CDrawing::clearDrawing();
			break;
		}
	case 2:
		{
			CDrawing::displayDrawing(CDrawing::VIEW_LISTING);
			break;
		}
	case 3:
		{
			break;
		}
	case 4:
		{
			break;
		}
	default:
		{
		}
	}

	glutPostRedisplay();
}
///////////////////////////////////////////////////////////////////////////////



void CCmdHandler::glutDrawMenuCB(int item)
///////////////////////////////////////////////////////////////////////////////
{
	// std::cout << "DEBUG: glutDrawMenuCB(): " << item << std::endl;

	switch (item)
	{
	case 0:
		{
			break;
		}
	case 1: // draw points
		{
			_DrwawingFigure = CDrawing::FIG_POINT;
			break;
		}
	case 2: // draw lines
		{
			_DrwawingFigure = CDrawing::FIG_LINE;
			break;
		}
	case 3: // draw rectangles
		{
			_DrwawingFigure = CDrawing::FIG_RECT;

			break;
		}
	case 4: // draw circles
		{
			_DrwawingFigure = CDrawing::FIG_CIRCLE;
			break;
		}
	case 5:
		{
			break;
		}
	default:
		{
		}
	}

	glutPostRedisplay();
}
///////////////////////////////////////////////////////////////////////////////