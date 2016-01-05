// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, j;
        object obj, *inv;
        string *id;

        if (me->query_temp("timer/big_cmd")+1 > time())
		return notify_fail("┤╦├№┴ю▒╚╜╧║─╖╤╧╡═│╫╩╘┤гм├┐├ы╓╗─▄╓┤╨╨╥╗┤╬бг\n");
	else
		me->set_temp("timer/big_cmd",time());
        
        if( !arg ) {
                inv = all_inventory(me);
                if( !sizeof(inv) )
                        return notify_fail("─у╔э╔╧├╗╙╨╚╬║╬╢л╬ўбг\n");
        write( "─у╔э╔╧╨п┤°╬я╞╖╡─▒Ё│╞╚ч╧┬(╙╥╖╜) :\n");
                for(i=0; i<sizeof(inv); i++) {
                        if( !me->visible(inv[i]) ) continue;
                        printf("%-20s = %s\n", inv[i]->name(),
                                implode(inv[i]->parse_command_id_list(), ", ") 
);
                }
                return 1;
        }

        if( arg=="here" ) {
            if (environment(me)->query("brief_objects"))
            	return notify_fail("┤╦╡╪╬▐╖и╩╣╙├┤╦├№┴юбг\n");
            inv = all_inventory(environment(me));
            if( !sizeof(inv) )
                	return notify_fail("╒т└я├╗╙╨╚╬║╬╢л╬ўбг\n");
        		write( "╘┌╒т╕Ў╖┐╝ф╓╨, ╔·╬я╝░╬я╞╖╡─(╙в╬─)├√│╞╚ч╧┬ :\n");
                for(i=0; i<sizeof(inv); i++) {
                    if( !me->visible(inv[i]) ) continue;
					if( (int) inv[i]->query("no_shown") ) 
					if(! wizardp(me))	continue;
                    if (wizardp(me) && inv[i]->query("id")!= inv[i]->get_id())
                    	printf("%-20s = %s ги%sг║%sгй\n", inv[i]->name(),
                    	implode(inv[i]->parse_command_id_list(), ","), inv[i]->name(1), inv[i]->query("id"));
                    else
                    	printf("%-20s = %s\n", inv[i]->name(),
                    	implode(inv[i]->parse_command_id_list(), ",") ); 
                }
                return 1;
        }
}
int help(object me)
{
write(@HELP

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	id [here][0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╚├─у╓к╡└╬я╞╖╡─╙в╬─├√│╞╝░├√╫╓. ╓╗┤Є id ╗с╧╘╩╛
─у╔э╔╧╦∙╨п┤°╬я╞╖╡─├√│╞. 'id here' ╘Є╧╘╩╛╦∙╙╨╕·─у╘┌═м╥╗╕Ў
╗╖╛│└я╡─╬я╝■├√│╞.

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m  
HELP
    );
    return 1;
}
 
 
