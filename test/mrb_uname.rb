##
## Uname Test
##

assert("Uname#sysname") do
  uname = Uname.new
  assert_equal(false, uname.sysname.nil?)
end
