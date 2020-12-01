const { readFile } = require("fs").promises;

/**
 * getLines function used to read from input file
 * @param {string} filename
 * @param {{mapperFunction: (data: string, index: number) => any}} [config] Config object
 */
module.exports = async (filename, config) => {
  let lines = [];
  try {
    lines = (await readFile(filename, "utf-8")).split("\n");
    lines = lines.map((line) => line.trim()).filter(Boolean);
  } catch (err) {
    throw new Error("no_file");
  }

  if (!config) {
    return lines;
  }

  const out = lines.map(config.mapperFunction);
  return out;
};
