// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string *tuned_ch;
    //considerate for bt and tt.
    if(arg=="bt") arg="bangtalk";
    else if(arg=="tt") arg="teamtalk";
	if (arg == "announce")
		return notify_fail("╣л╩╛╞╡╡└╬▐╖и▒╗╣╪▒╒бг\n");   

    tuned_ch = me->query("channels");
    if( !arg )
    {
        if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
            write("─у╧╓╘┌▓в├╗╙╨╩╒╠¤╚╬║╬╞╡╡└бг\n");
        else
            write("─у╧╓╘┌╩╒╠¤╡─╞╡╡└г║" + implode(tuned_ch, ", ") + "бг\n");
    }
    else if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 )
    {
        write("╣╪▒╒ " + arg + " ╞╡╡└бг\n");
        tuned_ch -= ({ arg });
        me->set("channels", tuned_ch);
    }
    else if(CHANNEL_D->valid_channel(me, arg))
    {
        write("┤Є┐к " + arg + " ╞╡╡└бг\n");
        tuned_ch += ({ arg });
        me->set("channels", tuned_ch);
    }
    else return notify_fail("├╗╙╨╒т╕Ў╞╡╡└бг\n");

    return 1;
}

int help(object me)
{
    write(@HELP

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	tune [<╞╡╡└├√│╞>][0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╚├─у╤б╘ё╩╟╖ё╥к╩╒╠¤─│╥╗╞╡╡└╡─╤╢╧вгм╚ч╣√├╗╙╨╓╕╢и╞╡╡└├√│╞гм
╛═╗с┴╨│Ў─у─┐╟░╩╒╠¤╓╨╡─╞╡╡└гм╚ч╣√╓╕╢и┴╦╞╡╡└гм╘н└┤╩╒╠¤╓╨╡─╛═╗с╣╪╡Їгм
╖┤╓о┤Є┐кбг

╚ч╣√─у╢╘╥╗╕Ў├╗╙╨╩╒╠¤╓╨╡─╞╡╡└╜▓╗░гм╗с╫╘╢п╜л╦№┤Є┐кбг
╥к╢╘╥╗╕Ў╞╡╡└╜▓╗░гм╓╗╥к╙├г║

<╞╡╡└├√│╞> <╤╢╧в> ....

└¤╫╙г║
  chat hello everyone!
  
┐╔╥╘╩╒╠¤╡─╞╡╡└╙╨г║
    info б╛┤л╬┼б┐
    vote б╛═╢╞▒б┐
    chat б╛╧╨┴─б┐
    fy   б╛╖ч╘╞б┐
    new  б╛╨┬╩╓б┐
    gab  б╛╩╨╛об┐
    rumorб╛╥е╤╘б┐
    bangtalk/btб╛░я╗сб┐
    teamtalk/ttб╛╢╙╬щб┐
    
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
	);
    if(wizardp(me))
        write(@HELP
╬╫╩ж┐╔╥╘╩╒╠¤╡─╞╡╡└╙╨г║
    sys  б╛╧╡═│б┐
    qst  б╛╚╬╬ёб┐
    wiz  б╛╬╫╩жб┐

HELP
            );
	return 1;
}

