import express from "express";
import type { Express } from "express";

const app: Express = express();
const port: number = 3000;

const users: string[] = [];

app.get(
  "/",
  (_req, res) => {
    res.send("Hello world");
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
      return res.status(400).send("Missing userId");
    }

    if (users.includes(newUserId)) {
      return res.status(400).send("userId already exists");
    }

    users.push(newUserId);
    return res.status(201).send("User registered");
  },
);

app.listen(
  port,
  () => {
    console.log(`Server listining on port ${port}`);
  },
);
