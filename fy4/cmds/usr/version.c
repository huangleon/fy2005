// version.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
//	write(__VERSION__+"\n");
	output = read_file("/doc/help/version.txt");
	write(output);
	return 1;
}
int help(object me)
{
  write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36m÷∏¡Ó∏Ò Ω : 	version[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

’‚∏ˆ÷∏¡Óª·œ‘ æ”Œœ∑ƒø«∞À˘”√µƒMudOS“‘º∞MudLIB∞Ê±æ.

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m 
HELP
    );
    return 1;
}
 
