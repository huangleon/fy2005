// help.c

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

void selete_main(string num,object ob);
void back_off(string num,object ob);
void quit_help(object ob);

int main(object me, string arg)
{
        int i;
        string file, map, *search;
        object ob;
        ob = this_player();

        write(CLR);
        write(read_file("/doc/help/cmds_main.txt"));
        input_to("selete_main", ob);
        ob->set_temp("block_msg/all",1);
        return 1;
}

void selete_main(string num,object ob)
{
        
        string *code = ({"1","2","3","4","5","6","7","8"});
                
        if(member_array(num, code) != -1)
        {
                ob->delete_temp("block_msg/all");
                write(CLR);
                write(read_file("/doc/help/help/cmds_"+num+".txt"));
                input_to("back_off",ob);
        }
        else if( num == "q" || num == "Q" || num == "0") quit_help(ob);
        else
        {
                ob->delete_temp("block_msg/all");
                write(HIR"\n    ╢╘▓╗╞Ёгм├╗╙╨╒т╕Ў╤б╧югб─·┐╔╥╘╤б╘ёг║\n"NOR);
                write(CYN"  ббг▒- 8 ╧р╣╪╡─├№┴ю╦╡├ўбббб0бв═╦│Ў░я╓·\n"NOR);
                write(CYN"\n    ╟ы╩ф╚ы╤б╘ё╧юги1-8 ╗Є 0гйг║"NOR);
                ob->set_temp("block_msg/all");
                input_to("selete_main", ob);
        }
}

void back_off(string num,object ob)
{
	write(CLR);
        write(read_file("/doc/help/cmds_main.txt"));
        input_to("selete_main", ob);
        ob->set_temp("block_msg/all",1);
}

void quit_help(object ob)
{
        ob->delete_temp("block_msg/all");
     	write(HIC"\n ╨╗╨╗╩╣╙├╖ч╘╞├№┴ю░я╓·╧╡═│гм╜°╥╗▓╜╡─╦╡├ў┐╔▓╬╝√╕ў╛▀╠х├№┴югб\n\n"NOR);
        return;
}

int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 		cmds[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў├№┴ю╕°│Ў╖ч╘╞╓╨═ц╝╥┐╔╥╘╩╣╙├╡─╦∙╙╨├№┴ю┴╨▒эгм
╟ы░┤╒╒╞┴─╗╠с╩╛╩ф╚ы╤б╧ю╥╘╜°╚ы╫╙▓╦╡ебг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
        );
        return 1;
}

