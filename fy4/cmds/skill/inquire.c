// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;

string getdam(object me, object obj);
string *skill_level_desc = ({
	BLU "³õÑ§Õ§Á·" NOR,
	HIB "´ÖÍ¨Æ¤Ã«" NOR,
	HIB "°ëÉú²»Êì" NOR,
	HIB "ÂíÂí»¢»¢" NOR,
	HIB "¼İÇá¾ÍÊì" NOR,
	CYN "³öÀà°ÎİÍ" NOR,
	CYN "ÉñºõÆä¼¼" NOR,
	CYN "³öÉñÈë»¯" NOR,
	HIC "µÇ·åÔì¼«" NOR,
	HIC "Ò»´ú×ÚÊ¦" NOR,
	HIW "Éî²»¿É²â" NOR
});

string *knowledge_level_desc = ({
	BLU "ĞÂÑ§Õ§ÓÃ" NOR,
	HIB "³õ¿úÃÅ¾¶" NOR,
	HIB "ÂÔÖªÒ»¶ş" NOR,
	HIB "ÂíÂí»¢»¢" NOR,
	HIB "ÒÑÓĞĞ¡³É" NOR,
	CYN "ĞÄÁìÉñ»á" NOR,
	CYN "ÁËÈ»ì¶ĞØ" NOR,
	CYN "»íÈ»¹áÍ¨" NOR,
	HIC "¾ÙÊÀÎŞË«" NOR,
	HIC "Õğ¹Åîå½ñ" NOR,
	HIW "Éî²»¿É²â" NOR
});
mapping area_name = ([ 
		"baiyun"	:	"°×ÔÆ³Ç",
		"bat"		:	"òùòğµº",
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
		"fycycle"	:  	"·çÔÆÍâ³Ç",
		"fywall"	:   "·çÔÆ³Ç",
		"ghost"		:    "ÓÄÁéÉ½×¯",
		"guanwai"	:  	"¹ØÍâ",
		"guanyin"	:  	"Ìì·ã",
		"huangshan"	:	"»ÆÉ½",
		"huashan"	:  	"»ªÉ½",
		"jinan"		:    "¼ÃÄÏ",
		"laowu"		:    "ÀÏÎİ",
		"libie"		:    "ÎŞÃûĞ¡Õò",
		"loulan"	:   "Â¥À¼",
		"manglin"	:  	"Ã§ÁÖ",
		"oldpine"	:  	"ÀÏËÉÕ¯",
		"palace"	:   "µÛÍõ¹È",
		"qianfo"	:   "Ç§·ğÉ½",
		"qianjin"	:  	"Ç§½ğÂ¥",
		"qingping"	: 	"ÇåÆ½É½×¯",
		"quicksand"	:	"´óÉ³Ä®",
		"resort"	:   "ÌúÑ©É½×¯",
		"shaolin"	:  	"ÉÙÁÖËÂ",
		"shenshui"	: 	"ÉñË®¹¬",
		"songshan"	: 	"áÔÉ½",
		"taiping"	:  	"Ì«Æ½Õò",
		"taishan"	:  	"Ì©É½",
		"taoguan"	:  	"ÌÒÔ´",
		"taoyuan"	:  	"ÈıÇå¹Û",
		"tieflag"	:  	"´óÆì¹È",
		"wanmei"	:   "ÍòÃ·É½×¯",
		"wolfmount"	:	"ÀÇÉ½",
		"wudang"	:   "Îäµ±",
		"xiangsi"	: 	"ÏàË¼Áë",
		"xinjiang"	: 	"ĞÂ½®",
		"yingou"	:   "Òø¹³¶Ä·»",
		"zhaoze"	:	"ÕÓÔóµØ",
		"zangbei"	:	"²Ø±±",
]);                             
string *heavy_level_desc= ({
	"¼«Çá",
	"ºÜÇá",
	"²»ÖØ",
	"²»Çá",
	"ºÜÖØ",
	"¼«ÖØ"	
});



