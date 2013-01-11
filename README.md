## Overview

### Manager

- start/stop/restart processes
- send signal to processes (e.g. SIGINT)
- set/get environment variables
- set port numbers

### Supervisor

- restart process on crash
- throttle restart if process is thrashing
- log exit codes

### Monitor

- collect `STDOUT` and `STDERR` for each process

## Design

Process Hierarchy

    init
        -> Application Container (uid root)
            -> application processes (uid application)
            -> Web Server (uid www)

The app container, started as root, spawns the user application processes and a public web server.
The app container communicates with the web server via a pipe.

### Application Container

The app container starts and monitors child processes specified in the applications `Procfile`.

- applications that exit are restarted, regardless of their exit code.
- applications have a minimum uptime of 5 seconds, otherwise they are considered thrashing
- thrashing applications are delayed by 2^n seconds, where n is the number of consecutive failures
- each restart is logged and available via web server stats

### Web Server

#### Routes

In the following routes, the value `all` may be substituted for `:type` or `:name` as a wildcard.

    # Process Control
    POST   /proc/:type                     <-- start a new process (incrementally named)
    PUT    /proc/:type/:name               <-- start a new process (specific name)
    DELETE /proc/:type/:name               <-- stop a process
    POST   /proc/:type/:name/:signal       <-- send interrupt signal to process
    
    # Process Stats
    GET    /proc                           <-- list all process types
    GET    /proc/:type                     <-- list all process names matching :type
    GET    /proc/:type/:name               <-- get all stats for process
    
    # Logging
    GET    /proc/:type/:name/stdout        <-- get process stdout
    GET    /proc/:type/:name/stderr        <-- get process stderr
    GET    /proc/:type/:name/stdout+stderr <-- get process combined output
    
    # Environment Variables
    GET    /env/:key                       <-- get an environment variable
    PUT    /env/:key                       <-- set an environment variable
    DELETE /env/:key                       <-- delete an environment variable

A few notes about the routes:

- when starting a process, pass the desired port number in the body of the request
    - use `Content-Type: text/plain`
- pass in an `Accept` header to get formatted output
    - e.g. `Accept: application/json`
- methods return _after_ the action has been carried out
    - e.g. process started
- issuing a `PUT /proc/:type/:name` to an existing process restarts it
- environment variables are shared amongst _all_ processes
- signals are of type `sigint` or `SIGHUP`, case invariant
- can download partial logs with HTTP `Range` header with `lines` token
    - e.g. `Range: lines=100-200` for lines 100 to 200
    - or `Range: lines=100-` for all lines from 100 onward







