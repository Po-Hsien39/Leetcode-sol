var removeDuplicates = function (s) {
  let sArr = [...s];
  let result = [];
  for (let i = 0; i < sArr.length; i++) {
    let target = sArr[i];
    if (result[result.length - 1] === target) {
      result.pop();
    } else {
      result.push(target);
    }
  }
  return result.join('');
};
