# Deno Express API
_______________________________________________________________________________

Project dependencies

```bash
deno install --save-exact express
```
_______________________________________________________________________________

Development dependencies

```bash
deno install --save-exact --dev @types/express
```
_______________________________________________________________________________

Update the `dev` task in the `deno.json` file

```json
{
  "tasks": {
    "dev": "deno --allow-env --allow-net src/main.ts"
  },
	"fmt": {
		"lineWidth": 80,
		"proseWrap": "always",
		"useTabs": false,
		"indentWidth": 2,
		"semiColons": true,
		"singleQuote": false
	}
}
```
_______________________________________________________________________________

To start the server

```bash
deno task dev
```
_______________________________________________________________________________

To send a GET request with hurl, use this command

```bash
echo "GET http://localhost:3000/" | hurl
```
_______________________________________________________________________________
