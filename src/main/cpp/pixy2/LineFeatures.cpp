#include "pixy2/LineFeatures.h"

LineFeatures::LineFeatures(Vector *vectors, Intersection *intersections, Barcode *barcodes)
{
	_vectors = vectors;
	_intersections = intersections;
	_barcodes = barcodes;
}

Barcode* LineFeatures::Barcodes()
{
	return _barcodes;
}

Intersection* LineFeatures::Intersections()
{
	return _intersections;
}

Vector* LineFeatures::Vectors()
{
	return _vectors;
}
