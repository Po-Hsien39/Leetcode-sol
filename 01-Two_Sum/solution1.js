// Time Complexity: O(n)

var twoSum = function (nums, target) {
  let haveSeen = {};
  for (let i = 0; i < nums.length; i++) {
    let currTarget = target - nums[i];
    if (haveSeen.hasOwnProperty(currTarget)) {
      return [haveSeen[currTarget], i];
    } else {
      haveSeen[nums[i]] = i;
    }
  }
};
