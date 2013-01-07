# BinaryFusion

>  Robust Application Development, and Distribution

BinaryFusion fuses application with virtual machine images to create 
isolated, robust, and reliable machine images that can be used both in 
development and production.

## Installation

    $ gem install binfuse
    $ cd my/project
    $ binfuse init

## Usage

    SYNOPSIS
        binfuse [global options] command [command options] [arguments...]

    GLOBAL OPTIONS
        --version                               - 

    COMMANDS
        init    - Initialize a new Buildfile
        create  - Fuse a new image from the current Buildfile
        test    - Test a fused image
        spawn   - Attach and run a fused image
        publish - ready and send a fused image to Amazon Web Services

## Inspirations and References

- [Pow](http://pow.cx/)
- [Awesome Command Line Apps](http://www.awesomecommandlineapps.com/)
- [Airbnb: Tech Talk - Ben Hindman](https://www.youtube.com/watch?v=Hal00g8o1iY)
