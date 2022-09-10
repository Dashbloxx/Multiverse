log = require("scripts/logger")

function main()
	--[[
		Anything inside this function is executed at the
		start of the game.
	]]--
	log.debug("main() called")
end

function render()
	--[[
		Anything inside this function is executed for each
		frame...
		Trying not to use any loggers inside this function as
		it could really lower the execution speed of the game.
	]]--
	draw_cube(1, 1, 1, 255, 255, 255)
	draw_cube(1, 2, 1, 255, 0, 255)
end
