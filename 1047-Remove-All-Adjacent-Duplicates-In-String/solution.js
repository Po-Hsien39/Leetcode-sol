var removeDuplicates = function (s) {
  let result = '';
  for (let i = 0; i < s.length; i++) {
    let target = s[i];
    if (result[result.length - 1] === target) {
      result = result.slice(0, result.length - 1);
    } else {
      result += target;
    }
  }
  return result;
};
