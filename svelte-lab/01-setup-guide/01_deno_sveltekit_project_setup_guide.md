# Deno SvelteKit Project Setup Guide
_______________________________________________________________________________

## `Intial Project Setup`
_______________________________________________________________________________

Create the project directory

```bash
mkdir deno-sveltekit-project
```
_______________________________________________________________________________

Enter the project directory

```bash
cd deno-sveltekit-project
```

Note: For the rest of this guide, 
run all commands from the `deno-sveltekit-project` directory.
_______________________________________________________________________________

Create the project structure

```bash
deno x --reload sv create .
```

Note: `deno x` is the equivalent of the `npx` command in Node.js

The `--reload` flag ensures that Deno does not use a cached version of sv
cli and gets the latest version from npm.

_______________________________________________________________________________

You will see this prompt
```
Install npm:sv? [Y/n]
```

Type lowercase `y` and press `Enter` 

Note: The cli will convert it to captial Y

_______________________________________________________________________________

```
┌  Welcome to the Svelte CLI! (v0.16.2)
│
◆  Which template would you like?
│  ● SvelteKit minimal (barebones scaffolding for your new app)
│  ○ SvelteKit demo
│  ○ Svelte library
└
```

Use the arrow keys to select `SvelteKit minimal` and press `Enter`
_______________________________________________________________________________

```
◆  Add type checking with TypeScript?
│  ● Yes, using TypeScript syntax
│  ○ Yes, using JavaScript with JSDoc comments
│  ○ No
└
```

Use the arrow keys to select `Yes, using TypeScript syntax` and press `Enter`
_______________________________________________________________________________

```
◆  What would you like to add to your project? (use arrow keys / space bar)
│  ◻ prettier (formatter - https://prettier.io)
│  ◻ eslint
│  ◻ vitest
│  ◻ playwright
│  ◻ tailwindcss
│  ◻ sveltekit-adapter
│  ◻ drizzle
│  ◻ better-auth
│  ◻ mdsvex
│  ◻ paraglide
│  ◻ storybook
│  ◻ mcp
│  ◻ experimental
└
```

Use the `arrow keys` to navigate the menu, and the `space bar` to select
`tailwindcss`, the press the `Enter` key 
_______________________________________________________________________________

```
◆  Which plugins would you like to add?
│  ◻ typography (@tailwindcss/typography)
│  ◻ forms
└
```

Press the `Enter` key to proceed without selecting any options.
_______________________________________________________________________________

```
◆  Which package manager do you want to install dependencies with?
│  ○ None
│  ○ npm
│  ○ yarn
│  ○ pnpm
│  ○ bun
│  ● deno
└
```

Use the arrow keys to select `deno` and press `Enter`
_______________________________________________________________________________

To skip prompts next time, run:

```bash
deno run npm:sv@0.16.2 create \
    --template minimal \
    --types ts \
    --add \
        tailwindcss="plugins:none" \
    --install deno .
```
_______________________________________________________________________________

## `Project Customisation`
_______________________________________________________________________________

### Mise Setup

Use `mise` to ensure that the project is always using the latest 
version of Deno

```bash
mise use deno@latest
```
_______________________________________________________________________________

If you ever want to update the version of a tool used in your project,
you can just run `mise use tool@the_new_version_you_want`, or you can directly
edit the mise.toml file

After that, run this command to ensure that your changes have been applied:

```bash
mise install
```
_______________________________________________________________________________

### Creating a Deno configuration file

Create a `deno.json` file

```bash
touch deno.json
```
_______________________________________________________________________________

### Adding additonal dependencies 

Add the official Deno adapter for Svelte as a development dependency.

```bash
deno add -D @deno/svelte-adapter
```
_______________________________________________________________________________

### `.vscode`

Delete the `.vscode` directory

```bash
rm -rf .vscode
```
_______________________________________________________________________________

### `.gitignore`

Replace the contents of the `gitignore` file with this

```gitignore
# Build Output
.deno-deploy/
.svelte-kit/

# Project dependencies
node_modules/
```
_______________________________________________________________________________

### `README.md`

Clear the contents of the `README.md` file

```bash
truncate -s 0 README.md
```
_______________________________________________________________________________

### `deno.json`

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
	},
	"unstable": ["fmt-component"]
}
```

The point of `"unstable": ["fmt-component"]` is to enable Deno formatting
for .svelte files
_______________________________________________________________________________

### `mise.toml`

Add this to the end of the `mise.toml file`

```toml
[env]
BROWSER = "chromium"
```
_______________________________________________________________________________

### `package.json`

Open the package.json file and look for the `scripts` section
_______________________________________________________________________________

Change the `dev` script from...

```json
"dev": "vite dev",
```
_______________________________________________________________________________

...to this

```json
"dev": "vite dev --open --port 6969",
```
_______________________________________________________________________________

Change the `preview` script from...

```json
"preview": "vite preview",
```

_______________________________________________________________________________

...to this

```json
"preview": "vite preview --open --port 6969",
```
_______________________________________________________________________________

Add a comma to the end of the last script.
_______________________________________________________________________________

Then add these two scripts
```json
"clean": "rm -rf .deno-deploy .svelte-kit node_modules",
"setup": "deno task clean && deno install && deno task build"
```
_______________________________________________________________________________

Remove this line

```
"@sveltejs/adapter-auto": "^7.0.1",
```
_______________________________________________________________________________

### `vite.config.ts`

Remove this line
```typescript
import adapter from '@sveltejs/adapter-auto';
```

Add this line
```typescript
import adapter from "@deno/svelte-adapter";
```
_______________________________________________________________________________

Run this command to let SvelteKit know about the changes made 
to the `vite.config.ts` file

```bash
deno run prepare
```
_______________________________________________________________________________

### The `src/lib` directory

Clear the contents of the `src/lib/index.ts` file

```bash
truncate -s 0 src/lib/index.ts
```
_______________________________________________________________________________

Create a `src/lib/global.css` file

```bash
touch src/lib/global.css
```
_______________________________________________________________________________

Add this to the `src/lib/global.css` file

```css
@import "tailwindcss";
```
_______________________________________________________________________________

### The `src/routes` directory

Clear the contents of the `src/routes/+layout.svelte` file

```bash
truncate -s 0 src/routes/+layout.svelte
```
_______________________________________________________________________________

Add this to the `src/routes/+layout.svelte` file

```svelte
<script lang="ts">
  import "$lib/global.css"
	import favicon from "$lib/assets/favicon.svg";

	let { children } = $props();
</script>

<svelte:head><link rel="icon" href={favicon} /></svelte:head>
{@render children()}
```
_______________________________________________________________________________

Clear the contents of the `src/routes/+page.svelte` file

```bash
truncate -s 0 src/routes/+page.svelte
```
_______________________________________________________________________________

Add this to the `src/routes/+page.svelte` file

```svelte
<h1>Deno SvelteKit Project</h1>
```
_______________________________________________________________________________

Delete the `src/routes/layout.css` file

```bash
rm -rf src/routes/layout.css
```
_______________________________________________________________________________

Run this command to ensure that you project can be built successfully.

```bash
deno task build
```
_______________________________________________________________________________

To run the project, open a separate terminal and run this command.

```bash
deno task dev
```
_______________________________________________________________________________
