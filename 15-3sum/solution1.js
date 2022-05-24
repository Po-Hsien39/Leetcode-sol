// Time Complexity: Theta(n^2)

var threeSum = function (nums) {
  nums.sort((a, b) => a - b);
  let finals = [];
  let prevTarget = null;
  for (let i = 0; i < nums.length; i++) {
    let target = nums[i] * -1;
    if (prevTarget !== target) {
      let haveSeen = {};
      for (let j = i + 1; j < nums.length; j++) {
        let currentTarget = target - nums[j];
        // If the number has been checked...Don't check again
        if (
          !haveSeen.hasOwnProperty(nums[j]) ||
          (haveSeen.hasOwnProperty(nums[j]) && !haveSeen[nums[j]])
        ) {
          if (
            haveSeen.hasOwnProperty(currentTarget) &&
            !haveSeen[currentTarget]
          ) {
            finals.push([nums[i], currentTarget, nums[j]]);
            haveSeen[currentTarget] = true;
          } else {
            haveSeen[nums[j]] = false;
          }
        }
      }
      prevTarget = target;
    }
  }
  return finals;
};
