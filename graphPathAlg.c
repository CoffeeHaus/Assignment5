#include "graph.h"
#include "graphPathAlg.h"


/* printNames
 * input: none
 * output: none
 *
 * Prints names of the students who worked on this solution
 */
void printNames( )
{
    printf("This solution was completed by:\n");
    printf("Samantha Murray\n");
    printf("Andrew Neumann\n");
}

/* OPTIONAL HELPER FUNCTION
 * buildGraph
 *
 * IMPORTANT NOTE: This is an entirely optional helper function which is only called by student implemented functions.
 * Creates a new graph to represent the given maze.
 */
Graph* buildGraph( array2D* maze, bool tunneling, Point2D * start, Point2D* finish)
{
    int x, yz, y, xz;
    int finCount = 0;
    int bits = floor(log2(maze->length * maze->width)) ;// finds how many bits are needed to store normal movements
    Point2D offset[4] = {
           {0, 1},  //right
           {0, -1}, //left
           {1, 0},  //down
           {-1, 0}}; //up

    Graph* g = createGraph(maze->length * maze->width);
    
    for (x = 0; x < maze->length; x++)
    {
        for (y = 0; y < maze->width; y++)
        {

            Point2D p = createPoint(x, y);

            if (maze->array2D[x][y] == 'S') { //if this point is S, save it in start
                *start = p;
            }
            else if (maze->array2D[x][y] == 'F') { //if the point is F, save it as one of the finishes
                finish[finCount++] = p;
            }

            // this loops through the 4 directions that the point will be touching
            for (int z = 0; z < 4; z++)
            {
                xz = x + offset[z].x;
                yz = y + offset[z].y;

                //checks for out of bounds
                if (xz < 0 || xz >= maze->length || yz < 0 || yz >= maze->width) {}
                
                else if (maze->array2D[xz][yz] != 'X') //check if next step is X
                { 
                    setEdge(g, p, createPoint(xz, yz), 1); //create an edge and a point

                }
                else if(tunneling && maze->array2D[xz][yz] == 'X')// If the point is a X then the movement will cost  1<< bits which makes it not interfer with count of normal movements
                {
                    setEdge(g, p, createPoint(xz, yz), 1 << bits); 
                }
                
            }

        }
    }

    return g; 
}

/* hasPath
 * input: an array2D pointer to a maze
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph. 'X' marks impassable regions.
 */
pathResult hasPath(array2D* maze)
{
    Point2D start;
    Point2D finish;

    Graph* g = buildGraph(maze, false, &start, &finish);
    dijkstrasAlg(g, start);
    int distance = getDistance(g, start, finish);
    freeGraph(g);

    if (distance != INT_MAX)
    {
        return PATH_FOUND;
    }
    else
    {
        return PATH_IMPOSSIBLE;
    }
}

/* findNearestFinish
 * input: an array2D pointer to a maze, a pointer to an int
 * output: pathResult
 *
 * The maze contains one 'S' and multiple 'F's (1 or more).  'X' marks impassable regions.
 * Find the length of the shortest path to any 'F' from 'S' and return it in spDist.
 * If no 'F' is reachable set spDist to INT_MAX.
 */
pathResult findNearestFinish(array2D* maze, int* spDist)
{
    Point2D start;
    Point2D finish[20];
    (*spDist) = INT_MAX;
    int distance = 0;
    Graph* g = buildGraph(maze, false, &start, &finish);

    dijkstrasAlg(g, start);

    // run through each finish
    for (int x = 0; x < 20; x++)
    {
        if (finish[x].x < 0)break;// since 'finish' are structs, they dont have null, so this checks for the end of array
        distance = getDistance(g, start, finish[x]);

        // checks to see if distance is lower
        if (distance < (*spDist) && distance > 0)
        {
            (*spDist) = distance;
        }
    }

    freeGraph(g);

    if ((*spDist) != INT_MAX)
    {
        return PATH_FOUND;
    }
    else
    {
        return PATH_IMPOSSIBLE;
    }

}

/* findTunnelRoute
 * input: an array2D pointer to a maze, an int representing the number X's you can travel through
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph where you pass through at most k 'X' symbols.
 */
pathResult findTunnelRoute(array2D* maze, int k)
{
    //The distance between any point and a 'X' point is the maze->length * maze->width, which means that if the tunnel has to travel through at least 5 blocks
    // It will have a distance of 5*size + 1-size, because there can not be more moves than there are vertices.
    //effectivly this is using the same int to carry two different pieces of information, akin to IP subnetting.
    Point2D start;
    Point2D finish;
    int bits = floor(log2(maze->length * maze->width)) ;

    Graph* g = buildGraph(maze, true, &start, &finish);
    dijkstrasAlg(g, start);

    int distance = getDistance(g, start, finish);
    freeGraph(g);
    
    //This doesn't have any importance to the program,
    //this gives me the number of steps that are not wall, but clearing the steps and subtracting the difference.
    int numOfNonWallSteps = distance - ((distance >> bits)<< bits);

    if (distance >> bits  <= k)
    {
        return PATH_FOUND;
    }
    else
    {
        return PATH_IMPOSSIBLE;
    }

}
