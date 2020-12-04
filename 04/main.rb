# frozen_string_literal: true

class Day04
  @@fields = ["byr",  "iyr",  "eyr",  "hgt",  "hcl",  "ecl",  "pid",  "cid"]
  @@rules = {
    'byr': {len: 4, from: 1920, to: 2002},
    'iyr': {len: 4, from: 2010, to: 2020},
    'eyr': {len: 4, from: 2020, to: 2030},
    'hgt': [
      {ext: 'cm', from: 150, to: 193},
      {ext: 'in', from: 59, to: 76}
    ],
    'hcl': 'color',
    'ecl': ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'],
    'pid': {len: 9}
  }

  def initialize(demo = false)
    file = if ARGV.first == 'demo'
             '/demo.txt'
           else
             '/input.txt'
           end
    @lines = File.open(__dir__ + file).map(&:strip)
  end

  def first
    tmp = []
    count = 0

    @lines.each_with_index do |row, index|
      if(row == '' || index == @lines.size - 1)
        if index == @lines.size - 1
          tmp << row
        end

        tmp = tmp.flatten.map do |item|
          item.split(':').first
        end

        tmp << 'cid' unless tmp.include?('cid')

        if tmp.sort == @@fields.sort
          count += 1
        end


        tmp = []
      else
        tmp << row.split(' ')
      end
    end

    puts "First: #{count}"
  end

  def second
    tmp = []
    count = 0

    @lines.each_with_index do |row, index|
      if(row == '' || index == @lines.size - 1)
        if index == @lines.size - 1
          tmp << row.split(' ')
        end

        ok = true
        tmp = tmp.flatten.map do |item|
          key, value = item.split(':')
          rule = @@rules[key.to_sym]

          if key != 'cid'
            if rule.class.to_s == 'Array'
              if rule.first.class.to_s == 'String'
                unless rule.include?(value)
                  ok = false
                  break
                end
              else
                ok = false
                rule.each do |type|
                  if value.end_with?(type[:ext]) && value[0..-2].to_i <= type[:to] && type[:from] <= value[0..-2].to_i
                    ok = true
                    break
                  end
                end

                break unless ok
              end
            elsif rule === 'color'
              unless value.match(/\#[a-fA-F0-9]{6}/)
                ok = false
                break
              end
            else
              if value.size != rule[:len]
                ok = false
                break
              end

              if rule[:from] && rule[:to]
                v = value.to_i

                unless v <= rule[:to] && v >= rule[:from]
                  ok = false
                  break
                end
              end
            end
          end

          key
        end

        unless ok
          tmp = []
          next
        end

        tmp << 'cid' unless tmp.include?('cid')

        if tmp.sort == @@fields.sort
          count += 1
        end

        tmp = []
      else
        tmp << row.split(' ')
      end
    end

    puts "Second: #{count}"
  end

  private
end

c = Day04.new(true)
c.first
c.second