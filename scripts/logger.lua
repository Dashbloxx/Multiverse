local log = {}

function log.info(message)
    print("info: " .. message)
end

function log.debug(message)
    print("debug: " .. message)
end

function log.warn(message)
    print("warn: " .. message)
end

function log.error(message)
    print("error: " .. message)
end

return log