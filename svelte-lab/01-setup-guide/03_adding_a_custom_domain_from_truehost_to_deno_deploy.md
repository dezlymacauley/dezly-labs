# Adding a custom domain name from truehost to Deno Deploy
_______________________________________________________________________________

### Step 1: First purchase a domain name from Truehost
```
https://truehost.co.za/
```
_______________________________________________________________________________

Click `Domains` on the drop down menu,
then click `My Domains`

You should see you domain listed.

E.g. `dezlymacauley.com`
_______________________________________________________________________________

Note: There will be a red padlock next to the name.

If you hover next to it, it will say no `SLL` certificate Detected.

The `SLL` certificate is what gives you the `https://` on your website,
otherwise you only have `http://` (not secure).

Ignore that and do not buy an `SLL` certificate, because your website will
not be deployed on Truehost.
_______________________________________________________________________________

`Deno Deploy` will give you a free `SLL` certificate.
_______________________________________________________________________________

Next to the `Status` column where it says `Active`,
you should see three dots `...`
_______________________________________________________________________________

Click on the three dots and then click on `Manage Nameservers`

Make sure it is set to `Use default nameservers`
_______________________________________________________________________________

### Open a new tab and Go to your console on `Deno Deploy`

```
https://console.deno.com/dezlymacauley
```
_______________________________________________________________________________

Click on `Domains`, the click `+ Add Domain`
_______________________________________________________________________________

Type your domain name like this
```
dezlymacauley.com
```

Then click the `Save` button.
_______________________________________________________________________________

You will see a message like this:
```
DNS records

Add all records from any of these tabs to your DNS provider 
to begin routing traffic to Deno Deploy.
```
_______________________________________________________________________________

There will be three tabs

_______________________________________________________________________________

### Tab 1 - CNAME

#### CNAME ? 
`This record is needed to provision TLS certificates, 
and to verify ownership of this domain`

_acme-challenge.dezlymacauley.com

83fe7d32b314f853b35f106949d4e212._acme.deno.net.

```
Proxying must be disabled for this record.

On Cloudflare, proxying is enabled by default. 
It is enabled when the orange cloud icon () is shown. 
To disable proxying, click the orange cloud to turn it gray ().

Most DNS providers have no proxying option. 
For these providers, 
you do not need to worry about disabling proxying.
```

#### CNAME
@.dezlymacauley.com

alias.deno.net
_______________________________________________________________________________

### TAB 2 - ANAME/ALIAS

#### ANAME/ALIAS

@.dezlymacauley.com

alias.deno.net
_______________________________________________________________________________

### TAB 3 - A/AAA

Proxying must be disabled for this record.

#### A
@.dezlymacauley.com

69.67.170.170

#### AAAA
@.dezlymacauley.com

2602:f70f::1
_______________________________________________________________________________

### Leave the Deno Deploy Tab Running
_______________________________________________________________________________

### Go back to `Truehost`

```
https://truehost.co.za/
```
_______________________________________________________________________________

Click `Domains` on the drop down menu,
then click `My Domains`

You should see you domain listed.

E.g. `dezlymacauley.com`
_______________________________________________________________________________

Next to the `Status` column where it says `Active`,
you should see three dots `...`

`Click the three dots`, then click `Manage Domain`
_______________________________________________________________________________

On the left sidebar that says `Manage`,
you should see an option that says `Manage DNS`

_______________________________________________________________________________

### Add the CNAME verification record from Deno Deploy

Click `+ Add Record`

| Field                  | Value                                             |
| ---------------------- | ------------------------------------------------- |
| Type                   | `CNAME`                                           |
| Name                   | `_acme-challenge`                                 |
| TTL                    | `14400`                                           |
| Cname                  | `83fe7d32b314f853b35f106949d4e212._acme.deno.net.`|

_______________________________________________________________________________

### Add the root domain A record from Deno Deploy

Click `+ Add Record`

| Field                  | Value           |
| ---------------------- | --------------- |
| Type                   | `A`             |
| Name                   | `@`             |
| TTL                    | `14400`         |
| Address                | `69.67.170.170` |

_______________________________________________________________________________

### Add the root domain AAAA record from Deno Deploy

| Field                  | Value          |
| ---------------------- | -------------- |
| Type                   | `AAAA`         |
| Name                   | `@`            |
| TTL                    | `14400`        |
| Address                | `2602:f70f::1` |

_______________________________________________________________________________

### Go back to the Deno Deploy Tab

You you should see something like

```
DNS records verified 1 minutes ago
```
_______________________________________________________________________________

You will see this

```
Certificates

TLS certificates are needed to secure your domain. You can not use a domain without a certificate.
```

Click `Provision certificate`
_______________________________________________________________________________

You will see this

```
Certificate successfully provisioned

We use Let's Encrypt to automatically provision certificates and will renew them automatically.

dezlymacauley.com

EC P-256 key

Expires in 89 days

Renews in 60 days

Created 1 minute ago
```
_______________________________________________________________________________

Click `Assign`, and attach the domain name to your repo.
_______________________________________________________________________________
