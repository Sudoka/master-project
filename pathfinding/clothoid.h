#ifndef __CLOTHOID_H__
#define __CLOTHOID_H__

#include <vector>

#include "vec2.h"

struct connector_t
{
    vec2d T, //tangent vector
          p; //position

    connector_t(vec2d _p, vec2d _T)
    {
        p = _p; 
        T = _T;
    }

    connector_t()
    {
    }
};

class ClothoidPair
{
public:
    double length, 
           a0, a1, //Scaling factors
           alpha0, alpha1, //Angle of starting tangent
           t0, t1, //Curve limits
           g_diff; //Difference between the actual g, and the limited g (g_diff = length of beginning straight line segment)

    connector_t p0, p1;  // Point at the end of "g" and "h" respectively, with normal
    bool flip0, reverse; //reverse indicates that the clothoids in the pair is switched
    bool straight_line;  //true if the points p0, v and p1 are colinear

    vec2d lookup(double t); //Lookup a value in the clothoid pair
};

class ClothoidSpline
{
private:
    std::vector<connector_t> connectors;
    std::vector<vec2d> controlPoints;
    std::vector<double> lengths;          // Accumulated curve length at each clothoid pair's starting point

    void construct(std::vector<vec2d> controlPoints, double tau);

public:
    std::vector<ClothoidPair> clothoidPairs;
    ClothoidSpline(std::vector<vec2d> controlPoints);

    vec2d lookup(double t);
    double length();
};

#endif
