var lengthOfLongestSubstring = function (s) {
  let haveSeen = {};
  let longest = 0;
  let current = 0;
  let prev = 0;
  for (let i = 0; i < s.length; i++) {
    let target = s[i];
    if (haveSeen.hasOwnProperty(target) && haveSeen[target] >= prev) {
      prev = haveSeen[target];
      current = i - haveSeen[target];
      haveSeen[target] = i;
    } else {
      current++;
      if (current > longest) longest = current;
      haveSeen[target] = i;
    }
  }
  return longest;
};
