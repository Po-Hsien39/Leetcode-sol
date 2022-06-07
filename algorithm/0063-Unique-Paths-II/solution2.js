var uniquePathsWithObstacles = function (obstacleGrid) {
  let routeTable = [];
  for (let i = 0; i < obstacleGrid.length; i++) {
    routeTable[i] = [];
    for (let j = 0; j < obstacleGrid[0].length; j++) {
      routeTable[i][j] = -1;
    }
  }
  routeTable[obstacleGrid.length - 1][obstacleGrid[0].length - 1] = 1;
  return getPaths(obstacleGrid, routeTable, 0, 0);
};

const getPaths = (obstacleGrid, routeTable, posX, posY) => {
  if (obstacleGrid[posX][posY] === 1) return 0;
  if (routeTable[posX][posY] !== -1) return routeTable[posX][posY];
  let routeFromBottom = 0;
  let routeFromRight = 0;
  if (posX < obstacleGrid.length - 1 && obstacleGrid[posX + 1][posY] !== 1)
    routeFromBottom = getPaths(obstacleGrid, routeTable, posX + 1, posY);
  if (posY < obstacleGrid[0].length - 1 && obstacleGrid[posX][posY + 1] !== 1)
    routeFromRight = getPaths(obstacleGrid, routeTable, posX, posY + 1);
  routeTable[posX][posY] = routeFromBottom + routeFromRight;
  return routeTable[posX][posY];
};
