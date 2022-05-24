var removeDuplicates = function (s, k) {
  let stack = [{ next: 0, prev: null }];
  let prev;
  for (let i = 0; i < s.length; i++) {
    let target = s[i];
    if (prev === target) {
      stack[stack.length - 1].count += 1;
    } else {
      stack[stack.length - 1].next = stack.length;
      stack.push({
        key: target,
        count: 1,
        next: null,
        prev: stack.length - 1,
      });
    }
    prev = target;
  }
  for (let i = 1; i < stack.length; i++) {
    if (stack[i].count >= k) {
      stack[i].count = stack[i].count % k;
    }
    let previous = stack[i].prev;
    let next = stack[i].next;
    if (stack[i].count === 0 && next) {
      if (stack[previous].key === stack[next].key) {
        stack[next].count += stack[previous].count;
        stack[next].prev = stack[previous].prev;
        stack[stack[previous].prev].next = next;
      } else {
        stack[previous].next = next;
        stack[next].prev = previous;
      }
    }
  }
  let index = stack[0].next;
  let result = '';
  while (index) {
    let target = stack[index];
    result += target.key.repeat(target.count);
    index = stack[index].next;
  }
  return result;
};
