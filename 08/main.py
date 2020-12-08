from sys import stdin, argv
from dataclasses import dataclass


@dataclass
class Code:
  command: str
  value: int

  def __init__(self, command, value=None):
    if value is None:
      if isinstance(command, Code):
        self.command = command.command
        self.value = command.value
      else:
        raise RuntimeError('Value is None, but first argument is not Code')
    else:
      self.command = command
      self.value = value


def main(lines):
  code = []

  for line in lines:
    command, amount = line[0:-1].split(' ')
    code.append(Code(command, int(amount)))

  ok, value = first(code)
  if ok:
    print("First: {}".format(value))
  else:
    print("First: error")

  second(code)


def first(code):
  done = []

  index = 0
  value = 0

  while True:
    if index in done:
      return True, value
    if index == len(code):
      return False, value

    done.append(index)
    inst = code[index]

    if inst.command == 'jmp':
      index += inst.value
    elif inst.command == 'acc':
      value += inst.value
      index += 1
    elif inst.command == 'nop':
      index += 1
    else:
      print("Cant find command {}".format(inst))


def second(code):
  value = set()

  for i in range(len(code)):
    if code[i].command not in ['nop', 'jmp']:
      continue

    tmp_code = [Code(j) for j in code]
    if tmp_code[i].command == 'nop':
      tmp_code[i].command = 'jmp'
    elif tmp_code[i].command == 'jmp':
      tmp_code[i].command = 'nop'

    tmp_ok, val = first(tmp_code)
    if not tmp_ok:
      value.add(val)

  print(value)


if __name__ == '__main__':
  filename = 'input.txt'
  if len(argv) > 1:
    filename = 'demo.txt'

  with open(filename) as f:
    lines = f.readlines()
    main(lines)
