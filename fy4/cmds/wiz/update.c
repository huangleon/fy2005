// Silencer@fengyun workgroup	June.2005
// Modified so it won't update "possessed pet". It doesn't care about player/non-player pet though.

#include "/doc/help.h"

inherit F_CLEAN_UP;

int update_player(object me);

int main(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("─у╥к╓╪╨┬▒р╥ы╩▓ўс╡╡░╕г┐\n");

        if( (obj = present(file, environment(me))) && interactive(obj) )
                return update_player(obj);

        if( file == "me" )
                return update_player(me);
        else {
                file = resolve_path(me->query("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c"; 
        }

        if( file_size(file)==-1 )
           	return notify_fail("├╗╙╨╒т╕Ў╡╡░╕бг\n");

		if (wiz_level(me)<4)
			return notify_fail("─у╡─╚и╧▐▓╗─▄╓╪╨┬▒р╥ы╬─╝■бг\n");
		
        me->set("cwf", file);

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("─у▓╗─▄╘┌ VOID_OB └я╓╪╨┬▒р╥ы VOID_OBбг\n");
                }

                inv = all_inventory(obj);
                i = sizeof(inv);
                while(i--) {
                        if(userp(inv[i])|| 
                        	inv[i]->query("possessed")) {
                        	inv[i]->move(VOID_OB, 1);
                        } else {
                        	destruct(inv[i]);
			}
                }

                destruct(obj);
        }

        if (obj) return notify_fail("╬▐╖и╟х│¤╛╔│╠╩╜┬ыбг\n");

    	write("╓╪╨┬▒р╥ы " + file + "г║");
        err = catch( call_other(file, "???") );
        if (err)
                printf( "╖в╔·┤э╬єг║\n%s\n", err );
        else {
                write("│╔╣жгб\n");
   		log_file( "UPDATE_LOG", sprintf("(%s)
%s updated %s\n", ctime(time()), me->query("name"), file));
        
        	if( (i=sizeof(inv)) && (obj = find_object(file))) {
        		while(i--)
                        {
                        	if( inv[i] && (userp(inv[i]) || inv[i]->query("possessed"))) 
					inv[i]->move(obj, 1);
                		
                	}
                }
        }
                
        return 1;
}

int update_player(object me)
{
        object env, link_ob, obj;

        env = environment(me);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
        exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

        write("╔э╠х╕№╨┬═ъ▒╧бг\n\n");
        obj->move(env);
        obj->write_prompt();

        return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	update <╡╡├√|here|me|═ц╝╥├√>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╕№╨┬╡╡░╕, ▓в╜л╨┬╡╡╡──┌╚▌╘╪╚ы╝╟╥ф╠х─┌. ╚Ї─┐▒ъ╬к
'here' ╘Є╕№╨┬╦∙╘┌╗╖╛│. ╚Ї─┐▒ъ╬к 'me' ╘Є╕№╨┬╫╘╝║╡─╚╦╬я. ╚Ї─┐
▒ъ╬к═ц╝╥╘Є┐╔╕№╨┬═ц╝╥╬я╝■.

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
HELP
    );
    return 1;
}
 
