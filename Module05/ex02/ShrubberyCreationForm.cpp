#include "ShrubberyCreationForm.hpp"

/*ShrubberyCreationForm::ShrubberyCreationForm() {}*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	Form("Shrubbery Creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) \
	: Form(copy), _target(copy._target)
{}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	Form::operator=(copy);
	*(const_cast<std::string*>(&_target)) = copy._target;
	return (*this);
}

const char* ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return "Cannot open file for Shrubbery Creation Form";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs)
		throw OpenFileException();
	ofs << _trees[rand() % 3] << std::endl;
	ofs.close();
}

std::string const ShrubberyCreationForm::_trees[3] = {
"                                              .\n \
                                   .         ;\n \
      .              .              ;%     ;;\n \
        ,           ,                :;%  %;\n \
         :         ;                   :;%;'     .,\n \
,.        %;     %;            ;        %;'    ,;\n \
  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n \
   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n \
    ;%;      %;        ;%;        % ;%;  ,%;'\n \
     `%;.     ;%;     %;'         `;%%;.%;'\n \
      `:;%.    ;%%. %@;        %; ;@%;%'\n \
         `:%;.  :;bd%;          %;@%;'\n \
           `@%:.  :;%.         ;@@%;'\n \
             `@%.  `;@%.      ;@@%;\n \
               `@%%. `@%%    ;@@%;\n \
                 ;@%. :@%%  %@@%;\n \
                   %@bd%%%bd%%:;\n \
                     #@%%%%%:;;\n \
                     %@@%%%::;\n \
                     %@@@%(o);  . '\n \
                     %@@@o%;:(.,'\n \
                 `.. %@@@o%::;\n \
                    `)@@@o%::;\n \
                     %@@(o)::;\n \
                    .%@@@@%::;\n \
                    ;%@@@@%::;.\n \
                   ;%@@@@%%:;;;.\n \
               ...;%@@@@@%%:;;;;,..    Gilo97\n \
------------------------------------------------\n \
This ASCII pic can be found at\n \
https://asciiart.website/index.php?art=plants/trees\n",
"           \\/ |    |/\n \
        \\/ / \\||/  /_/___/_\n \
         \\/   |/ \\/\n \
    _\\__\\_\\   |  /_____/_\n \
           \\  | /          /\n \
  __ _-----`  |{,-----------~\n \
            \\ }{\n \
             }{{\n \
             }}{\n \
             {{}\n \
       , -=-~{ .-^- _\n \
  ejm        `}\n \
              {\n \
------------------------------------------------\n \
This ASCII pic can be found at\n \
https://asciiart.website/index.php?art=plants/trees\n",
"         - - -\n \
       -        -  -     --    -\n \
    -                 -         -  -\n \
                    -\n \
                   -                --\n \
   -          -            -              -\n \
   -            '-,        -               -\n \
   -              'b      *\n \
    -              '$    #-                --\n \
   -    -           $:   #:               -\n \
 --      -  --      *#  @):        -   - -\n \
              -     :@,@):   ,-**:'   -\n \
  -      -,         :@@*: --**'      -   -\n \
           '#o-    -:(@'-@*\"\'  -\n \
   -  -       'bq,--:,@@*'   ,*      -  -\n \
              ,p$q8,:@)'  -p*'      -\n \
       -     '  - '@@Pp@@*'    -  -\n \
        -  - --    Y7'.'     -  -\n \
                  :@):.\n \
                 .:@:'.\n \
               .::(@:.      -Sam Blumenstein-\n \
------------------------------------------------\n \
This ASCII pic can be found at\n \
https://asciiart.website/index.php?art=plants/trees\n"
};