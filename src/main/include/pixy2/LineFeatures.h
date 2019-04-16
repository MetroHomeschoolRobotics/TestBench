#pragma once

#include <vector>
#include <cstdint>
//#include "Intersection.h"
//#include "Barcode.h"
//#include "Vector.h"

static const std::uint8_t LINE_MAX_INTERSECTION_LINES = 6;

struct Vector
{
  void print()
  {
    char buf[64];
    //sprintf(buf, "vector: (%d %d) (%d %d) index: %d flags %d", m_x0, m_y0, m_x1, m_y1, m_index, m_flags);
	  //Serial.println(buf);
  }

  std::uint8_t m_x0;
  std::uint8_t m_y0;
  std::uint8_t m_x1;
  std::uint8_t m_y1;
  std::uint8_t m_index;
  std::uint8_t m_flags;
};

struct IntersectionLine
{
  std::uint8_t m_index;
  std::uint8_t m_reserved;
  std::int16_t m_angle;
};

struct Intersection
{
  
  std::uint8_t m_x;
  std::uint8_t m_y;
	
  std::uint8_t m_n;
  std::uint8_t m_reserved;
  IntersectionLine m_intLines[LINE_MAX_INTERSECTION_LINES];

  void print()
  {
    char buf[64];
    std::uint8_t i;
    //sprintf(buf, "intersection: (%d %d)", m_x, m_y);
	  //Serial.println(buf);
    for (i=0; i<m_n; i++)
    {
      //sprintf(buf, "  %d: index: %d angle: %d", i, m_intLines[i].m_index, m_intLines[i].m_angle);
	    //Serial.println(buf);
    }
  }
};

struct Barcode
{
  std::uint8_t m_x;
  std::uint8_t m_y;
  std::uint8_t m_flags;
  std::uint8_t m_code;
  void print()
  {
    char buf[64];
    //sprintf(buf, "Barcode: (%d %d), val: %d flags: %d", m_x, m_y, m_code, m_flags);
    //Serial.println(buf);
  }
  
};

class LineFeatures
{
	private:
		Vector* _vectors;
		Intersection* _intersections;
		Barcode* _barcodes;

	public:
		LineFeatures(Vector *vectors, Intersection *intersections, Barcode *barcodes);

		virtual Barcode* Barcodes();

		virtual Intersection* Intersections();

		virtual Vector* Vectors();
};
