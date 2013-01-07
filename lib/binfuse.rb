require 'binfuse/version.rb'

# Add requires for other files you add to your project here, so
# you just need to require this one file in your bin file

module Console
  
  INFO = Paint['[Info] ',:green]
  DONE = Paint['[Done] ',:blue]
  
  def self.Indent(value)
    return "       "
  end
  
end