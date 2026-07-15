import express from "express";
import type { Express } from "express";

const app: Express = express();
const port: number = 3000;

app.get(
  "/",
  (_req, res) => {
    res.send("Hello world");
  },
);

app.listen(
  port,
  () => {
    console.log(`Server listining on port ${port}`);
  },
);
