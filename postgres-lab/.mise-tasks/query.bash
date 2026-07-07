#!/usr/bin/env bash
#MISE description="🔎 Perform database queries with pgcli"
#MISE quiet=true
#______________________________________________________________________________

# STEP: 1 => Ensure that environment variables for PSQL are available

# Fail immediately if any unset variable is used
set -eu

# This is a collection of guard clauses,
# to check that the following environment variables have been set in 
# `mise.toml` and are accessible.
: "${PGCLI_LOGIN_USER_NAME:?Missing PGCLI_LOGIN_USER_NAME}"
: "${PGCLI_DB_NAME:?Missing PGCLI_DB_NAME}"
: "${PGCLI_DB_HOST:?Missing PGCLI_DB_HOST}"
: "${PGCLI_DB_PORT:?Missing PGCLI_DB_PORT}"
: "${PGCLI_DB_PORT:?Missing PGCLI_DB_PORT}"
: "${PGCLI_CONFIG_FILE:?Missing PGCLI_CONFIG_FILE}"

#______________________________________________________________________________

# STEP: 2 => Connect to the Postgres server with pgcli

    echo
    echo "____________________________________________________________"
    echo "📁 Connecting to database: $PGCLI_DB_NAME"
    echo "  - Host: $PGCLI_DB_HOST"
    echo "  - Port: $PGCLI_DB_PORT"
    echo "👤 via the user: $PGCLI_LOGIN_USER_NAME"
    echo "_____________________________________________________________"
    echo

    pgcli \
        -U "$PGCLI_LOGIN_USER_NAME" \
        --pgclirc "$PGCLI_CONFIG_FILE" \
        -d "$PGCLI_DB_NAME" \
        -h "$PGCLI_DB_HOST" \
        -p "$PGCLI_DB_PORT"

#______________________________________________________________________________
