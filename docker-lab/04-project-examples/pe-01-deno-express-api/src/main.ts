import express from "express";
import type { Express } from "express";

const app: Express = express();

// Enables Express to handle JSON requests
app.use(express.json());

const port: number = 3000;

const users: string[] = [];

app.get(
  "/",
  (_req, res) => {
    res.send("Hello world\n");
  },
);

app.get(
  "/users",
  (_req, res) => {
    return res.json({ users: users });
  },
);

app.post(
  "/users",
  (req, res) => {
    const newUserId = req.body.userId;

    if (!newUserId) {
      return res.status(400).send("Missing userId\n");
    }

    if (users.includes(newUserId)) {
      return res.status(400).send("userId already exists\n");
    }

    users.push(newUserId);
    return res.status(201).send("User registered\n");
  },
);

app.listen(
  port,
  () => {
    console.log(`\nServer listining on port ${port}\n`);
  },
);
