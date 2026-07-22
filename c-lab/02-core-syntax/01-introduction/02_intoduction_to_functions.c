/*
    ABOUT: Introduction to functions 

    A function is a named block of code that can contain several lines of code
    that perform a specific task.
   
    This is the syntax of a function in C:

    type_of_data_returned function_name(data_type parameter) {
        The tasks that the function needs to do

        return data_type;
    }

*/

int main(void) {

    // The return type of the function `main` is an `int`
    // So that means that the the last line inside the function block should
    // end with this:
    // return value-that-matches-return-type-of-function;

    // This means that the main function will return 0 after it has completed
    // all of the tasks in this block.
    //
    // To confirm this, after running this program, run this command:
    // echo $?
    //
    // On Linux, `$?` is a special variable that will show the exit status
    // of the last command.
    //
    // If you are using fish shell, `echo $?` won't work.
    // fish shell uses this command instead:
    // echo $status
    return 0;
}
