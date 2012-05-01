--[[------------------------------------------------------

  dummy bindings generator
  ------------------------

  This uses the 'dub' tool and Doxygen to generate the
  bindings for dummy.

  Input:  headers in 'include/dummy'
  Output: cpp files in 'src'

  Look at mimas/bind.lua for a more complex example.

--]]------------------------------------------------------
require 'lubyk'

local base = lk.directory(lk.scriptPath())

local ins = dub.Inspector {
  INPUT    = {
    base .. '/include/dummy',
  },
}

local binder = dub.LuaBinder()

----------------------------------------------------------------
-- bind
----------------------------------------------------------------

binder:bind(ins, {
  output_directory = base .. '/src',
  -- Remove this part in included headers
  header_base = base .. '/include',
  -- Create a single library.
  single_lib = 'dummy',
  -- Open the library with require 'dummy.core' (not require 'dummy')
  luaopen    = 'dummy_core',
})
