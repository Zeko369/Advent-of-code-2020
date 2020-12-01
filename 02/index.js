const { join } = require("path");
const getLines = require("../common/input");

(async () => {
  /**
   * @type {any[]}
   */
  const input = await getLines(join(__dirname, "input.txt"), {
    mapperFunction: (row) => parseInt(row),
  });

  // ENTER CODE HERE
})();