string skill_level(string, int);
int main(object me, string arg)
{                               
	object ob, man, *all    ;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp, skill;             
	int i, cost;            
	object room;            
	string location,*area,line;
	mapping my;        
	                        
	                        
        seteuid(getuid());      
        skill=me->query_skill("begging",1);
        
                         
//	check requirement            
	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}                       
                                
        if (me->query("class")!="beggar")
		return notify_fail("Ö»ÓĞØ¤°ïµÜ×Ó²ÅÄÜ´òÌ½±ğÈËµÄÏûÏ¢£¡\n");
	
	if (skill<50)
		return notify_fail("ÄãµÄÆòÌÖÖ®Êõ²»¹»¸ßÉî£¨Ğè¸ßÓÚ50£©\n");
	
	if ( !objectp(man) )    
		return notify_fail("ÖÜÎ§Ã»ÈËÄÜ°ïÄãÈ¥´òÌ½±ğÈËµÄÏûÏ¢£¡\n");

	if (arg==("monster nian"))
		return notify_fail("»î¶¯NPCÎŞ·¨´òÌı¡£\n");

	if ( !arg )             
		return notify_fail("ÄãÒª´òÌıË­µÄÏûÏ¢£¿\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) 
		return notify_fail("ÄãÒª´òÌıË­µÄÏûÏ¢£¿\n");
	if ( wizardp(ob))
			return notify_fail("ÄãÒª´òÌıË­µÄÏûÏ¢£¿\n");
	if ( ob == me )         
		return notify_fail("ÇëÊäÈëÖ¸Áî£ó£ë£é£ì£ì£ó\n");
        if ( present(ob, environment(me)) )
                return notify_fail("ÄãÒª´òÌıµÄÈË¾ÍÔÚÕâ¶ù£¡\n");
	cost = me->query("max_gin")/(me->query_skill("begging",1)/10 + 1);
	if ( me->query("gin") <= cost )
		return notify_fail("ÏÖÔÚÄãÌ«ÀÛÁË£¬ÎŞ·¨È¥´òÌı±ğÈËµÄÏûÏ¢¡£\n");
	if (me->is_busy())
		return notify_fail("ÄãÏÖÔÚÕıÃ¦¡£\n");
		
//	start inquire
	tell_object(me, "Äã¾ö¶¨Ïò" + man->name() + "´òÌı¹ØÓÚ" + ob->name() + "µÄÏûÏ¢¡£\n\n");
	message("vision", "Ö»¼û" + me->name() + "½»Í·½Ó¶úµØ¸ú" + man->name() + "Ëµ×Å»°£¬ºÃÏóÔÚ´òÌıĞ©Ê²Ã´¡£\n\n", 
		environment(me), ({ me, man }) );
	sp = me->query_skill("begging")*10 + me->query("kar")*5 + me->query("gin") + man->query("gin");
	dp = ob->query("kar")*10 + ob->query("gin")*3;
		me->receive_damage("gin", cost );
	if ( random(sp) < random(dp) || wizardp(ob))
		return notify_fail( man->name() + "Ò¡ÁËÒ¡Í·£¬ËµµÀ£ºÕâÊÂÎÒ¿É²»Çå³ş£¬"
		 	+ RANK_D->query_respect(me) + "»¹ÊÇÈ¥Ïò±ğÈË´òÌıÒ»ÏÂ°É£¡\n");

	write(YEL"\n"+man->name()+YEL"ÇÄÇÄµØ¸æËßÄã£º\n\n"NOR);
//	basic information inquiry
	my = ob->query_entire_dbase();
	
	line = ob->query("title")?ob->query("title"):"";
	line += sprintf("    %s£¬%s£¬%s£¬%sËê£¬",
		ob->query("name"),
		(ob->query("national")? ob->query("national") : "±¾µØÉú"),
		ob->query("gender"),
		chinese_number(ob->query("age")));
	
	if ( my["marry"] || my["divorced"]) {
        	if (my["marry"]) {
        		line += (ob->query("gender") == "Å®ĞÔ" ? "¼ŞÓë":"È¢ÆŞ")
        			+ my["marry_name"]+ "(" + my["marry"] +")¡£\n";  		
        	}
        	else
        		line += "ÏÖ" + (ob->query("gender") == "Å®ĞÔ" ? "¹Ñ¾Ó¡£":"÷¤¾Ó¡£");
	}
	else
		line += "ÉĞÎ´»éÅä¡£";
		
	if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line += sprintf("°İÊ¦%s¡£",
                                my["family"]["master_name"] );
        }
        
        if (userp(ob)) {
        if (my["PKS"]>80) line += "\n"+ob->name()+"Ğ×ºİ¼«¶ñ£¬ÊÈÉ±³ÉĞÔ¡£";
        	else if (my["PKS"]>40) line+="\n"+ob->name()+"ÊÑÓÂºÃ¶·£¬¶àÉËÈËÃü¡£";
        	else if (my["PKS"]>10) line+="\n"+ob->name()+"Å¼ÓĞÁÓ¼££¬È´ÎŞ¶ñĞĞ¡£";
        		else line += "\n"+ob->name()+"ÉúĞÔÉÆÁ¼£¬¿íºñÈİÈÃ¡£";
        } else line +="\n";
        	
	write (line);


