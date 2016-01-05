// skills.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 08/08/2001 by Daniel Q. Yu.
//			* Get name from skill itself.			
//
// 		- 9/22/2002 by Silencer
//			* Add -xxxx to enable single skill check.


#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_LEVEL;

string *skill_level_desc = ({
	BLU "³õÑ§Õ§Á·" NOR,
	HIB "´ÖÍ¨Æ¤Ã«" NOR,
	HIB "°ëÉú²»Êì" NOR,
	HIB "ÂíÂí»¢»¢" NOR,
	HIB "¼ÝÇá¾ÍÊì" NOR,
	CYN "³öÀà°ÎÝÍ" NOR,
	CYN "ÉñºõÆä¼¼" NOR,
	CYN "³öÉñÈë»¯" NOR,
	HIC "µÇ·åÔì¼«" NOR,
	HIC "Ò»´ú×ÚÊ¦" NOR,
	HIW "Éî²»¿É²â" NOR
});

string *knowledge_level_desc = ({
	BLU "ÐÂÑ§Õ§ÓÃ" NOR,
	HIB "³õ¿úÃÅ¾¶" NOR,
	HIB "ÂÔÖªÒ»¶þ" NOR,
	HIB "ÂíÂí»¢»¢" NOR,
	HIB "ÒÑÓÐÐ¡³É" NOR,
	CYN "ÐÄÁìÉñ»á" NOR,
	CYN "ÁËÈ»ì¶ÐØ" NOR,
	CYN "»íÈ»¹áÍ¨" NOR,
	HIC "¾ÙÊÀÎÞË«" NOR,
	HIC "Õð¹Åîå½ñ" NOR,
	HIW "Éî²»¿É²â" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob, *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname,skill_name, permit, msg;
	int i, marry_flag, skill_level;
	mapping learned_skill_points;
	int estimate,cost, amount, total, j, my_skill,req_exp;
	string *att_skill = ({ "literate", "unarmed", "force", 
							"foreknowledge", "chanting", "move" });
	mapping exp_data;
							
	seteuid(getuid());

//	==> implemented to reduce flooding when player only needs to check a single skill level -- by silencer
	if (arg)
	if (sscanf(arg,"-%s -%d",skill_name,estimate)==2 
		|| sscanf(arg,"-%s",skill_name)==1) {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("¡¸" + skill_name + "¡¹£¬ÓÐÕâÖÖ¼¼ÄÜÂð£¿\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
				skill_level = 0;
//			return notify_fail("Äã²¢Ã»ÓÐÑ§¹ýÕâÏî¼¼ÄÜ»òÊÇ¼¼ÄÜµÈ¼¶ÎªÁã¡£\n");
		
		learned_skill_points=me->query_learned();
		
//		return notify_fail("ÄãÃ»ÓÐÑ§¹ýÈÎºÎ¼¼ÄÜ£¬»¹²»ÄÜ²ì¿´¼¼ÄÜµÄ¾ßÌåÐÅÏ¢¡£ÏÈÈ¥Ñ§µãÊ²Ã´°É¡£\n");
			
//		write( "ÄãÄ¿Ç°Ñ§¹ý£º\n\n");		
		write(HIG"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);   
		
		if (mapp(learned_skill_points))
		{
			write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n\n", 
					(learned_skill_points[skill_name] >= (skill_level+1) * (skill_level+1)) ? HIM : "", 
					me->query_skill_mapped(skill_name) ? "  ": "£ª",
					SKILL_D(skill_name)->name() + " (" + skill_name + ")",
					skill_level(SKILL_D(skill_name)->type(), skill_level),
					skill_level, 
					learned_skill_points[skill_name],
			));
		} else
			write(sprintf("%s%s\n\n",
					me->query_skill_mapped(skill_name) ? "  ": "£ª",
					SKILL_D(skill_name)->name() + " (" + skill_name + ")")
					);
			
		msg = sprintf("\t¡¾Îä¹¦ÏµÊý¡¿%-6d¡¾ÉËº¦µÈ¼¶¡¿+%-6d¡¾ÃüÖÐµÈ¼¶¡¿+%-6d\n",
				SKILL_D(skill_name)->effective_level(me),
				SKILL_D(skill_name)->damage_level(me),
				SKILL_D(skill_name)->accuracy_level(me));
		msg += sprintf("\t¡¾Ñ§Ï°ÄÑ¶È¡¿%-6d¡¾ÑÐ¾¿ÄÑ¶È¡¿+%-6d¡¾Á·Ï°¼¶Êý¡¿%-6d\n",
				SKILL_D(skill_name)->skill_difficulty(),
				SKILL_D(skill_name)->skill_difficulty_r(),
				SKILL_D(skill_name)->practice_limit());
		
		if (SKILL_D(skill_name)->eff_parry_level()!=SKILL_D(skill_name)->effective_level())
			msg += sprintf("\t¡¾ÕÐ¼ÜÓÐÐ§ÏµÊý¡¿%-6d\n",
				SKILL_D(skill_name)->eff_parry_level());
		if (SKILL_D(skill_name)->bounce_ratio())
			msg += sprintf("\t¡¾½ð¸ÕÀàÓÐÐ§ÏµÊý¡¿%-6d¡¾½ð¸ÕÀà·´µ¯ÏµÊý¡¿%-6d\n",
				SKILL_D(skill_name)->ic_effect(),
				SKILL_D(skill_name)->bounce_ratio());
		write(WHT+msg + "\n"NOR);
		
		// Here a friendly estimation of pot cost
		
		if (mapp(learned_skill_points)){
			j = me->query_skill(skill_name,1);
			if (!estimate|| estimate<=j)	estimate = j+1;
			if (estimate>400)	estimate = 400;
		
			if (me->query_int()<=40)
				amount = (400+30*me->query_int())*2*100;
			else
				amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*100) ;
						
	        if (me->query("national")=="Ãç×å")	
	        	amount = amount + amount/20;	// Ãñ×åÌØÐÔ      	            	    	
	        amount = amount / SKILL_D(skill_name)->skill_difficulty();        	                 	
	       	if( amount < 1) amount = 1;		// ÖÁÉÙ1£º1 
	       	          
	        for (i=j;i<=estimate-1;i++){
	        	total = total + (i+1)*(i+1)+1;
	       	}
	       	total = total - learned_skill_points[skill_name];	
			cost = total*100/amount+1;
			
			my_skill = estimate-1;
			if ( member_array(skill_name, att_skill) == -1)
	    		my_skill = my_skill * SKILL_D(skill_name)->effective_level(me)/100;
	    	else
	    		my_skill = my_skill * 150/100;	
	    	req_exp = my_skill * my_skill * my_skill/10;
			exp_data = exp_to_level(req_exp);
			
			write(sprintf(YEL"¡¾ÉýÖÁµÚ%d¼¶ËùÐèÇ±ÄÜ¡¿%-6d\t¡¾ËùÐè¾­ÑéµÈ¼¶¡¿£Ì%d £¨%d.%d£¥£©\n" NOR,
						estimate,cost,
							exp_data["level"],
				    		exp_data["sub"]/10,
				    		exp_data["sub"]%10,
				    		));
			
			my_skill = estimate-1;
			if ( member_array(skill_name, att_skill) == -1)
	    		my_skill = my_skill * SKILL_D(skill_name)->effective_level(me)/100;
	    	else
	    		my_skill = my_skill;	
	    	req_exp = my_skill * my_skill * my_skill;
			exp_data = exp_to_level(req_exp);
			
			write(sprintf(YEL"¡¾ÔÄ¶ÁÓÐ¹ØÊé¼®ÉýÖÁµÚ%d¼¶ËùÐè¾­ÑéµÈ¼¶¡¿£Ì%d £¨%d.%d£¥£©\n\n" NOR,
							estimate,
							exp_data["level"],
				    		exp_data["sub"]/10,
				    		exp_data["sub"]%10,
				    		));
		}
			
		if (me->query_temp("timer/check_skill_help")+2 < time())
			SKILL_D(skill_name)->help(me);
		me->set_temp("timer/check_skill_help",time());
		
		write(HIG"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);   
		return 1;
	}
	
//	==> single skill check ends.	
	
	
	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄ¼¼ÄÜ£¿\n");
	}
	
	target = (string) me->query("marry");	
	if(stringp(target)) couple_ob = find_player(target);
	
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
		&& !me->is_apprentice_of(ob) && ob!=couple_ob
		&& !ob->query("skill_public") )
