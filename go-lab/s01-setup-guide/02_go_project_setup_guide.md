# Go project setup guide
_______________________________________________________________________________

Create the directory

```bash
mkdir go-project
```
_______________________________________________________________________________

Enter the directory

```bash
cd go-project
```
_______________________________________________________________________________

Use `mise` to set the latest version of Go in the project

```bash
mise use go@latest
```
_______________________________________________________________________________

mise.toml

```toml
[tools]
go = "latest"
```
_______________________________________________________________________________

The syntax is `go mod init module-path`

This would normally be the GitHub url of your project.

E.g. `go mod init github.com/dezlymacauley/repo-name`

For this example, I'm just doing to use the directory name

```bash
go mod init go-project
```

_______________________________________________________________________________

go.mod

```bash
module go-project

go 1.26.4
```
_______________________________________________________________________________
