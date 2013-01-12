# BinaryFusion

>  Robust Application Development, and Distribution

BinaryFusion fuses application with virtual machine images to create 
isolated, robust, and reliable machine images that can be used both in 
development and production.

![Binary Fusion Overview](https://raw.github.com/jacobgroundwater/binary-fusion/assets/Export/Overview.png)

## Product Vision

**TODO** 

- list problems with existing deployment methods
    - problems with PaaS
    - problems with non VMs
- state a clear goal in one statement
- list ways to achieve that goal

## Installation

BinaryFusion is a Ruby application that can be installed via Ruby gems.

    $ gem install binfuse
    $ cd my/project
    $ binfuse init

The `init` command will ask you for your AWS credentials,
and what kind of project you are running.

## Usage

1. Create a project that contains a `Procfile`
2. Build an image with `binfuse create`
3. Done!

After an new image has been _fused_ it is ready to be attached and run in AWS.

## Inspirations and References

- [Pow](http://pow.cx/)
- [Awesome Command Line Apps](http://www.awesomecommandlineapps.com/)
- [Airbnb: Tech Talk - Ben Hindman](https://www.youtube.com/watch?v=Hal00g8o1iY)
