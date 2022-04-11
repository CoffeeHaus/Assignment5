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
    /* TODO : Fill in you and your partner's names (or N/A if you worked individually) */
    printf("This solution was completed by:\n");
    printf("<student name #1>\n");
    printf("<student name #2 (if no partner write \"N/A\")>\n");
}

/* OPTIONAL HELPER FUNCTION
 * buildGraph
 *
 * IMPORTANT NOTE: This is an entirely optional helper function which is only called by student implemented functions.
 * Creates a new graph to represent the given maze.  
 */
Graph* buildGraph( array2D* maze /* and other parameters you find helpful */  )
{
    //OPTIONAL TODO: Translate the given maze into a graph.  'X' represents impassable locations.  Only moves of up, down, left, and right are allowed. 
    /* With the right parameters this can be used by all three functions below to build the graph representing their different maze problems. */
    /* HINT 1: To solve this, my solution used the functions createGraph and setEdge from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */

    return NULL; /* TODO: Replace with your graph representing maze */
}

/* hasPath
 * input: an array2D pointer to a maze
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph. 'X' marks impassable regions.
 */
pathResult hasPath( array2D *maze )
{
    //TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */

    return PATH_UNKNOWN; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}

/* findNearestFinish
 * input: an array2D pointer to a maze, a pointer to an int
 * output: pathResult
 *
 * The maze contains one 'S' and multiple 'F's (1 or more).  'X' marks impassable regions.
 * Find the length of the shortest path to any 'F' from 'S' and return it in spDist.
 * If no 'F' is reachable set spDist to INT_MAX.
 */
pathResult findNearestFinish( array2D *maze, int *spDist )
{
    //TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */
    
    
    (*spDist) = INT_MAX; /* TODO: This returns your shortest path distance to any 'F' from the 'S'.  Set it to INT_MAX if no path exists. */
    
    return PATH_UNKNOWN; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}

/* findTunnelRoute
 * input: an array2D pointer to a maze, an int representing the number X's you can travel through
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph where you pass through at most k 'X' symbols.
 */
pathResult findTunnelRoute( array2D *maze, int k )
{
    //TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */

    return PATH_UNKNOWN; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}
