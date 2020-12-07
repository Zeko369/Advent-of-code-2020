from sys import stdin, argv

LOOKING_FOR = 'shiny gold'


def main(lines):
  bags = dict()

  for line in lines:
    name, rest = line[0:-1].split('bags contain')
    name = name.strip()
    tmp_bags = rest.strip()[0:-1].split(", ")

    new_bags = []
    new_count = []

    if len(tmp_bags) > 1 or tmp_bags[0] != 'no other bags':
      for b in tmp_bags:
        tmp_count = int(b[0])
        tmp_name = ' '.join(b.split(' ')[1:-1])
        new_bags.append(tmp_name)
        new_count.append(tmp_count)

        if tmp_name not in bags.keys():
          bags[tmp_name] = []

    bags[name] = [new_bags, new_count]

  first(bags)
  second(bags)


def first(bags):
  bags_containing = set()
  for bag in bags.keys():
    if LOOKING_FOR in bags[bag][0]:
      bags_containing.add(bag)

  len_before = 0
  while(len_before != len(bags_containing)):
    len_before = len(bags_containing)

    new = set()
    for looking_for in bags_containing:
      for bag in bags.keys():
        if looking_for in bags[bag][0]:
          new.add(bag)

    for new_bag in new:
      bags_containing.add(new_bag)

  print("First: {0}".format(len(bags_containing)))


def second(bags):
  initial_bags = bags[LOOKING_FOR]
  count = 0

  tmp = []
  for i in range(0, len(initial_bags[0])):
    bag, c = initial_bags[0][i], initial_bags[1][i]
    count += c
    tmp.append(dig(bags, bag, c))

  while(len(tmp) > 0):
    out = [i for i in tmp]
    tmp = []

    for i in out:
      for k in i:
        b, c = k
        o = dig(bags, b, c)

        count += c

        if len(o) > 0:
          tmp.append(o)

  print("Second {0}".format(count))


def dig(bags, bag, count):
  out = []
  for i in range(len(bags[bag][0])):
    color, tmp_count = bags[bag][0][i], bags[bag][1][i]
    out.append([color, tmp_count * count])

  return out


if __name__ == '__main__':
  filename = 'input.txt'
  if len(argv) > 1:
    if argv[1] == '2':
      filename = 'demo2.txt'
    else:
      filename = 'demo.txt'

  with open(filename) as f:
    lines = f.readlines()
    main(lines)
