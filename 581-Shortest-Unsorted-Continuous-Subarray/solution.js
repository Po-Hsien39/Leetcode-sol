var findUnsortedSubarray = function (nums) {
  let start = -1;
  let end = -1;
  let currentMax = -Infinity;
  let currentMin = Infinity;
  for (let i = 0; i < nums.length; i++) {
    let target1 = nums[i];
    if (target1 >= currentMax) currentMax = target1;
    else end = i;

    let target2 = nums[nums.length - 1 - i];
    if (target2 <= currentMin) currentMin = target2;
    else start = nums.length - 1 - i;
  }
  if (start !== end) return end - start + 1;
  else return 0;
};
