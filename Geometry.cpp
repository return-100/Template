/*** Point Structure ***/

class point    
{
public:
    int x, y;
    
    /*** Use for Polar Sort ***/
  
    bool operator < (point b) 
    {
        if (y != b.y)
            return y < b.y;
      
        return x < b.x;
    }
  
    /*** Use for Montone Chain ***/
  
    bool operator < (point a, point b)
    {
        return (a.x < b.x || (a.x == b.x && a.y < b.y));
    }
};


double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
long long area(point a, point b, point c)
{
    return (a.x - b.x) * (b.y - c.y) - (a.y - b.y) * (b.x - c.x);
}

/*** Montone Chain Method for finding Convex Hull ***/
 
void convexHull()
{
    sort(arr, arr + n);
 
    for (int i = 0; i < n; ++i)
    {
        while (idx > 1 && area(cvx[idx - 2], cvx[idx - 1], arr[i]) <= 0)
            --idx;
 
        cvx[idx++] = arr[i];
    }
 
    int var = idx;
 
    for (int i = n - 2; i >= 0; --i)
    {
        while (idx > var && area(cvx[idx - 2], cvx[idx - 1], arr[i]) <= 0)
            --idx;
 
        cvx[idx++] = arr[i];
    }
}

