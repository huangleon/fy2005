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
	string *sname, *mapped,target,cardname,skill_name;
	int i, marry_flag;

	mapping learned_skill_points;
	int skill_level;

	seteuid(getuid());

//	==> implemented to reduce flooding when player only needs to check a single skill level -- by silencer
	if (arg)
	if (sscanf(arg,"-%s",skill_name)==1) {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("¡¸" + skill_name + "¡¹£¬ÓÐÕâÖÖ¼¼ÄÜÂð£¿\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
			return notify_fail("Äã²¢Ã»ÓÐÑ§¹ýÕâÏî¼¼ÄÜ»òÊÇ¼¼ÄÜµÈ¼¶ÎªÁã¡£\n");
		
		learned_skill_points=me->query_learned();
		write( "ÄãÄ¿Ç°Ñ§¹ý£º\n\n");		
		write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n\n", 
				(learned_skill_points[skill_name] >= (skill_level+1) * (skill_level+1)) ? HIM : "", 
				me->query_skill_mapped(skill_name) ? "  ": "£ª",
				SKILL_D(skill_name)->name() + " (" + skill_name + ")",
				skill_level(SKILL_D(skill_name)->type(), skill_level),
				skill_level, 
				learned_skill_points[skill_name],
		));
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
/*	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && ob!=couple_ob
	&& !ob->query("skill_public") )
		return notify_fail("Ö»ÓÐ¹ÜÀí»òÓÐÊ¦Í½/·òÆÞ¹ØÏµµÄÈËÄÜ²ì¿´ËûÈËµÄ¼¼ÄÜ¡£\n");*/

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
Ö¸Áî¸ñÊ½ : 

£¨1£© skills 

²éÑ¯×Ô¼ºËùÑ§¹ýµÄ¼¼ÄÜ¡£

£¨2£© skills [<Ä³ÈË>] 

Ö¸¶¨Ò»¸öºÍÄãÓÐÊ¦Í½/·òÆÞ¹ØÏµµÄ¶ÔÏó£¬¿ÉÒÔ²éÖª¶Ô·½µÄ¼¼ÄÜ×´¿ö¡£

£¨3£© skills -¼¼ÄÜÓ¢ÎÄÃû³Æ

ÔÚ¼õºÅ¡°-¡±ºó¸úÒ»¼¼ÄÜµÄÓ¢ÎÄÃû³Æ£¬½«Ö»ÁÐ³ö¸Ã¼¼ÄÜµÄµÈ¼¶×´¿ö¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
