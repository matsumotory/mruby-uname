# mruby-uname   [![Build Status](https://travis-ci.org/matsumoto-r/mruby-uname.png?branch=master)](https://travis-ci.org/matsumoto-r/mruby-uname)
Uname class, system uname bindings
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :git => 'https://github.com/matsumoto-r/mruby-uname.git'
end
```
## example
```ruby
$ ./bin/mirb
mirb - Embeddable Interactive Ruby Shell

> u = Uname.new
 => #<Uname:0xa47c90>
> u.sysname
 => "Linux"
```

## License
under the MIT License:
- see LICENSE file
