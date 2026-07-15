# Deno TypeScript Project Setup Guide
_______________________________________________________________________________

First create the project directory

```bash
mkdir deno-typescript-project 
```
_______________________________________________________________________________

Enter the project directory

```bash
cd deno-typescript-project
```
_______________________________________________________________________________

Create the project structure

```bash
touch .gitignore
touch deno.json
touch package.json

mkdir src/
touch src/main.ts
```
_______________________________________________________________________________

Add this to the `.gitignore` file

```gitignore
# Project dependencies
node_modules/
```
_______________________________________________________________________________

Add this to the `deno.json` file

```json
{
  "tasks": {
    "dev": "deno src/main.ts"
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

Add this to the `src/main.ts` file

```typescript
console.log("\nDeno TypeScript Project\n");
```
_______________________________________________________________________________

Add this to the `package.json` file

```json
{
  "name": "deno-typescript-project",
  "version": "1.0.0",
  "type": "module"
}
```
_______________________________________________________________________________

To run the program, use this command

```bash
deno task dev
```
_______________________________________________________________________________
