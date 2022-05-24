// Time Complexity: O(n)

var addTwoNumbers = function (l1, l2) {
  let result = l1;
  let plusList = l2;
  let newValue;

  while (plusList || result) {
    if (!result) {
      newValue = plusList.val;
    } else if (!plusList) {
      newValue = result.val;
    } else {
      newValue = result.val + plusList.val;
    }

    if (newValue >= 10) {
      newValue -= 10;
      if (result.next) {
        result.next.val += 1;
      } else {
        result.next = new ListNode(1);
      }
    } else if (!result.next && plusList && plusList.next) {
      result.next = new ListNode(0);
    }
    result.val = newValue;

    if (result) result = result.next;
    if (plusList) plusList = plusList.next;
  }
  return l1;
};