//		&& !ob->query("skill_restrict"))
		return notify_fail("Ö»ÓÐ¹ÜÀí»òÓÐÊ¦Í½/·òÆÞ¹ØÏµµÄÈËÄÜ²ì¿´ËûÈËµÄ¼¼ÄÜ¡£\n");

/*	if (stringp(permit = ob->query("skill_restrict"))) {
		if (member_array(permit, me->query("marks/ok_skill")) == -1)
			return notify_fail("Ö»ÓÐ¹ÜÀí»òÓÐÊ¦Í½/·òÆÞ¹ØÏµµÄÈËÄÜ²ì¿´ËûÈËµÄ¼¼ÄÜ¡£\n");	
	}*/

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "Äã" : ob->name()) + "Ä¿Ç°²¢Ã»ÓÐÑ§»áÈÎºÎ¼¼ÄÜ¡£\n");
		return 1;
	}
	write( (ob==me ? "Äã" : ob->name()) +"Ä¿Ç°¹²Ñ§¹ý"+chinese_number(sizeof(skl))+"ÖÖ¼¼ÄÜ£º\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		if(!find_object(SKILL_D(sname[i])) && file_size(SKILL_D(sname[i])+".c")<0) 
		{
			ob->delete_skill(sname[i]);
			write("delete obselete skill " + sname[i] + "\n");
			continue;
		}
		if (ob->prevent_shown(me,sname[i]))	continue;
		write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "", 
				(member_array(sname[i], mapped)==-1? "  ": "£ª"),
				SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], 
				(int)lrn[sname[i]],
		));
	}
	write("\n");
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

