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
	draw_cube(-2, 1, 1, 255, 255, 255)
	draw_cube(2, 1, 1, 255, 0, 255)
	draw_cube(-3, 1, 1, 0, 255, 0)
	draw_cube(3, 1, 1, 255, 255, 0)
	draw_sphere(0, 3, 0, 255, 255, 255, 1, 20, 20)
	draw_triangle(0, 255, 0, 0, 0, 0, 0, 255, 0, 10, 10, 10, 0, 255, 0, 30, -30, 30)
end
