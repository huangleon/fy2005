// buy.c
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string *name, item, targ;
	object ob, owner, buyer;
	int i,num;
	mapping goods;
	
	if( me->is_busy())
		return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓÐÍê³É£¬²»ÄÜ²ì¿´ÎïÆ·¡£\n");
		
	if( !arg || sscanf(arg, "%d from %s", num, targ)!=2 )
		return notify_fail("Ö¸Áî¸ñÊ½£ºsample <ÎïÆ·ÐòÁÐºÅ> from <Ä³ÈË>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("ÄãÒª´ÓË­ÄÇ¶ù²ì¿´ÑùÆ·£¿\n");

	if (!(owner->is_vendor())) 
		return notify_fail("´ËÈË²»×öÂòÂô£¬Ã»¶«Î÷¿É²ì¿´¡£\n");

	// ÕâÀïÎÒÃÇÔö¼ÓÒ»¸ö¿Éµ÷ÓÃµÄÅÐ¶Ï£¬±ÈÈçËµÄã¿ÉÒÔÉèÍíÉÏ²»¿ªÃÅÁË£¬ÐÄÇé²»ºÃ²»×öÉúÒâÁË¡£¡£¡£¡£
	if (!owner->legit_buyer(me))
		return notify_fail(owner->name()+"²»Ô¸ÒâÓëÄã×ö½»Ò×¡£\n");
	
	
	if( !mapp(goods = owner->query("vendor_goods")) ) 
		return notify_fail("Õâ¶ù»¹Ã»½ø»õ¡£\n");
	
	name = keys(goods);
	if(!sizeof(name))
		return notify_fail("Õâ¶ùµÄ¶«Î÷È«Âô¹âÁË¡£\n");
	
	if ( num > sizeof(name) || num <= 0 )
		return notify_fail("Ã»ÓÐÕâ¸ö±àºÅµÄÎïÆ·¡£\n");
	
	if (me->query_temp("timer/sample")+2 > time())
		return notify_fail(owner->name()+"¶ÑÐ¦µÀ£º¡°¿Í¹ÙÉÔºò£¬ÂíÉÏ¾ÍÀ´ÕÐºô£¡¡±\n");
	me->set_temp("timer/sample",time());
	
	num = num - 1;
		
	ob = new (name[num]);
	if (!objectp(ob))
		return notify_fail("Õâ¸ö¶«Î÷ºÃÏñ³öÁËµãÎÊÌâ£¬¿ìµã±¨¸æÎ×Ê¦°É¡£\n");	
	
	buyer = this_player();
	buyer->set_temp("checking_goods",1);
	"/cmds/std/look"->look_item(buyer,ob);
	buyer->delete_temp("checking_goods");	
	destruct(ob);
	
		
	return 1;
	
	
}

int help(object me)
{
   write( @HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	sample <Ä³ÎïÆ·ÐòºÅ> from <someone>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÕâÒ»Ö¸ÁîÈÃÄã¿ÉÒÔ´ÓÉÌ··ÄÇÀï²ì¿´»õÎïµÄÐÅÏ¢¡£

ÊÇ²»ÊÇ»¹ÔÚÎª´ó·çÍèºÍ»¢¹ÇÍèµ½µ×ÓÐÊ²Ã´ÓÃ´¦·¢³î£¿
ÊÇ²»ÊÇ»¹ÔÚÓÉÓÚÊÇ·ñÓ¦¸ÃÍ¶×Ê¹ºÂòÒ»¼þ°º¹óµÄÎïÆ·£¿
´ËÃüÁîÈÃÄãÔÚ¹ºÂòÇ°²ì¿´»õÎïµÄÐÅÏ¢¡£

ÆäÖÐ£¬ÎïÆ·ÐòºÅÎª¡°list¡±µÄÊ±ºòÎïÆ·Ç°ÃæµÄ±àºÅ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

HELP
   );
   return 1;
}
