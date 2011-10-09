#!/usr/bin/ruby
# encoding=utf8
size=2
start=0
c=['Н', 'Н' ,'Н' ,'Н' ,'Н','Н','Н','Н','Н','Н','Н','Н','Н','Н']
code_dictionary=Array.new()
begin_size_code_dictionary=Array.new()
end_string=String.new()
code_dictionary=c.uniq.to_a
decode_dictionary=c.uniq.to_a
for i in 0...code_dictionary.size
	begin_size_code_dictionary[i]=i
end
c.size.times{
if !code_dictionary.include?(c[start,size].to_s)#Comparation
	code_dictionary.push(c[start,size].to_s.chomp)
	start=start+(code_dictionary.last.size)/2-1
	size=2
else 
	size+=1;
end
}
end_code=Array.new(code_dictionary.size)
for i in begin_size_code_dictionary.size...code_dictionary.size
	end_code[i]=code_dictionary.index(code_dictionary[i].chop.chop)+1
	end_string+=code_dictionary[i].chop.chop
end
if (c.size>(end_string.size)/2)
	end_code.push(code_dictionary.index(c.last)+1)
end
end_code=end_code.compact
puts code_dictionary
puts "Вхідна стрічка: "+c.join
puts "Вихідна стрічка: "+end_code.join
puts "Коефіцієнт стиснення= "+((c.size-end_code.size)*100/c.size).to_s+"%"
#Тут скінчилося кодування
end_decode = Array.new(end_code.size)
def ololo(end_code,decode_dictionary,end_decode)
	count=true
	end_code.each{|elem| 
	if elem <= decode_dictionary.size && count == true  
		end_decode[end_code.index(elem)]=decode_dictionary[elem-1]
	else
		count = false
	end
}
end
puts decode_dictionary.size
def ololo2(end_code,decode_dictionary,end_decode)
	if decode_dictionary.size == 1 
		decode_dictionary[1]=Array.new
		decode_dictionary[1].push(decode_dictionary[0])
		decode_dictionary[1].push(decode_dictionary[0])
		decode_dictionary[1]=decode_dictionary[1].join
	end	
	temp_array=end_decode.compact.to_s
	start =0
	size = 2
	temp_array.size.times{
	if !decode_dictionary.include?(temp_array[start,size*2])
		decode_dictionary.push(temp_array[start,size*2])
		start=start+decode_dictionary.last.size-2
		size=2
	else
		size+=1
	end }
end
count=true
ololo(end_code,decode_dictionary,end_decode)
ololo2(end_code,decode_dictionary,end_decode)
ololo(end_code,decode_dictionary,end_decode)
c4=end_decode.size
while end_decode.compact.size < end_decode.size && c4 > 0
ololo2(end_code,decode_dictionary,end_decode)
ololo(end_code,decode_dictionary,end_decode)
c4-=1
end
for i in 0...end_decode.size
	if end_decode[i] == nil
		end_decode[i]=decode_dictionary[end_code[i]-1]
	end
end
puts "Розкодована стрічка: "+end_decode.to_s
