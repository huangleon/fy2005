#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object wolf, *enemy;
	int summonwolf, exp, cost, hate, i, guard, duration, timer;
	        
    if ((string)me->query("class") != "wolfmount")
		return notify_fail("Ö»ÓĞÀÇÉ½µÜ×Ó²Å¿ÉÒÔÇıÀÇÖúÕó¡£\n");
        
    summonwolf = (int)me->query_skill("summonwolf",1);
	if(summonwolf < 20 )
    		return notify_fail("»½ÀÇÖÁÉÙĞèÒª20¼¶µÄ»½ÀÇÖ®Êõ£¡\n");   
        
    timer = 40;
	duration = me->query("timer/alert")-time() + timer - F_ABILITY->check_ability(me,"xiao_add");
    if ( duration >0)
		return notify_fail("Äã»¹ĞèÒªµÈ´ı"+(int)(duration)+"ÃëÖÓ×óÓÒ²ÅÄÜÔÙ´Î»½ÀÇ£¡\n");
		
    if (me->is_busy() )
        	return notify_fail("ÄãÏÖÔÚÕıÃ¦£¬ÎŞ·¨ÇıÀÇÖúÕó¡£\n");
    
    if(!me->is_fighting() )
        	return notify_fail("ºÃÏóÃ»ÓĞÈËÒªÉ±Äã£¡\n");
        	
	if (ANNIE_D->check_buff(me,"lockfield") >= 1)
	{
		tell_object(me,YEL"ÄãÕÅ¿ÚÓûĞ¥£¬È´Í»È»·¢ÏÖ·¢²»³öÒ»µãÉùÒô¡£\n"NOR);
		return 0;
	}
			
	if(me->query_temp("max_guard"))
        return notify_fail("¸½½üµÄÀÇÒÑ¾­±»Äã½ĞÍêÁË¡£\n");
             
	if (summonwolf<100)	cost = 80;
		else	cost = 80 + (summonwolf-80)/3;		
	if(me->query("sen")< cost ||me->query("gin") < cost)
		return notify_fail("ÄãµÄ¾«Éñ×´¿öÌ«²îÁË£¬¿ÖÅÂÎŞ·¨ÓĞĞ§µÄÇıÀÇÖúÕó¡£\n");
	me->receive_damage("sen",cost);
	me->receive_damage("gin",cost);
	
	if (summonwolf > 200)	summonwolf = 200;	// capped
		
	seteuid(getuid());
	wolf= new("/obj/npc/wolf");
	me->add_temp("max_guard",1);
	wolf->move(environment(me));
    wolf->invocation(me, (summonwolf));
    wolf->set("possessed", me);

	if (summonwolf<50)
		wolf->set_name("ÔÓÃ«¶ñÀÇ",({ "wolf" }));
	else if (summonwolf<75)
		wolf->set_name(WHT"»ÒÃ«¶ñÀÇ"NOR,({ "wolf" }));
	else if (summonwolf<100)
    	wolf->set_name(YEL"»ÆÃ«¶ñÀÇ"NOR,({ "wolf" }));
	else if (summonwolf<150)
        wolf->set_name(RED"ºìÃ«¶ñÀÇ"NOR,({ "wolf" }));
	else if (summonwolf<200)
		wolf->set_name(HIW"°×Ã«¶ñÀÇ"NOR,({ "wolf" }));
    else if (summonwolf<250)
     	wolf->set_name(HIR"³àÃ«¶ñÀÇ"NOR,({ "wolf" }));
	else 
		wolf->set_name(HIY"½ğÃ«ÀÇÍõ"NOR,({ "wolf" }));

    me->set("timer/alert",time());
                
    if (wolf)
    {       
	    enemy = me->query_enemy();
	    if (enemy)
	    for (i=0;i<sizeof(enemy);i++)
	    {
	       	hate = enemy[i]->query_hate(me);
	       	enemy[i]->add_hate(wolf, summonwolf + hate);     	
	    }   	
       	message_vision(HIB "\n$NÑöÌìÀÇº¿¡°ÎØ¡«à»¡«¡«£¬ÎØ¡«à»¡±£¬¶ÙÊ±ÂşÉ½±éÒ°ÈºÀÇÆëÏø¡£\n" NOR, me);	
    	message_vision( "\n\n$N¶ñºİºİµØÆËÁËÉÏÀ´¡£\n" , wolf);
    }
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	Ö¸Áî¸ñÊ½£ºxiao[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Ö¸Áî¸ñÊ½£ºxiao
 
ÀÇÉ½µÜ×ÓÃ¿¶şÊ®¸ö»ØºÏ¿É»½ÀÇÀ´×ªÒÆµĞÈË×¢ÒâÁ¦£¬ÖÁÉÙĞèÒª20¼¶»½ÀÇÊõ¡£
»½³öµÄÀÇ³öÏÖºó½«¾ßÓĞ±ÈÖ÷ÈËÂÔ¸ßµÄÔ÷ºŞÖµ£¬ÓëÖ÷ÈË²¢¼çÕ½¶·10¸ö»ØºÏºó
ÏûÊ§¡£ºô³öÀÇµÄÇ¿ÈõÈ¡¾öÓÚ»½ÀÇÖ®ÊõµÄ¼¶±ğ¡¢ÀÇµÄÊôĞÔÓëÖ÷ÈËÏàËÆ£¬µ«Æø
Ñª½Ï²î¡£»½ÀÇ²»ÄÜÔÚ×ÔÎÒÃ¦ÂÒÊ±½øĞĞ£¬Í¬Ê±½«ÏûºÄÒ»¶¨µÄĞÄÉñºÍ¾«Á¦¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m    
HELP
    );
    return 1;
}
