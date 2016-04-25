/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of drawing class
purpose: this class provides the interface to manage the geometric figures
         of a drawing. This includes functions to display, append, remove
         and the functionality to save/load figures from a file.

written: U.Kuenzler
version: 1.01
/////////////////////////////////////////////////////////////////////////////*/


#ifndef _DRAWING_H_
#define _DRAWING_H_

// system includes ////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include "../inc/Geom.h"
using namespace std;



// forward declaration ////////////////////////////////////////////////////////
class CPoint;


class CDrawing
///////////////////////////////////////////////////////////////////////////////
{
public: // types
	enum EViewMode { VIEW_DRAWING, VIEW_LISTING };
	enum EFigType { FIG_POINT=0x00, FIG_LINE=0x10, FIG_RECT=0x20, FIG_CIRCLE=0x30 };

public: // functions
	static void displayDrawing( EViewMode mode =  VIEW_DRAWING );
	static void clearDrawing( void );
	static void appendFigure( EFigType figtype, const CPoint& p1, const CPoint& p2 );
	static void removeFigure( void );
	static void loadDrawingFile(const string& filename);
	static void saveDrawingFile(const string& filename);

private:
    static vector<Geometry*>objects;
};
#endif // _DRAWING_H_ /////////////////////////////////////////////////////////
