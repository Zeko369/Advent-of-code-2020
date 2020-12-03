# frozen_string_literal: true

class Day04
  def initialize(demo = false)
    file = if ARGV.first == 'demo'
             '/demo.txt'
           else
             '/input.tx'
           end
    @lines = File.open(__dir__ + file).map(&:strip)
  end

  def first
    puts 'First'
  end

  def second
    puts 'Second'
  end

  private

  def run
    
  end
end

c = Day04.new(true)
c.first
c.second