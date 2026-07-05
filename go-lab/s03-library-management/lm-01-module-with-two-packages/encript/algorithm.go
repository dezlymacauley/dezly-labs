package encript

// NOTE: The function name most be Capitilized if you want to use 
// it outside of this module

func Nimbus(str string) string {
    encryptedString := ""

    for _, value := range str {
        asciiCode := int(value)
        character := string(asciiCode + 3)
        encryptedString += character
    }

    return encryptedString
}
