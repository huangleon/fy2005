/* 	╡╚╝╢╧╡═│╧╓╘┌╘┌гпгцгхгсгЇгїгЄгхгпгхг°гЁг▀гьгхгЎгхгьгогу
			гнгн by Silencer
	
*/
 
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

//	Some Reference for wizards.
//  100k (L34)гм500k (L61)гм1M(L78)гм2M(L97)гм3M(L109)
//  4M(L118)гм5M(L128)гм6M(L133),7M(L139),8M(L144),9M(L147),10M(L150)

string status_color(int current, int max);	//╤╒╔л 
 
int main(object me, string arg)
{
    	object ob;
    	mapping my, exp_data;
 	int level, old_level, pot_reward;
 	
    	seteuid(getuid(me));
 
    	if(!arg) ob = me;
    	else 
    	{
	        ob = present(arg, environment(me));
	        if (!ob) ob = find_player(arg);
	        if (!ob) ob = find_living(arg);
	        if (!ob) return notify_fail("─у╥к▓ь┐┤╦н╡─╫┤╠мг┐\n");
    	}
    	     
    	my = ob->query_entire_dbase();
/*    	    printf(HIC"б╘"HIY"йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд"HIC"б╘\n"NOR);	
    	    printf(CYN"    			"+ my["name"] + "\n"NOR);	
    	    printf(HIC"б╘"HIY"йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд"HIC"б╘\n"NOR);	*/
	    printf(" б╛╛л┴жб┐%s%5d/ %5d %s(%3d%%)" NOR "    б╛╩│╬яб┐%s%3d%%\n" NOR,
	           status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
	           status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
	           status_color(my["food"], ob->max_food_capacity()),
	           my["food"] * 100/ob->max_food_capacity()	
	        );
	    printf(" б╛╞°╤кб┐%s%5d/ %5d %s(%3d%%)" NOR "    б╛╥√╦об┐%s%3d%%\n" NOR,
	           status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
	           status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
	           status_color(my["water"], ob->max_water_capacity()),
	           my["water"] * 100/ob->max_water_capacity()
	        );
	    printf(" б╛╨─╔ёб┐%s%5d/ %5d %s(%3d%%)" HIW "    б╛╞└╝█б┐ %d\n" NOR,
	           status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
	           status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
	           my["score"]
	        );
	    printf(" б╛┴щ┴жб┐%s%5d/ %5d (%4d)" HIR "    б╛╔▒╞°б┐ %d\n" NOR,
	           status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
	           my["atman_factor"],
	           my["bellicosity"]
	        );
	    printf(" б╛─┌┴жб┐%s%5d/ %5d (%4d)"  HIG "    б╛╟▒─▄б┐ %d\n" NOR,
	           status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
	           my["force_factor"],
	           (my["potential"] - my["learned_points"])
	        );
	    exp_data = exp_to_level(my["combat_exp"]);    
	    
	    if (wizardp(me) && me->query("oldexp")) {	// ┤╦╧ю╘╩╨эWiz╙├╛╔╙╨╡─╛н╤щ╠х╧╡▓ь┐┤бг
	    	printf(" б╛╖и┴жб┐%s%5d/ %5d (%4d)"HIM "    б╛╛н╤щб┐%d\n" NOR,
	           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
	           my["mana_factor"],
	           my["combat_exp"]		    		
	        );
	    } else 
	    	    printf(" б╛╖и┴жб┐%s%5d/ %5d (%4d)"HIM "    б╛╡╚╝╢б┐ г╠%d ги%d.%dгегй\n" NOR,
		           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
		           my["mana_factor"],
				exp_data["level"],
		    		exp_data["sub"]/10,
		    		exp_data["sub"]%10,
		    	);
//	printf(HIC"б╘"HIY"йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд"HIC"б╘\n"NOR);
   	level = exp_data["level"];
	if (ob == this_player() && level > ob->query("achieved_level")) {
    		
    		old_level = ob->query("achieved_level");
    		me->set("level",level);
    		me->set("achieved_level",level);
    		
    		write(HIR"\n╣з╧▓гм─у╡─╛н╤щ╡╚╝╢╔╧╔¤╡╜"+chinese_number(me->query("level"))+"╝╢бг\n"NOR);
		
		// ├┐╡╚╝╢╜▒└°╥╗╢и╟▒─▄╓╡бг
		pot_reward = level_to_pot(level) - level_to_pot(old_level);
		me->add("potential",pot_reward);
		write(HIR"─у╡├╡╜┴╦"+pot_reward+"╡у╟▒─▄бг\n"NOR);
		
		write (WHT"╙╔╙┌─у╟┌╤з┐р┴╖гм─у╡─╛л╞°╔ё╓╡╘Ў╝╙┴╦бг\n\n"NOR);

		me->save();
		if (me->query("gender")==("┼о╨╘")) 
			message_vision(CYN"$N┐ь└╓╡╪╠°╞Ё╬ш└┤гб б╕ ╣■╣■╣■гм╔¤╝╢┴╦гбб╣\n"NOR,me);
		else 
			message_vision(CYN"$N╡├╥т╡╪╫ў│Ў╩д└√╡─╩╓╩╞ б╕ V б╣  ╦╡: б╕ ╣■╣■╣■гм╔¤╝╢┴╦гбб╣\n"NOR,me);
			
	}    	
    	return 1;
}
 
