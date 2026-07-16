/*
    ABOUT: The `args` function

    To run this program
    cargo bin 02_the_args_functions -- myfile.txt

*/

fn main() {
    let args: Vec<String> = std::env::args().collect();
    println!("{args:?}");

    println!("Number of arguments: {}", args.len());
    
    println!("Argument 0: {}", args[0]);
    println!("Argument 1: {}", args[1]);
}
