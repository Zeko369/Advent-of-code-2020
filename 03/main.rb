# frozen_string_literal: true

lines = File.open('./input.txt').map(&:strip).map do |line|
  line
end

lines.each_with_index do |line, index|
  p line, index
end
