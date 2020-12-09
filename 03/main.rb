# frozen_string_literal: true

lines = File.open(__dir__ + '/input.txt').map(&:strip)

def run(d, r, lines)
  trees = 0
  pos = r

  lines.each_with_index do |line, index|
    if d == 1
      next if index.zero?
    elsif d == 2
      next if index.odd? || index.zero?
    end

    line += line while pos + r > line.size

    trees += 1 if line[pos] == '#'
    pos += r
  end

  trees
end

puts run(1, 3, lines)

down = [1, 1, 1, 1, 2]
right = [1, 3, 5, 7, 1]

out = (0..4).map do |type|
  d = down[type]
  r = right[type]

  run(d, r, lines)
end

tmp = nil
out.each do |a|
  if tmp.nil?
    tmp = a
  else
    tmp *= a
  end
end

puts tmp
