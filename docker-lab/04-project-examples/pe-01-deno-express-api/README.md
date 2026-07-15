# Deno Express API
_______________________________________________________________________________

## Setup Guide

Install the project dependencies

```bash
deno install
```
_______________________________________________________________________________

Open the project directory in a separate terminal and run this command 
to start the server

```bash
deno task dev
```
_______________________________________________________________________________

## API Testing with Hurl

Open the project directory in a separate terminal and navigate 
to the the `api-testing directory`

_______________________________________________________________________________

### GET requests

_______________________________________________________________________________

To view the response

```bash
hurl name_of_file.hurl
```
_______________________________________________________________________________

To test the response

```bash
hurl --test name_of_file.hurl 
```
_______________________________________________________________________________

### POST requests

```bash
hurl --variable userId="Add a test userId value" users_post.hurl
```
_______________________________________________________________________________