string pet_skill(object ob)
{
	string desc;
        object  *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                desc =  ob->name() + "Ä¿Ç°²¢Ã»ÓÐÑ§»áÈÎºÎ¼¼ÄÜ¡£\n";
                return desc;
        }
        	desc =  ob->name() +"Ä¿Ç°ËùÑ§¹ýµÄ¼¼ÄÜ£º\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "£ª"),
                        SKILL_D(sname[i])->name() + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return desc +"\n";
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
[0;1;36mÖ¸Áî¸ñÊ½ :[0;32m 

£¨1£© skills 

²éÑ¯×Ô¼ºËùÑ§¹ýµÄ¼¼ÄÜ¡£

£¨2£© skills [<Ä³ÈË>] 

Ö¸¶¨Ò»¸öºÍÄãÓÐÊ¦Í½/·òÆÞ¹ØÏµµÄ¶ÔÏó£¬¿ÉÒÔ²éÖª¶Ô·½µÄ¼¼ÄÜ×´¿ö¡£

£¨3£© skills -¼¼ÄÜÓ¢ÎÄÃû³Æ

ÔÚ¼õºÅ¡°-¡±ºó¸úÒ»¼¼ÄÜµÄÓ¢ÎÄÃû³Æ£¬½«Ö»ÁÐ³ö¸Ã¼¼ÄÜµÄµÈ¼¶×´¿ö¡£

£¨4£© skills -¼¼ÄÜÓ¢ÎÄÃû³Æ -Êý×Ö

¸ø³öÒ»¸öÉýÖÁµÚ¡°Êý×Ö¡±µÈ¼¶ËùÐèÒªµÄÇ±ÄÜÊý¹ÀËã¡£

ÎªÁË±ÜÃâË¢ÆÁ£¬¼¼ÄÜËù¶ÔÓ¦µÄÌØ¼¼ÐÅÏ¢Ã¿£²ÃëÖÓ×î¶àÏÔÊ¾Ò»´Î

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

¹ØÓÚ¸÷ÏîµÄËµÃ÷

¡¾ÉýÖÁµÚx¼¶ËùÐèÇ±ÄÜ¡¿
¡¾ËùÐè¾­ÑéµÈ¼¶¡¿
¡¾ÔÄ¶ÁÓÐ¹ØÊé¼®ÉýÖÁµÚx¼¶ËùÐè¾­ÑéµÈ¼¶¡¿

ÎªÁË·½±ã´ó¼Ò£¬ÎÒÃÇ¸ù¾ÝÄãµÄÊôÐÔ×´¿ö£¬¸ø³öÒ»¸öÉýµ½ÏÂÒ»¼¶ËùÐè
Ç±ÄÜÊýÁ¿µÄ´óÖÂ¹À¼Æ¡£¶Ô´Ë×÷Ò»Ð©ËµÃ÷£º

£á£®·çÔÆ£²£°£°£µÖÐÑ§Ï°ËùºÄ·ÑµÄÇ±ÄÜÊýÃ»ÓÐËæ»ú°Ú¶¯£¬Õâ¸öÊý×Ö
ÊÇ±È½Ï×¼È·µÄ¹À¼Æ£¬ÓÉÓÚÄã»¨·ÑµÄÇ±ÄÜ²»Í¬£¬ÔÚËÄÉáÎåÈëÊ±»áÓÐÒ»
¶¨²îÒì£¬´Ë¹À¼ÆÊÇ°´ÕÕÃ¿´ÎÊ¹ÓÃ£±£°£°Ç±ÄÜµãµÄ¹«Ê½¼ÆËãµÄ¡£
£¨¾ßÌå²Î¼û£è£å£ì£ð¡¡£ì£å£á£ò£îµÄËµÃ÷£©

£â£®´Ë¹ÀËãÊÇ°´ÕÕÄãµ±Ç°²ÅÖÇ¡¢Ãñ×å¡¢ÒÔ¼°µ±Ç°¼¼ÄÜµÈ¼¶Ëù¶ÔÓ¦µÄ
Ñ§Ï°ÄÑ¶ÈËù¼ÆËãµÄ£¬Èç¹ûÄãµÄ²ÅÖÇ¡¢»òÕß¸Ã¼¼ÄÜµÄÑ§Ï°ÄÑ¶ÈÒÔºó±ä
¶¯ÁË£¬Ôò´ËÊý×ÖÒ²½«±ä¶¯¡£

£ã£®¶ÁÊéÊ¶×Ö£¨literate£©Ç£Éæµ½²ÅÖÇµÄÌá¸ß£¬ËùÒÔÆäÊµ¼ÊËùÐèµÄ
±ÈÏÔÊ¾µÄÒªÉÙºÜ¶à¡£
[1;31m
£ä£®ËùÓÐºÄ·ÑµÄÇ±ÄÜµãÖ»ÔÚµ±Ç°µÈ¼¶ÓÐÐ§£¬¼´Ê¹ÏµÍ³ÏÔÊ¾ÐèÒª20000
µãÉýÖÁµÚ£±£°£°¼¶£¬Èç¹ûÄãÏÖÔÚÖ»ÓÐ£²£°¼¶£¬Ò»´ÎÓÃÈ¥20000µãÒ²Ö»
ÄÜÉýµ½µÚ£²£±¼¶£¬¶ø²»»áÖ±½ÓÉýµ½µÚ£±£°£°¼¶¡£É÷Ö®£¡£¡£¡
[0;32m

¡¾Îä¹¦ÏµÊý¡¿¼¼ÄÜÖ÷Òª²ÎÊý£¬¾ö¶¨¸ÃÎä¹¦ÔÚÄ³Ò»¾­Ñé¶Î¿ÉÒÔÑ§µ½µÄ
×î¸ßµÈ¼¶¡£Îä¹¦ÏµÊýºÍÎä¹¦µÈ¼¶ÊÇ¾ö¶¨Îä¹¦µÄÃüÖÐÂÊµÄÁ½´óÖ÷ÒªÒòËØ¡£

¡¾ÉËº¦µÈ¼¶¡¿ÐÞÊÎÎä¹¦µÄÉËº¦ÂÊ£¬ÉËº¦Á¦Ò»°ãÈ¡¾öÓÚÄãµÄÁ¦Á¿¡¢¼ÓÁ¦
£¨enforce£©¡¢ÎäÆ÷¡¢Ïà¶Ô¾­ÑéµÈ¼¶µÈ£¬¡¾ÉËº¦µÈ¼¶¡¿¶ÔÇ°Á½¸öÒòËØ
¼Ó³É¡£100Ïàµ±ÓÚÀ´Ô´ÓÚÁ¦Á¿ºÍ¼ÓÁ¦µÄÉËº¦Á¦Ôö´ó10£¥¡£

¡¾ÃüÖÐµÈ¼¶¡¿ÀàËÆÓÚÉÏÒ»Ïî£¬¶ÔÎä¹¦ÃüÖÐÂÊµÄ¼Ó³É£¬Á½¸öÆäËûÍêÈ«
ÏàÍ¬µÄ¼¼ÄÜ£¬ÃüÖÐµÈ¼¶£²£°£°µÄ±ÈÃüÖÐµÈ¼¶£°µÄÃüÖÐÂÊ¸ß£²£°£¥

¡¾Ñ§Ï°ÄÑ¶È¡¿²Î¿´ÃüÁî£ì£å£á£ò£îµÄ¹«Ê½ËµÃ÷

¡¾ÑÐ¾¿ÄÑ¶È¡¿Ò»°ãÀ´Ëµ£¬ÑÐ¾¿£¨£ò£å£ó£å£á£ò£ã£è£©ËùÐèÇ±ÄÜÊýÎªÆÕ
Í¨Ñ§Ï°ËùÐèµÄ£²£°±¶£¬ÑÐ¾¿ÄÑ¶ÈÊÇÔÚ´Ë»ù´¡ÉÏµÄ¼ÓÈ¨¡£

¡¾Á·Ï°¼¶Êý¡¿¸Ã¼¼ÄÜÄÜ¹»Á·Ï°£¨£ð£ò£á£ã£ô£é£ã£å£©µ½µÄ×î¸ßµÈ¼¶¡£

¡¾ÕÐ¼ÜÓÐÐ§ÏµÊý¡¿Ò»°ãÀ´Ëµ£¬¡¾Îä¹¦ÏµÊý¡¿±ãÊÇ¼¼ÄÜµÄÕÐ¼ÜÏµÊý£¬Î¨
ÓÐÒ»Ð©ÌØ¶¨µÄÎä¹¦»áÓÐ×¨ÃÅµÄÕÐ¼ÜÏµÊý¡£

¡¾½ð¸ÕÀàÓÐÐ§ÏµÊý¡¿¶ÔÌú²¼ÉÀÀàÎä¹¦×÷ÓÃÓÚ»¤¼×µÄÐÞÊÎ£¬ÏµÊýÔ½¸ß£¬
»¤¼××÷ÓÃ¾ÍÔ½Ã÷ÏÔ¡£

¡¾½ð¸ÕÀà·´µ¯ÏµÊý¡¿ÓÃÀ´¼ÆËãÌú²¼ÉÀÀàÎä¹¦µÄ·´µ¯ÉËº¦Á¦¡£


[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
