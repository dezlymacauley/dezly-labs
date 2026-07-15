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

/

```bash
hurl root_get.hurl
```
_______________________________________________________________________________

/users

```bash
hurl users_get.hurl
```
_______________________________________________________________________________

### POST requests

/users

```bash
hurl users_post_missing_userid.hurl
```
_______________________________________________________________________________

/users

```bash
hurl --variable userId="Add a test userId value" users_post.hurl
```
_______________________________________________________________________________
