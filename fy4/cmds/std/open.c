// open.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir;
	int i;

	if( !arg ) return notify_fail("─у╥к┤Є┐к╩▓ўсг┐\n");

	doors = environment(me)->query_doors();
	if( mapp(doors) ) {
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("─у╥к┤Є┐к╩▓ўсг┐\n");
	
		if( environment(me)->open_door(dir) ) {
			message_vision("$N╜л" + doors[dir]["name"] + "┤Є┐кбг\n", me);
			return 1;
		}
	}

	return 0;
}

int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	open <door> ╗Є <╖╜╧Є> ╗Є <╚▌╞ў>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╚├─у┤Є┐к├┼╗Є╚▌╞ўбг

╧р╣╪├№┴юг║close

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m    
HELP
    );
    return 1;
}
