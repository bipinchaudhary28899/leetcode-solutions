/**
 * @param {string|number|boolean} val
 * @return {Object}
 */
var expect = function (val) {
  return {
    toBe: function (n) {
      if (n === val) return true;
      throw new Error("Not Equal");
    },
    notToBe: function (n) {
      if (n !== val) return true;
      throw new Error("Equal");
    }
  };
};
