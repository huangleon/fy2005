// status.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string msg;

	msg = (string)mud_status(arg=="detail" ? 1 : 0);
	if( stringp(msg) ) write(msg);

	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	status [detail][0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╧╘╩╛│Ў─┐╟░╙╬╧╖╡─╥╗╨й╧р╣╪╫╩┴╧╝░╫┤┐Ў.

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m  
HELP
    );
    return 1;
}
 
