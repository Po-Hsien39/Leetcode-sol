var longestCommonPrefix = function (strs) {
  let commonStr = '';
  let sameValue = true;
  let index = 0;
  do {
    let compareKey = strs[0][index];
    if (!compareKey) {
      break;
    }
    for (let i = 1; i < strs.length; i++) {
      if (strs[i][index] !== compareKey || !strs[i][index]) {
        sameValue = false;
        break;
      }
    }
    if (sameValue) {
      index++;
      commonStr += compareKey;
    }
  } while (sameValue);
  return commonStr;
};
