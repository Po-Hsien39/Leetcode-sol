var maxOperations = function (nums, k) {
  let keysMap = {};
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    let target = nums[i];
    if (keysMap.hasOwnProperty(target) && keysMap[target] > 0) {
      keysMap[target] -= 1;
      sum++;
    } else {
      if (keysMap.hasOwnProperty(k - target)) keysMap[k - target] += 1;
      else keysMap[k - target] = 1;
    }
  }
  return sum;
};
