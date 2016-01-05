//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, object target)
{
	object *ob;
	int skill, iron, duration;
	mapping buff;
	string msg;
	
	if (me->query("class")!= "lama")
		return notify_fail("Ö»ÓÐ´óÕÑµÜ×Ó²ÅÄÜÐû¡ºÃ÷×ð»¤Éí¡»\n");
		
	if (me->query_skill_mapped("force")!="bolomiduo")
		return notify_fail("¡ºÃ÷×ð»¤Éí¡»ÊÇÆÅÂÜÃÛ¶àÐÄ¾­µÄÌØÊâ¹¦ÄÜ¡£\n");
	skill = me->query_skill("bolomiduo",1);
	if (skill < 160)
		return notify_fail("¡ºÃ÷×ð»¤Éí¡»ÐèÒª160¼¶ÆÅÂÜÃÛ¶àÐÄ¾­ºÍ150¼¶½ð¸Õ²»»µ¹¦¡£\n");
	
	iron = me->query_skill("jin-gang",1);
	if (iron < 150)
		return notify_fail("¡ºÃ÷×ð»¤Éí¡»ÐèÒª160¼¶ÆÅÂÜÃÛ¶àÐÄ¾­ºÍ150¼¶½ð¸Õ²»»µ¹¦¡£\n");
		
	if (ANNIE_D->check_buff(me,"invul"))
		return notify_fail("ÄãÒÑ¾­ÔÚÊ¹ÓÃÀàËÆµÄÎä¹¦ÁË¡£\n");
		
	duration = me->query("timer/pfm/dz_roar")-time() + 1800 - F_ABILITY->check_ability(me,"mz_add")* 60;     
	if (duration>0)
      	return notify_fail("Äã»¹ÐèÒªµÈ´ý"+(int)(duration/60+1)+"·ÖÖÓ×óÓÒ²ÅÄÜÔÙ´ÎÊ¹ÓÃ¡ºÃ÷×ð»¤Éí¡»¡£\n");
		
	if( !me->is_fighting() )
		return notify_fail("¡ºÃ÷×ð»¤Éí¡»Ö»ÄÜÔÚÕ½¶·ÖÐÊ¹ÓÃ¡£\n");
	
	me->set("timer/pfm/dz_roar",time());
	
	msg = BRED + HIY "$NÓÒÊÖÖ¸Ìì£¬×óÊÖÖ¸µØ£¬ÈÆÐÐÆß²½£¬Æø³Áµ¤Ìï£¬ÃÍÈ»Ó½³öµÍ³ÁÓÐÁ¦µÄ·ðºÅ£¬\n";
	msg += BRED + HIY"¡º††¡¡‡¶¡¡‡Ó¡¡ÚÓ¡¡ÄÂ¡»£¬·ðÒôÕ§Âä£¬ÃæÉ¢½ð¹â£¬ÉíÕÖÏ¼ÄÞ£¡\n\n"NOR;
	
	buff = 
		([
			"caster":me,
			"who":me,
			"type":"invul",
			"att":"bless",
			"name":"ÆÅÂÜÃÛ¶àÐÄ¾­¡¤Ã÷×ð»¤Éí",
			"time":	20,
			"buff_msg":msg,
			"buff1": "resistance/kee",
			"buff1_c":100,
			"buff2": "pfm/dz_roar",
			"buff2_c": 1,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	roar[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÎÞÄÏ·ðºÅÊÇ´óÕÑ¸ßÉ®µÄ×¨ÓÃÖ¸Áî£¬ÆÅÂÞÃÛ¶àÐÄ¾­Óë½ð¸Õ²»»µ¹¦Á¶ÖÁ¼«ÖÂ£¬
Ò»Éù¶ÏºÈ£¬Èç½ð·ð¸½Ìå£¬ÈË²»¿ÉÉË¡£´ËÊ½¼«ºÄÔªÆø£¬Ã¿30·ÖÖÓÊ¹ÓÃÒ»´Î£¬
Ã¿´ÎÑÓÐø20ÃëÖÓ£¬ÆÚ¼ä²»ÊÜÆøÑªÉËº¦¡£ÐèÒª160¼¶ÆÅÂÞÃÛ¶àÐÄ¾­ºÍ150¼¶
½ð¸Õ²»»µ¹¦¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}