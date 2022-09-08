print("Hi")
print("I don't know what to say here...")


local x = 0

function render()
	--[[
		Anything inside this function is executed for each
		frame...
	]]--
	x = x + 1
	print(x)
end
