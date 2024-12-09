import dotenv from "dotenv"
import cors from "cors"
import morgan from "morgan"
import express, {Request,Response} from "express";

dotenv.config();

const app = express();
const PORT = process.env.PORT;

app.use(express.json());
app.use(express.urlencoded({extended: true}))
app.use(morgan("dev"));

app.use(cors({
    origin: "http://example.com",
    methods: ["GET","POST"]
}));

app.get("/",(req:Request, res:Response) => {
    res.send("Hello, Typescript with Express!");
});

app.listen(PORT,() => {
    console.log(`Server is running on http://localhost:${PORT}`);
}); 