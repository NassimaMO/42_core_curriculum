/*
Calculate the area of the given triangle, i.e., the area of the triangle ABC in the above diagram. 
Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 
Calculate the area of the triangle PAB. We can use the same formula for this. Let this area be A1. 
Calculate the area of the triangle PBC. Let this area be A2. 
Calculate the area of the triangle PAC. Let this area be A3. 
If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.
*/

#include "Point.hpp"

Fixed   getTriangleArea( Point const p1, Point const p2, Point const p3 )
{
    std::cout << p1.getX() * (p2.getY() - p3.getY()) << std::endl;
    return (( p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY())) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   AreaA = getTriangleArea(a, b , c);
    Fixed   AreaB = getTriangleArea(point, b , c);
    Fixed   AreaC = getTriangleArea(a, point , c);
    Fixed   AreaP = getTriangleArea(a, b , point);

    std::cout << "a: " << a.getX() << "b: " << b.getY() << "c: " << c.getX() << "point: "<< point.getY() << std::endl;
    std::cout << "AreaA: " << AreaA << "AreaA: " << AreaB << "AreaA: " << AreaC << "AreaA: " << AreaP << std::endl;
    if (AreaA == AreaB + AreaC + AreaP)
        return ( true );
    return ( false );
}