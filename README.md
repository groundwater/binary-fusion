# BinaryFusion

>  Robust Application Development, and Distribution

BinaryFusion fuses application with virtual machine images to create 
isolated, robust, and reliable machine images that can be used both in 
development and production.

![Binary Fusion Overview](https://raw.github.com/jacobgroundwater/binary-fusion/assets/Export/Overview.png)


## Product Vision

_Problems in traditional physical (or p2v) application deployment_

- in-place applications updates are risky
- os updates are difficult without disrupting a running application 
- application rollbacks are difficult 

_Problems with Platform as a Services_

- Paas frameworks will always lag behind Iaas innovations.
- Iaas providers will likely evolve and make many generic Paas a paasing fad.
- prohibitive (availablibity, expense) to create private clouds 
- applications updates can still break a working deployment 
- limited regions per provider [dg: is this AWS vs PAAS argument?]

_Construct Hierarchy_

- Deployment script (e.g. CloudFront)
- Stack script (e.g. Elastic Beanstalk)
- Instance script (e.g. BinFusion)
- Instance preparation script (e.g. Puppet, Chef)

_Opportunities with cloud computing_

- cloud computing makes deploying a brand-new application fast, easy, and cheap
- virtual machine images can be re-created each update
    - os is always up to date
- can replace the entire working stack each update, no risky deployments
    - the new stack can be tested before live deployment
    - live migration step only involves re-pointing a load balancer
    - rollback is easy

_Testing Considerations_

- How is a/b testing done
- Staging and Test use different AWS credentials
- high scale of continuous deployment (10 to 50 per day)

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
- [BundlingAMI blog] (http://www.vim-fu.com/bundling-versioned-amis-rapidly-in-amazons-ec2/)
- [EC2 API Reference] (http://docs.amazonwebservices.com/AWSEC2/latest/APIReference/query-apis.html)
