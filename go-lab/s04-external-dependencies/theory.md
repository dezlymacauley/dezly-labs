repositories, modules, and packages

repository = Where the source code of a project is stored.

A module = The root of a Go library or application.
A module contains on one or more packages.

Each Go project is declared as a module.

Every module has a globally unique identifier.

E.g. 
github.com/dezlymacauley/dezly-labs

This is a path that allow the module to be downloaded by go tools

It is possible to store more than one module in a repository 
but this is discouraged because a module has to have a version.

So having more than one module in a repository would mean tracking separate
versions for two different projects in a single repository.
_______________________________________________________________________________

go.mod

This file declares the version of Go used in the project directory,
and any additional modules (external packages) that the project needs 
in order to function.

_______________________________________________________________________________
