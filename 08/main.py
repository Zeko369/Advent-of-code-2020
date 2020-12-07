from sys import stdin, argv


def main(lines):
  for line in lines:
    print(line[0:-1])


if __name__ == '__main__':
  filename = 'input.txt'
  if len(argv) > 1:
    filename = 'demo.txt'

  with open(filename) as f:
    lines = f.readlines()
    main(lines)
