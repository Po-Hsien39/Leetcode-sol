var combine = function (n, k) {
  const result = [];
  getCombinations(1, [], result, n, k);
  return result;
};

const getCombinations = (target, currentCombination, result, n, k) => {
  if (currentCombination.length === k)
    return result.push([...currentCombination]);
  currentCombination.push(target);
  getCombinations(target + 1, currentCombination, result, n, k);
  currentCombination.pop();
  if (currentCombination.length + n - target >= k)
    getCombinations(target + 1, currentCombination, result, n, k);
};
