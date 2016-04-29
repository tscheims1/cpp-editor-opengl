/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of drawing class
purpose: this class provides the interface to manage the geometric figures
         of a drawing. This includes functions to display, append, remove
         and the functionality to save/load figures from a file.

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;



// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Drawing.h"
#include "../inc/Geom.h"



// static data definitions ////////////////////////////////////////////////////
vector<Geometry*>CDrawing::objects;



///////////////////////////////////////////////////////////////////////////////
// function: displayDrawing()
// purpose:  This function is called, if the GLUT window handler decides to
//           draw or redraw the window. This happens for instance if the user
//           draws a new figure or resizes or min/maximizes the window.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::displayDrawing( EViewMode mode )
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: insert code to draw and list figures

	// check for viewing mode
	vector<Geometry*>::iterator it;
    it = objects.begin();
	if ( mode == VIEW_DRAWING )
	{
        for(;it != objects.end();it++)
        {
            (*it)->draw();
        }
	}
	else // VIEW_LISTING
	{
		for(;it != objects.end();it++)
        {
            (*it)->list();
        }
	}
}
// CDrawing::displayDrawing() /////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: clearDrawing()
// purpose:  This function is called, if the user exits the application or
//           if the user clears the window or opens an existing drawing from
//           a file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::clearDrawing( void )
///////////////////////////////////////////////////////////////////////////////
{
	vector<Geometry*>::iterator it;
    it = objects.begin();
    for(;it != objects.end();it++)
    {
        delete (*it);
    }
    objects.clear();

}
// CDrawing::clearDrawing() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: appendFigure()
// purpose:  This function is called, if the user starts drawing a new
//           figure in the window. For lines, rectangles and circles this
//           function is constantly called, until the user stops drawing by
//           releasing the left mouse button.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::appendFigure(EFigType figtype, const CPoint& p1, const CPoint& p2)
///////////////////////////////////////////////////////////////////////////////
{
	//{ FIG_POINT=0x00, FIG_LINE=0x10, FIG_RECT=0x20, FIG_CIRCLE=0x30 }
    switch(figtype)
    {
        case FIG_POINT:
            objects.push_back(new CPoint(p1));
        break;
        case FIG_LINE:
            objects.push_back(new CLine(p1,p2));
            break;
        case FIG_RECT:
            objects.push_back(new CRect(p1,p2));
            break;
        case FIG_CIRCLE:
            objects.push_back(new CCircle(p1,p1.getDistance(p2)));
            break;

    }
}
// CDrawing::appendFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: removeFigure()
// purpose:  This function is called, to remove temporary figures while the
//           user is interactively drawing lines, rectangles or circles.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::removeFigure( void )
///////////////////////////////////////////////////////////////////////////////
{
    delete objects.back();
    objects.pop_back();
}

// CDrawing::removeFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: loadDrawingFile()
// purpose:  This function is called, if the user loads a figure drawing
//           file from external storage. The read data will be used to re-
//           instantiate the corresponding figure objects.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::loadDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
    CCircle c;
    c.load("20 30 10");
    objects.push_back(new CCircle(c));
	// TODO: add drawing file reading code here
}
// CDrawing::loadDrawingFile() ////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: saveDrawingFile()
// purpose:  This function is called, if the user saves a figure drawing
//           file to external storage. The filename parameter contains the
//           user selected file path of the drawing file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::saveDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: add drawing file writing code here
}
// CDrawing::saveDrawingFile() ////////////////////////////////////////////////
