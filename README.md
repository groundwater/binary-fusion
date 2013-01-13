# BinaryFusion

>  Robust Application Development, and Distribution

BinaryFusion fuses application with virtual machine images to create 
isolated, robust, and reliable machine images that can be used both in 
development and production.

![Binary Fusion Overview](https://raw.github.com/jacobgroundwater/binary-fusion/assets/Export/Overview.png)

## Product Vision

_Problems in traditional application deployment_

- in-place applications updates are risky
- os updates are difficult without disrupting a running application
- application rollbacks are difficult

_Problems with Platform as a Services_

- prohibitive to create private clouds
- applications updates can still break a working deployment
- limited regions per provider

_Opportunities with cloud computing_

- cloud computing makes deploying a brand-new application fast, easy, and cheap
- virtual machine images can be re-created each update
    - os is always up to date
- can replace the entire working stack each update, no risky deployments
    - the new stack can be tested before live deployment
    - live migration step only involves re-pointing a load balancer
    - rollback is easy

**We need good tools that take this approach!**

1. a good tool should provision and create an AMI with one command
2. a good tool should provide good default builds
3. a good tool should make deployment fun

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
- [Homebrew](http://mxcl.github.com/homebrew/)
