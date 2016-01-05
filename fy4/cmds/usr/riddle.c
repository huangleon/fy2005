// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    mapping riddle;
    string *list, attr;
    object ob;
    int i,j, *num;

    if (wizardp(me) && stringp(arg))	
    {
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("▀╫... ╙╨╒т╕Ў╚╦┬Ё?\n");
    }else
	ob = me;

	riddle = ob->query("riddle");	 
    	
    write(WHT"\tбббб		" + ob->name()+ "╒¤╘┌╜т╡─├╒╠т\n"NOR);
    write(HIR BLK"йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд\n"NOR);

    if (!riddle)	write (HIR "╬▐\n"NOR);
    else
    {
		list = keys(riddle);
		i = 0;					// deal with the problem of setting riddle=0
		for(j=0; j<sizeof(list); j++)
		{
		    if (riddle[list[j]])
		 	{
		    	if(i%5!=4) 
					write(sprintf(YEL"%-16s"NOR,list[j]));
		    	else 
					write(YEL + list[j] + "\n"NOR);   
				i++;
			}
		}
    }
    write(HIR BLK"\nйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд\n"NOR);
    
 
    riddle = ob->query("m_success");

    write(WHT"\tбббб		"+ob->name()+ "╥╤╛н╜т┐к╡─├╒╠т\n"NOR);
    write(HIR BLK"йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд\n"NOR);

    if (!riddle)	write (HIR "╬▐\n"NOR,16);
    else
    {
	list = keys(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    if(i%5!=4) 
		write(sprintf(CYN"%-16s"NOR,list[i]));
	    else
		write(CYN + list[i] + "\n"NOR);   
	}
    }
    write(HIR BLK"\nйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд\n"NOR);


    riddle = ob->query("imbue");

    write(WHT"\tбббб		" + ob->name()+ "╜т├╒╘Ў╝╙╡─╩Ї╨╘\n"NOR);
    write(HIR BLK"йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд\n"NOR);

    if (!riddle)	write (HIR "╬▐\n"NOR);
    else
    {
	list = keys(riddle);
	num = values(riddle);
	for(i=0; i<sizeof(list); i++)
	{
	    switch (list[i])
	    {
	    	case "agi": attr = "╦┘╢╚"; break;
	    	case "int": attr = "▓┼╓╟"; break;
	    	case "con": attr = "╠х╓╩"; break;
	    	case "str": attr = "┴ж┴┐"; break;
	    	case "cps": attr = "╢и┴ж"; break;
	    	case "kar": attr = "╘╦╞°"; break;
	    	default: attr = "";
	    }		
	    
	    if (sizeof (attr)>0)
		write(HIR + attr +" +" + num[i] + "\t"NOR);   
	}
    }
    write(HIR BLK"\nйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд\n"NOR);

    return 1;
}
int help(object me)
{
    write(@HELP

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	riddle            [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╚├─у╓к╡└─у─┐╟░╥╤╛н╜т┐к╡─├╒╠тгм╥╘╝░╥Є╜т├▄╘Ў╝╙╡─╩Ї╨╘

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m  
HELP
    );
    return 1;
}


