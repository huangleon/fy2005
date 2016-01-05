// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;

mapping area_name = ([ 
		"baiyun"	:	"°×ÔÆ³Ç",
		"bat"		:	"òùòðµº",
		"bashan"	: 	"°ÍÉ½",
		"bawang"	:	"¶ö»¢¸Ú",
		"biancheng"	:	"±ß³Ç",
		"cave"		:   "·çÔÆµØÏÂ³Ç",
		"chenxiang"	:	"³ÁÏãÕò",
		"chuenyu"	:	"ºÚËÉ±¤",
		"cyan"		: 	"Ã÷Ï¼É½",
		"daimiao"	:	"á·Ãí",
		"death"		:	"¹íÃÅ¹Ø",
		"eastcoast"	: 	"¶«º£",
		"eren"		:    "¶ñÈË¹È",
		"eren2"		:    "¶ñÈË¹È",
		"fy"		:	"·çÔÆ³Ç",
		"fugui"		:    "¸»¹óÉ½×¯",
		"fycycle"	:  	"·çÔÆ³Ç",
		"fywall"	:   "·çÔÆ³Ç",
		"ghost"		:    "ÓÄÁéÉ½×¯",
		"guanwai"	:  	"¹ØÍâ",
		"guanyin"	:  	"Ìì·ã",
		"huangshan"	:	"»ÆÉ½",
		"huashan"	:  	"»ªÉ½",
		"jinan"		:    "¼ÃÄÏ",
		"laowu"		:    "ÀÏÎÝ",
		"libie"		:    "ÎÞÃûÐ¡Õò",
		"loulan"	:   "Â¥À¼",
		"manglin"	:  	"Ã§ÁÖ",
		"oldpine"	:  	"ÀÏËÉÕ¯",
		"palace"	:   "µÛÍõ¹È",
		"qianfo"	:   "Ç§·ðÉ½",
		"qianjin"	:  	"Ç§½ðÂ¥",
		"qingping"	: 	"ÇåÆ½É½×¯",
		"quicksand"	:	"´óÉ³Ä®",
		"resort"	:   "ÌúÑ©É½×¯",
		"shaolin"	:  	"ÉÙÁÖËÂ",
		"shenshui"	: 	"ÉñË®¹¬",
		"songshan"	: 	"áÔÉ½",
		"taiping"	:  	"Ì«Æ½Õò",
		"taishan"	:  	"Ì©É½",
		"taoguan"	:  	"ÌÒÔ´",
		"taoyuan"	:  	"ÈýÇå¹Û",
		"tieflag"	:  	"´óÆì¹È",
		"wanmei"	:   "ÍòÃ·É½×¯",
		"wolfmount"	:	"ÀÇÉ½",
		"wudang"	:   "Îäµ±",
		"xiangsi"	: 	"ÏàË¼Áë",
		"xinjiang"	: 	"ÐÂ½®",
		"yingou"	:   "Òø¹³¶Ä·»",
		"zhaoze"	:	"ÕÓÔóµØ",
		"zangbei"	:	"²Ø±±",
]);                             

int main(object me, string arg)
{                               
	object ob, man;
	int i, cost;            
	object room;            
	string location,*area,line;
                         
    if (me->query("NO_PK"))
		return notify_fail("´ËÃüÁîÖ»ÓÐÑ²²¶ºÍÌÓ·¸²ÅÄÜÊ¹ÓÃ¡£\n");
	
	if ( !arg )             
		return notify_fail("ÄãÒª°µÖÐµ÷²éË­µÄÏûÏ¢£¿\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("ÄãÒª´òÌýË­µÄÏûÏ¢£¿\n");
	if ( ob == me )         
		return notify_fail("Õö´óÑÛ¾¦¿´¿´×Ô¼º°É£¡\n");

	if (ob->query("NO_PK"))
		return notify_fail("´ËÃüÁîÖ»ÓÐÕë¶ÔÑ²²¶»òÕßÌÓ·¸Ê¹ÓÃ¡£\n");
		
    if ( present(ob, environment(me)) )
        return notify_fail("Õâ¸öÈË¾ÍÔÚÄãÑÛÇ°£¡\n");

	if ( me->query("sen") <= 500 )
		return notify_fail("´ËÃüÁîÖÁÉÙºÄ·Ñ500µãÐÄÉñ¡£\n");
	me->receive_damage("sen", 500);		

	room=environment(ob);
	area=keys(area_name);
	if (!room) 
		write("²»Çå³þÔÚÄÄÀï¿ÉÒÔÕÒµ½"+ob->name()+"¡£\n");
	else {
		location=domain_file(file_name(room));
		if (member_array(location,area)==-1)	
			write("²»Çå³þÔÚÄÄÀï¿ÉÒÔÕÒµ½"+ob->name()+"¡£\n");
		else 
			write(ob->name()+"ºÃÏñ×î½ü¾­³£ÔÚ"+area_name[location]+"Ò»´ø×ß¶¯¡£\n");
			
	}
	me -> perform_busy(1);
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	pklocate <Ä³ÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´ËÃüÁîÎª¾íÈë½­ºþ³ðÉ±µÄÍæ¼Ò×¨ÓÃ£¬¿ÉÒÔ´óÖÂÈ·¶¨ÆäËû¾íÈë½­ºþ³ðÉ±µÄ
Íæ¼ÒµÄËùÔÚµØÇø¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

HELP
    );
    return 1;
}
