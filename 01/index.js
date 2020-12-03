const { join } = require("path");
const getLines = require("../common/input");

(async () => {
  /**
   * @type {number[]}
   */
  const input = await getLines(join(__dirname, "input.txt"), {
    mapperFunction: (row) => parseInt(row),
  });

  let largest = -1;
  for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < input.length; j++) {
      if (i == j) {
        continue;
      }

      if (input[i] + input[j] === 2020) {
        const tmp = input[i] * input[j];
        if (tmp > largest) {
          largest = tmp;
        }
      }
    }
  }
  console.log(largest);
  for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < input.length; j++) {
      for (let k = 0; k < input.length; k++) {
        if (i == j || j == k || i == k) {
          continue;
        }

        if (input[i] + input[j] + input[k] === 2020) {
          const tmp = input[i] * input[j] * input[k];
          if (tmp > largest) {
            largest = tmp;
          }
        }
      }
    }
  }
  console.log(largest);
})();
