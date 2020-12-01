const { readFile } = require("fs").promises;

module.exports = async (filename, config = {}) => {
  let lines = [];
  try {
    lines = (await readFile(filename, "utf-8")).split("\n");
    lines = lines.map((line) => line.trim());
  } catch (err) {
    throw new Error("no_file");
  }

  if (!config) {
    return lines;
  }

  const out = lines.map(config.mapperFunction);
  return out;
};
