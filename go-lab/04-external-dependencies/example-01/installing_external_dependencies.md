go get github.com/pborman/uuid

_______________________________________________________________________________

Ensures that the project has the right dependencies installed.

go mod tidy

_______________________________________________________________________________

go.mod

```gomod
// This is the module declaration
// The synatax is `module globally-unique-identifier`
// For a real project, this would be something like:
// module github.com/dezlymacauley/project-name
module example-01

// This specifies the version of Go used by the module
go 1.26.4

require github.com/pborman/uuid v1.2.1

require github.com/google/uuid v1.0.0 // indirect
```
_______________________________________________________________________________



_______________________________________________________________________________
