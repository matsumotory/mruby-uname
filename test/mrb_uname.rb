##
## Uname Test
##

assert("Uname#sysname") do
  assert_equal(false, Uname.sysname.nil?)
end

assert("Uname returns each field of uname(2) as a non-empty String") do
  [:sysname, :nodename, :release, :version, :machine].each do |name|
    value = Uname.__send__(name)
    assert_kind_of(String, value, "Uname.#{name}")
    assert_false(value.empty?, "Uname.#{name} is empty")
  end
end

# The first call keeps the result in a data object (the class variable
# @@uname); a later call reads it back from there.
assert("Uname answers a later call from the kept result") do
  first = [Uname.sysname, Uname.nodename, Uname.release, Uname.version, Uname.machine]
  second = [Uname.sysname, Uname.nodename, Uname.release, Uname.version, Uname.machine]
  assert_equal(first, second)
end
