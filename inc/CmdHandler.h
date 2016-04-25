/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of command handler class
purpose: this class handles all commands and events from user and mouse

written: U.Kuenzler
version: 1.01
/////////////////////////////////////////////////////////////////////////////*/


#ifndef _CCMDHANDLER_H_
#define _CCMDHANDLER_H_

// system includes ////////////////////////////////////////////////////////////




class CCmdHandler
///////////////////////////////////////////////////////////////////////////////
{
private:
	static CDrawing::EFigType _DrwawingFigure;

private:
	static void glutFileMenuCB(int mode);
	static void glutViewMenuCB(int mode);
	static void glutDrawMenuCB(int mode);

	static void MouseButtonCB(int x1, int y1, int x2, int y2);
	static void MouseMotionCB(int x1, int y1, int x2, int y2);

public:
	static void initCmdHandler();	

	static void glutInitMenu();
	static void glutMainMenuCB(int mode);
};


#endif // _CCMDHANDLER_H_ /////////////////////////////////////////////////////


