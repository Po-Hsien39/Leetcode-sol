// Time Complexity: O(n^2)

var threeSum = function (nums) {
  nums.sort((a, b) => a - b);
  let finals = [];
  for (let i = 0; i < nums.length; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    let target = nums[i] * -1;
    let left = i + 1;
    let right = nums.length - 1;
    while (left < right) {
      if (left > i + 1 && nums[left] === nums[left - 1]) {
        left++;
        continue;
      } else if (right < nums.length - 1 && nums[right] === nums[right + 1]) {
        right--;
        continue;
      }
      let sum = nums[left] + nums[right];
      if (sum < target) {
        left++;
      } else if (sum === target) {
        finals.push([nums[i], nums[left], nums[right]]);
        left++;
        right--;
      } else {
        right--;
      }
    }
  }
  return finals;
};
