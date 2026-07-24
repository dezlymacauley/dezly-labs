/*
    ABOUT: Setting a limit on the number of arguments

    To run this program
    cargo bin 02_the_args_functions -- myfile.txt

*/

fn main() {

    // Returns an iterator over the program's arguments; index 0 is the binary name
    let args: Vec<String> = std::env::args().collect();

    if args.len() < 2 {
        eprintln!("Usage: name-of-program <file_name>");

        // The program will exit with a status code of 1
        std::process::exit(1);
    }

    let path = &args[1];
    println!("{path}");

}
