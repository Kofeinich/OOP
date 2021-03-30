#include "BackUp.h"
#include "CreationStrategy.h"

int main() {
    BackUp backUp;
    FullCreation fullCreation;
    IncCreation incCreation;
    SeparatedStorage separatedStorage;
    auto file1 = new File("file1", 3);
    auto file2 = new File("file2", 134);
    backUp.addFile(file1);
    backUp.addFile(file2);
    fullCreation.create(&backUp, separatedStorage);
    backUp.setTime(123);
    incCreation.create(&backUp, separatedStorage);
    backUp.show();
    return 0;
}
