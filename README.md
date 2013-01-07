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

BinaryFusion requires a base Ubuntu image that will be downloaded during initialization.

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

### Init

Initialize an existing application as a BinaryFusion project.

- BinaryFusion will attempt to guess your project type

### Create

Running the BinaryFusion `create` command will generate a **fused image**
between the current repository branch and your base machine.

### Test

All images should be tested after creation.
BinaryFusion provides a number of base tests that can be overridden and extended.

### Spawn

Spawning a fused image runs it in the local service network.

### Publish

Push the image to an imaging server for production.

## Inspirations and References

- [Pow](http://pow.cx/)
- [Awesome Command Line Apps](http://www.awesomecommandlineapps.com/)
- [Airbnb: Tech Talk - Ben Hindman](https://www.youtube.com/watch?v=Hal00g8o1iY)
