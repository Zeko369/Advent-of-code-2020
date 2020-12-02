const { join } = require("path");
const getLines = require("../common/input");

(async () => {
  /**
   * @type {string[][]}
   */
  const input = await getLines(join(__dirname, "input.txt"), {
    mapperFunction: (row) => row.split(" "),
  });

  // ENTER CODE HERE

  let globalCount = 0;

  for (let i = 0; i < input.length; i++) {
    const [count, letter, password] = input[i];
    const a = letter[0];

    let tmp = 0;
    for (let j = 0; j < password.length; j++) {
      if (a === password[j]) {
        tmp++;
      }
    }

    const [from, to] = count.split("-").map((a) => parseInt(a));

    if (from <= tmp && to >= tmp) {
      globalCount++;
    }
  }

  console.log(globalCount);

  globalCount = 0;
  for (let i = 0; i < input.length; i++) {
    const [count, letter, password] = input[i];
    const a = letter[0];

    const [from, to] = count.split("-").map((a) => parseInt(a) - 1);

    let tmp = 0;
    if (a === password[from]) tmp++;
    if (a === password[to]) tmp++;

    if (tmp === 1) {
      globalCount++;
    }
  }

  console.log(globalCount);
})();
