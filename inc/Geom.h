/*/////////////////////////////////////////////////////////////////////////////
module:  interface of geom classes (CPP-A.04_GLDraw2D)
purpose: declare the interface to all geometrical classes

written: U.Kuenzler
version: 1.01
/////////////////////////////////////////////////////////////////////////////*/


#ifndef _GEOM_H_
#define _GEOM_H_

// system includes ////////////////////////////////////////////////////////////



// application includes ///////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// class:   CPoint
// purpose: declare a two dimensional point
///////////////////////////////////////////////////////////////////////////////
class Geometry
{
    public:
    virtual void draw() = 0;
    virtual void list() = 0;
    virtual void load(string line) = 0;
};


class CPoint : public Geometry
{
	// friend declarations
	friend class CLine;
	friend class CRect;
	friend class CCircle;

private:
	float x;
	float y;
	static unsigned long ulCount;

public: // constructors and destructor
	CPoint() { x = 0; y = 0; ulCount++; }
	CPoint( float x, float y ) { CPoint::x = x; CPoint::y = y; ulCount++; }
	CPoint( const CPoint& source );
	~CPoint() { ulCount--; }

public: // functions
	CPoint operator+ ( const CPoint& pt ) const { return CPoint( x + pt.x, y + pt.y ); }
	CPoint operator- ( const CPoint& pt ) const { return CPoint( x - pt.x, y - pt.y ); }
	void set( float x, float y ) { CPoint::x = x; CPoint::y = y; }
	void list( void );
	void draw( void );
	void load(string line);
    unsigned int getDistance(const CPoint& pt) const;
	static void listCount( void )
		{ cout << "Count of points: " << ulCount << endl; }
};


///////////////////////////////////////////////////////////////////////////////
// class:   CLine
// purpose: declare a two dimensional line
///////////////////////////////////////////////////////////////////////////////
class CLine : public Geometry
{
private:
	CPoint _P1;
	CPoint _P2;
	static unsigned long ulCount;

public: // constructors and destructor
	CLine() { ulCount++; }
	CLine( float x1, float y1, float x2, float y2 );
	CLine( const CPoint& ptP1, const CPoint& ptP2 );
	CLine( const CLine& source );
	~CLine() { ulCount--; }

public: // functions
	CLine& operator=( const CLine& source );
	CLine  operator+( const CLine& addline );
	void set( float x1, float y1, float x2, float y2 );
	void list( void );
	void draw( void );
	void load(string line);
	static void listCount( void )
		{ cout << "Count of lines: " << ulCount << endl; }
};


///////////////////////////////////////////////////////////////////////////////
// class:   CRect
// purpose: declare a rectangle
///////////////////////////////////////////////////////////////////////////////
class CRect : public Geometry
{
private:
   CPoint _P1;
   CPoint _P2;
   static unsigned long ulCount;

public: // constructors and destructor
   CRect() { ulCount++; }
   CRect( float x1, float y1, float x2, float y2 );
   CRect( const CPoint& ptP1, const CPoint& ptP2 );
   CRect( const CRect& source );
   ~CRect() { ulCount--; }

public: // functions
   CRect operator+( const CRect& addrect );
   void set( float x1, float y1, float x2, float y2 );
   void list( void );
   void draw( void );
   void load(string line);
   static void listCount( void )
      { cout << "Count of rectangles: " << ulCount << endl; }
};


///////////////////////////////////////////////////////////////////////////////
// class:   CCircle
// purpose: declare a circle
///////////////////////////////////////////////////////////////////////////////
class CCircle : public Geometry
{
private:
   CPoint _P1;
   float _Radius;
   static unsigned long ulCount;

public: // constructors and destructor
   CCircle() { ulCount++; }
   CCircle( float x1, float y1, float radius );
   CCircle( const CPoint& ptP1, float radius );
   CCircle( const CCircle& source );
   ~CCircle() { ulCount--; }

public: // functions
   CCircle operator+( const CCircle& addcircle );
   void set( float x1, float y1, float radius );
   void list( void );
   void draw( void );
   void load(string line);
   static void listCount( void )
      { cout << "Count of circles: " << ulCount << endl; }
};


#endif // _GEOM_H_ ////////////////////////////////////////////////////////////
