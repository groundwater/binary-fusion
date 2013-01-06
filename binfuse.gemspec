Gem::Specification.new do |s|
  
  s.name          = "binfuse"
  s.version       = "0.0.1"
  s.platform      = Gem::Platform::RUBY
  
  s.authors       = ["Jacob Groundwater"]
  s.email         = ["groundwater@gmail.com"]
  
  s.homepage      = "http://github.com/jacobgroundwater/binary-fusion"
  s.summary       = "A Rapid Application Development and Distribution Tool"
  s.description   = %q{Hi}
  
  s.rubyforge_project = "binary-fusion"
  
  s.files         = ["bin/binfuse.rb"]
  s.executables   = ["binfuse.rb"]
  
  # Dependencies
  s.add_dependency("gli")
  
end