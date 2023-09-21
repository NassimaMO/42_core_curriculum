/*
Calculate the area of the given triangle, i.e., the area of the triangle ABC in the above diagram. 
Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 
Calculate the area of the triangle PAB. We can use the same formula for this. Let this area be A1. 
Calculate the area of the triangle PBC. Let this area be A2. 
Calculate the area of the triangle PAC. Let this area be A3. 
If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.
*/

#include "Point.hpp"

float   getTriangleArea( Point const p1, Point const p2, Point const p3 )
{
    //std::cout << p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) << std::endl;
    return (( p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) + p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) + p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float   AreaA = getTriangleArea(a, b , c);
    float   AreaB = getTriangleArea(point, b , c);
    float   AreaC = getTriangleArea(a, point , c);
    float   AreaP = getTriangleArea(a, b , point);

    //std::cout << "AreaA: " << AreaA << "AreaA: " << AreaB << "AreaA: " << AreaC << "AreaA: " << AreaP << std::endl;
    if (AreaA == AreaB + AreaC + AreaP)
        return ( true );
    return ( false );
}