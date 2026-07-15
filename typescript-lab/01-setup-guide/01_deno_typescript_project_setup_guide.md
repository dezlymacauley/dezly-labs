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
touch deno.json
touch main.ts
```
_______________________________________________________________________________

Add this to the `deno.json` file

```json
{
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

Add this to the `main.ts` file

```typescript
console.log("\nDeno TypeScript Project\n");
```
_______________________________________________________________________________

To run the program, use this command

```bash
deno run main.ts 
```
_______________________________________________________________________________
