# frozen_string_literal: true

class Day04
  def initialize(demo = false)
    if demo
      @lines = File.open(__dir__ + '/demo.txt').map(&:strip)
    else
      @lines = File.open(__dir__ + '/input.txt').map(&:strip)
    end
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