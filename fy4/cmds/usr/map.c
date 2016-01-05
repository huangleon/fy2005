// map.c by Silencer@fy4.

#include <ansi.h>
#include "/doc/help.h"
inherit F_CLEAN_UP;

string ngstr(string str);

int main(object me, string arg)
{
    int i;
    string file, area, room, map, room_name, room1;
    string a1, a2, a3;


    if (me->query_temp("timer/map")+2>time())
	return notify_fail("¼ìÑéµØÍ¼×î¶àÖ»ÄÜÃ¿Á½ÃëÖ´ĞĞÒ»´Î¡£\n");
    file = file_name(environment(me));
    //  write("file is "+file +"\n");
    if (sscanf(file,"/d/%s/%s",area,room)==2) {
	switch (area) {
	case "fywall":
	case "fycycle": area = "fycycle";  break;
	case "fy":	area = "fengyun";  break;
	case "palace":	area = "diwanggu"; break;
	case "resort":	area = "tiexue";   break;
	case "wulapo":  area = "xinjiang"; break;
	case "taoguan": area = "sanqing" ; break;
	case "guanyin": area = "tianfeng"; break;
	case "chuenyu": area = "heisong" ; break;
	case "death": 	area = "diyu"	 ; break;
	case "oldpine":	area = "laoyun" ; break;	
	case "ghost":   area = "youling"; break;
	case "xinjiang":area = "wulapo"; break;
	case "tieflag" :area = "east";	 break;
	case "eastcoast": area = "east"; break;
	case "quicksand": area = "west"; break;
	case "bawang":  area = "ehu"	;break;
	case "eren":    area = "kunlun"; break;
	case "cave": 	area = "dixia";  break;
	}

	if (area == "fengyun") {
	    if ( environment(me)->query("map")=="fyeast"){area = "fengyun_east";}
	    if ( environment(me)->query("map")=="fywest"){area = "fengyun_west";}
	    if ( environment(me)->query("map")=="fynorth"){area = "fengyun_north";}
	    if ( environment(me)->query("map")=="fysouth"){area = "fengyun_south";}
	}
	if (area == "zangbei") {
	    if ( environment(me)->query("map")=="zbeast"){area = "zangbei_east";}   
	    	else area = "zangbei_west";
	}
	
	//other areas can be added in here later...


	if (file_size(HELP_DIR + "help/maps/"+area+"_map.txt")>0) {
	    map = read_file(HELP_DIR + "help/maps/"+area+"_map.txt");
	    room_name = environment(me)->query("short");

	    room_name = ngstr(room_name);
//	    write(room_name); 
	    map = replace_string(map,room_name,BGRN HIW""+room_name+""NOR);
	    write (map);
	    write ("\n\nÄãÏÖÔÚËù´¦µØµãµÄµØÃûÎª  "+ HIR""+room_name + NOR"\n");
	    write ("´ËµØÃûÔÚµØÍ¼ÉÏÒÔ"HIG"ÁÁÂÌÉ«"NOR"±ê³ö¡££¨×¢Òâ£¬¿ÉÄÜÓĞÖØÃûµØµã´æÔÚ£©\n\n\n");
	    me->set_temp("timer/map",time());
	    return 1;
	}
    }
    return notify_fail("µ±Ç°µØÇøµÄµØÍ¼²»´æÔÚ¡£\n");
}

string ngstr(string str)
{
    int i,i2;
    string strc;
    strc=str;
    // filter color-code
    str=replace_string(str,CSI,"");

    str=replace_string(str,"2;37;0m","");

    str=replace_string(str,"41;","");
    str=replace_string(str,"42;","");
    str=replace_string(str,"43;","");
    str=replace_string(str,"44;","");
    str=replace_string(str,"45;","");
    str=replace_string(str,"46;","");
    str=replace_string(str,"47;","");
    str=replace_string(str,"1;","");
    str=replace_string(str,"30m","");
    str=replace_string(str,"31m","");
    str=replace_string(str,"32m","");
    str=replace_string(str,"33m","");
    str=replace_string(str,"34m","");
    str=replace_string(str,"35m","");
    str=replace_string(str,"36m","");
    str=replace_string(str,"37m","");
    str=replace_string(str,"38m","");
    str=replace_string(str,"40m","");
    str=replace_string(str,"41m","");
    str=replace_string(str,"42m","");
    str=replace_string(str,"43m","");
    str=replace_string(str,"44m","");
    str=replace_string(str,"45m","");
    str=replace_string(str,"46m","");
    str=replace_string(str,"47m","");
    str=replace_string(str,"1m","");

    return str;

}


int help(object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ :   map[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Ö¸Áî¸ñÊ½£ºmap

Õâ¸öÖ¸ÁîÌá¹©Äãµ±Ç°ÇøÓòµÄµØÍ¼¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}

/* ·Ç³£²»ÍêÉÆµÄµØÍ¼¡£
¡ı¡ü¡ú¡û

help bat_map.txt            òùòğµºµØÍ¼  
help chenxiang_map.txt      ³ÁÏãÕòµØÍ¼
help daimiao_map.txt        á·ÃíµØÍ¼
help diwanggu_map.txt       µÛÍõ¹ÈµØÍ¼
help fengyun_map.txt        ·çÔÆ³ÇµØÍ¼
help fugui_map.txt          ¸»¹óÉ½×¯µØÍ¼
help guanwai_map.txt        ¹ØÍâµØÍ¼
help huashan_map.txt        »ªÉ½µØÍ¼
help huangshan_map.txt      »ÆÉ½µØÍ¼
help jinan_map.txt          ¼ÃÄÏµØÍ¼
help laowu_map.txt          ÀÏÎİµØÍ¼
help loulan_map.txt         Â¥À¼³ÇµØÍ¼
help qianjin_map.txt        Ç§½ğÂ¥µØÍ¼
help shaolin_map.txt        ÉÙÁÖËÂµØÍ¼
help songshan_map.txt       áÔÉ½µØÍ¼
help taishan_map.txt        Ì©É½µØÍ¼
help wolfmount_map.txt      ÀÇÉ½µØÍ¼
help wudang_map.txt         Îäµ±É½µØÍ¼
help wulapo_map.txt         ÎÚÀ­²´µØÍ¼
*/
