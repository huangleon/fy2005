#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    	string *files;
    	string wiz_status;
    	int i;
    	int size;
    	set_eval_limit(1); 
    	seteuid(getuid());

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" )
		return notify_fail("╓╗╙╨admin▓┼─▄╩╣╙├┤╦├№┴юбг\n");
		
		
    	if(!arg || arg=="") return notify_fail("╕ё╩╜▓╗╢╘гб\n");
    
    
    	files= get_dir(arg);
    	reset_eval_cost();
    	for(i=0; i<sizeof(files); i++) 
    	{
    	        size=sizeof(files[i]);
        	if(files[i][(size-2)..size]==".c")
  	               	me->ccommand(sprintf("rm %s%s",arg,files[i]));
        }   	 	
    	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	updatep ─┐┬╝├√	[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

		╔ў╙├		╔ў╙├
		
rmpartner /d/baiyun/	╛═╩╟╔╛│¤╦∙╙╨/d/baiyun/─┐┬╝╧┬╡─╬─╝■бг


[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}