string status_color(int current, int max)
{
    int percent;
 
    if( max>0 ) percent = current * 100 / max;
    else percent = 100;
    if( percent > 100 ) return HIC;
    if( percent >= 90 ) return HIG;
    if( percent >= 60 ) return HIY;
    if( percent >= 30 ) return YEL;
    if( percent >= 10 ) return HIR;
    return RED;
}
 
int help(object me)
{
    write(@HELP
    write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : hp [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
╒т╕Ў╓╕┴ю╧╘╩╛─у(═ц╝╥)╡─╥╗╨й╗∙▒╛╫┤╠мг║

 б╛╛л┴жб┐ 4086/  4086 (100%)    б╛╩│╬яб┐  0%
 б╛╞°╤кб┐ 5001/  5001 (100%)    б╛╥√╦об┐  0%
 б╛╨─╔ёб┐ 4081/  4086 (100%)    б╛╞└╝█б┐ 946454
 б╛┴щ┴жб┐ 1125/  1125 (   0)    б╛╔▒╞°б┐ 12
 б╛─┌┴жб┐ 1385/  1385 (  70)    б╛╟▒─▄б┐ 3168879
 б╛╖и┴жб┐ 1109/  1109 (   0)    б╛╡╚╝╢б┐ г╠34 ги85.1гегй


[37mб╛╡╚╝╢б┐[32m╖ч╘╞╓╨╙├└┤║т┴┐╥╗╕Ў╬ф┴╓╚╦╬я╡─╫ю╓╪╥к▓╬╩¤гм╛Ў╢и─у─▄╤з╡╜
	╬ф╣ж╝╝─▄╡─╕▀╡═╥╘╝░╘┌╒╜╢╖╓╨╡─═■┴жбг╡╚╝╢║є╡─░┘╖╓▒╚▒э╩╛
	┤╦╥╗╡╚╝╢╡─═ъ│╔╢╚гмг▒г░г░ге╩▒╔¤╝╢бг╔¤╝╢╡─╜▒└°г║
	гиг▒гй╟▒─▄г║┐╔╥╘╙├└┤╤з╧░╕ў╓╓╝╝─▄
	гиг▓гй╛л╞°╔ё╓╡г║╓Ё▓╜╘Ў│д

[37mб╛╩│╬ябв╥√╦об┐[32m	┐╔╙╔┐═╒╗╣║┬Є▓╣│фгигхгсгЇгпгфгЄгщгюгыгйбг

[37mб╛╞└╝█б┐[32m╞└╝█┐╔╙╔═ъ│╔Quest/Taskбв╜т├╒╠╜╧╒╡╚╠с╕▀гм╩╟░▌╩ж╤з╥╒бв
	╣║╓├╖┐╬▌бв┐к░я╜с┼╔╡╚╡─▒╪╨ш╠ї╝■бг
	
[37mб╛╔▒╞°б┐[32m╗с╦ц╔▒╚╦╩¤─┐╢°╘Ў│дгм╚ч╣√╠л╕▀┴╦╗с║·┬╥╣е╗ў╘┌│б╡─╚╦гм╜╡
	╡═╔▒╞°┐╔╚е╖ч╘╞│╟└я╡─╧┤└ё│╪гм╗Є╒▀╩╣╙├╥╗╨й╠╪╩т╡──┌╣ж╨─
	╖ибг
	
[37mб╛╟▒─▄б┐[32m╙├└┤╤з╧░╕ў╓╓╝╝─▄

[37mб╛╛л┴жб┐[32m╡╚╩Ї╨╘╟ы▓╬┐┤гшгхгьгЁббгюгхгўгтгщгх

└р╦╞├№┴ю▓╬┐┤ : score
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 

HELP
    );
    return 1;
}