//	skill inquiry	
	
	if (skill<100) 
		write ("´òÌ½²»³ö´ËÈËµÄÎä¹¦¾³½ç¡£\n");
	else {	
		skl = ob->query_skills();
		if(!sizeof(skl)) {
			write("´ËÈË³öÊÖ"+getdam(me,ob)+"£¬Ê²Ã´¶¼²»»á£¡\n");
		} else {
			write("´ËÈË³öÊÖ"+getdam(me,ob)+"£¬ËùÉÃ³¤µÄ¼¼ÄÜÖ®Ò»ÊÇ£º\n");
			sname  = sort_array( keys(skl), (: strcmp :) );
			map = ob->query_skill_map();
			if( mapp(map) ) mapped = values(map);
			if( !mapped ) mapped = ({});
			lrn = ob->query_learned();
			if( !mapp(lrn) ) lrn = ([]);
			i = random(sizeof(skl));
			printf("%s%s%-40s" NOR " - %-10s \n", 
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				(member_array(sname[i], mapped)==-1? "  ": "¡õ"),
				SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			);
			write("\n");
		}
	}
	
//	location inquiry, for player, it's area only
	
	if (skill<150) 
		write("´òÌ½²»³ö´ËÈË¾­³£³öÃ»µÄµØÇø¡£\n\n\n");
	else {
		room=environment(ob);
		area=keys(area_name);
		if (!room) 
			write("²»Çå³şÔÚÄÄÀï¿ÉÒÔÕÒµ½"+ob->name()+"¡£\n\n\n");
		else {
			location=domain_file(file_name(room));
			if (member_array(location,area)==-1)	
				write("²»Çå³şÔÚÄÄÀï¿ÉÒÔÕÒµ½"+ob->name()+"¡£\n\n\n");
			else if (skill<250)
				write(ob->name()+"ºÃÏñ×î½ü¾­³£ÔÚ"+area_name[location]+"Ò»´ø×ß¶¯¡£\n\n\n");
			else 	
				write(ob->name()+"ºÃÏñ×î½üÔøÔÚ"+area_name[location]+room->query("short")+"³öÏÖ¡£\n\n\n");
		}	
	}
	me -> perform_busy(2);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

string getdam(object me, object obj) {	
	int str, level, max_str, max_level;
	
	max_str = 120;
	max_level = sizeof(heavy_level_desc) - 1;
	
	str = obj->query_str();
	level = str * max_level / max_str;
	level = level > max_level ? max_level : level; 
	return heavy_level_desc[level];
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	inquire <Ä³ÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄã´òÌı±ğÈËµÄÏûÏ¢¡£´ËÃüÁîÎªØ¤°ïµÜ×Ó×¨ÓÃ£¬
²¢ĞèÑ§Ï°ÆòÌÖÖ®Êõ¡£¼¼ÄÜµÈ¼¶Ô½¸ß£¬µÃµ½µÄĞÅÏ¢¾ÍÔ½¶à£¬¿É
ÒÔÁË½â¶Ô·½µÄÉíÊÀ£¬Îä¹¦ÉîÇ³£¬¼¼ÄÜÖÖÀà£¬ÉõÖÁ¿ÉÒÔÖªÏş¶Ô
·½µÄ´óÖÂÎ»ÖÃ¡££¨ÖÁÉÙĞèÒª£µ£°¼¶ÆòÌÖÖ®Êõ£©

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

HELP
    );
    return 1;
}
