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
	return notify_fail("�����ͼ���ֻ��ÿ����ִ��һ�Ρ�\n");
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
	    write ("\n\n�����������ص�ĵ���Ϊ  "+ HIR""+room_name + NOR"\n");
	    write ("�˵����ڵ�ͼ����"HIG"����ɫ"NOR"�������ע�⣬�����������ص���ڣ�\n\n\n");
	    me->set_temp("timer/map",time());
	    return 1;
	}
    }
    return notify_fail("��ǰ�����ĵ�ͼ�����ڡ�\n");
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
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ :   map[0m
[0;1;37m����������������������������������������������������������������[0m   

ָ���ʽ��map

���ָ���ṩ�㵱ǰ����ĵ�ͼ��

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}

/* �ǳ������Ƶĵ�ͼ��
��������

help bat_map.txt            ���𵺵�ͼ  
help chenxiang_map.txt      �������ͼ
help daimiao_map.txt        ����ͼ
help diwanggu_map.txt       �����ȵ�ͼ
help fengyun_map.txt        ���Ƴǵ�ͼ
help fugui_map.txt          ����ɽׯ��ͼ
help guanwai_map.txt        �����ͼ
help huashan_map.txt        ��ɽ��ͼ
help huangshan_map.txt      ��ɽ��ͼ
help jinan_map.txt          ���ϵ�ͼ
help laowu_map.txt          ���ݵ�ͼ
help loulan_map.txt         ¥���ǵ�ͼ
help qianjin_map.txt        ǧ��¥��ͼ
help shaolin_map.txt        �����µ�ͼ
help songshan_map.txt       ��ɽ��ͼ
help taishan_map.txt        ̩ɽ��ͼ
help wolfmount_map.txt      ��ɽ��ͼ
help wudang_map.txt         �䵱ɽ��ͼ
help wulapo_map.txt         ��������ͼ
*/
