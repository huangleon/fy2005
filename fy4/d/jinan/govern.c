#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "·çÔÆÑÃÃÅ");
        set("long", @LONG
ÕâÀïÊÇ³¯Í¢ËùÉè£¬¸½½ü³ÇÀïµÄ¾À·×¶¼¿ÉÒÔÔÚÕâÀïÉÏ×´ÇëÇó´¦Àí¡£´óÌüÄÏÊ×Ò»ÕÅ
¾íéÜÄ¾°¸£¬°¸ÉÏÓĞ¸öĞ¡ÖñÍ°£¬ÀïÃæ²å×Å¼¸¸ùÓĞÖª¸®¹ÙÓ¡µÄÖñÇ©¡£Ä¾°¸ºóµÄÌ«Ê¦ÒÎÉÏ
ÆÌ×ÅÑ©ÈŞÆ¤£¬ÒÎºóÆÁ·çÉÏºìÈÕÇàÔÆÍ¼¡£ÉÏĞü½ğ±ßØÒ£º
[0;1;33m
				Ã÷²ìÇïºÁ
[0m
LONG
        );
    	set("exits", ([ /* sizeof() == 4 */
        	"north" : __DIR__"street5",
        	"south" : __DIR__"shufang",
        	"west" : __DIR__"w_xiangfang",
        	"east" : __DIR__"e_xiangfang",
    	]));
    	set("objects", ([
		__DIR__"npc/yayi0" : 1,
        	__DIR__"npc/yayi1" : 2,
        	__DIR__"npc/yayi" : 2,
        	__DIR__"npc/yayi2" : 2,
    	]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}

/*
void init()
{
	object xing;
	mixed *current_time;
	
	add_action("do_arrest","arrest");	
	if (!interactive(this_player()))	return ;
		
	current_time=NATURE_D->get_current_time();
	if(xing=present("xing rui",this_object()))
	{
		if(current_time[5]<480||current_time[5]>1200)
		{
			message_vision(CYN"ĞÏÈñºöÈ»ÓĞÈç´óÃÎ³õĞÑÒ»°ã£¬ËµµÀ£º¡°Ô­À´¶¼ÕâÃ´Ò¹ÁË£¬ÊÇ»Ø¼ÒµÄÊ±ºòÁË¡£¡±\n"NOR,xing);
			message_vision(CYN"ĞÏÈñÂıÂıµÄ×ßÁË³öÈ¥¡£\n"NOR,xing);
			destruct(xing);
		}
		else if(current_time[5]>1080)
		{
			message_vision(CYN"ĞÏÈñÅÄÅÄ¼ç°òËµµÀ£º¡°Ì«ÍíÁË£¬ÓĞÊÂÃ÷ÌìÔÙÀ´°É¡£¡±\n"NOR,xing);
			message_vision(CYN"ĞÏÈñ×ÔÑÔ×ÔÓïµÀ£º¡°È¥ºÍ½­Ê¦Ò¯ºÈÁ½ÖÑ°É¡£¡±×ªÉíÀë¿ª¡£\n"NOR,xing);
			destruct(xing);
		}
	}
	else
		if(current_time[5]>480&&current_time[5]<960)
		{
			xing=new(__DIR__"npc/xing");
			xing->move(this_object());
			message_vision(YEL"ĞÏÈñµÍÉùµÄËµµÀ£º¡°Éı¡«¡«¡«¡«ÌÃ¡«¡«¡«¡«¡±\n"NOR,xing);
		}
	
}

int do_arrest(string arg)
{
	
	object me, target,xing;
	int exp, stra,leader,factor,mysen;
	if(!arg)
		return notify_fail("ÄãÒªÏÂÁî¼©ÄÃË­£¿\n");
	me = this_player();
	if((string) me->query("class") != "official" )
		return notify_fail("Äã²»ÊÇ³¯Í¢¹ÙÔ±£¬²»¿É¼©ÄÃÒÉ·¸£¡\n");
	if (me->query("marks/¹Ù¸®/ÔÀ·É"))
        	return notify_fail("ÄãÊÇÖ¸»ÓÇ§¾üÍòÂíµÄ´ó½«£¬×¥·¸ÈËµÄÊÂ»¹ÊÇÁô¸ø¹ÜÂÉ·¨µÄ¹ÙÔ±È¥×ö°É¡£\n");
	
	xing = present("xing rui",this_object());
	
	if(!xing ) 
		return notify_fail("×Ü²¶Í·²»ÔÚ£¬ÎŞ·¨ÏÂÁî¾Ğ²¶·¸ÈË¡£\n");
	mysen=(int) me->query("sen");
	if( mysen< 150 )
		return notify_fail("ÄãµÄĞÄÉñ²»¹»£¡ÎŞ·¨ÏÂ¾Ğ²¶µÄÃüÁî¡£\n");	
	if (me->is_busy())
		return notify_fail("ÄãÏÖÔÚÃ»¿Õ£¡£¡\n");
	
	if(!objectp(target = find_living(arg)))
		return notify_fail("ĞÏ×Ü²¶Í·¶ÔÄãËµµÀ£º¡°Ğ¡ÈËÎŞÄÜ£¬Ã»ÓĞ¹ØÓÚÕâ¸öÈËµÄÏßË÷£¬ÎŞ·¨¾Ğ²¶¡£¡±\n");
	if( !userp(target) && !environment(target))
		return notify_fail("ĞÏ×Ü²¶Í·¶ÔÄãËµµÀ£º¡°Ğ¡ÈËÃ÷²ì°µ·Ã£¬´ËÈËËÆºõÒÑÇ±·üÆğÀ´ÁË£¬ÕÒ²»µ½ÏßË÷£¬µÈĞ©Ê±ºòÔÙËµ°É¡£¡±\n");
	if( userp(target) || !environment(target))
		return notify_fail("ĞÏ×Ü²¶Í·¶ÔÄãËµµÀ£º¡°ÇëË¡Ğ¡ÈË¶àÑÔ£¬´ËÈË²¢ÎŞ¹ı·¸£¬»¹ÊÇµÃÈÄÈË´¦ÇÒÈÄÈË°É¡£¡±\n");
	if( target->query("no_arrest") )
		return notify_fail("ĞÏ×Ü²¶Í·Ì¾ÁË¿ÚÆøËµ£º¡°´ËÈËËùÔÚÖ®´¦²»Êô¹Ù¸®¹ÜÏ½·¶Î§£¬ÓĞĞÄÇÜÔô£¬ÎŞÁ¦»ØÌì°¡¡£¡±\n");
	if (target->is_fighting())
		return notify_fail("ĞÏ×Ü²¶Í·³ÁË¼Æ¬¿ÌËµ£º´ËÈËÒÑ¾­ÓĞ³ğ¼ÒÕÒÉÏÃÅÁË£¬ÎÒÃÇÇÒ¾²¹ÛÆä±ä¡£\n");
	if (target->is_vendor()|| target->query("fly_target"))
		return notify_fail("ĞÏ×Ü²¶Í·ÄÑÎªµØËµ£º¾Ğ²¶´ËÈË²»ÄÑ£¬Ö»ÊÇ¿ÖÅÂ»áÓĞĞí¶à²»±ãÖ®´¦¡£\n");
	if (environment(target)==this_object())
		return notify_fail("ĞÏ×Ü²¶Í·µÃÒâµØËµ£ºĞ¡ÈËÒÑ¾­°Ñ´ËÈË¾ĞÄÃ¹é°¸ÁË¡£\n");		
		
	mysen=mysen*3/100;
	me->add("sen",-mysen);
	
	message_vision("$N´óÉùÏÂÁîµÀ£ºÀ´ÈËÄÇ£®£®°Ñ$n¸øÎÒÄÃÀ´£¡£¡\n",me,target);
	message_vision("$NËµµÀ£º¡°²¶¿ìºÎÔÚ£¿»¹²»¿ìÈ¥Ö´ĞĞ"+me->query("name")+"´óÈËµÄÃüÁî£¡£¡¡£\n",xing);
	
	exp = (int) target->query("combat_exp");
	stra = (int) me->query_skill("strategy",1);
	leader = (int) me->query_skill("leadership",1);
	factor = stra * stra / 10 * leader / 10 * leader / 10;
	factor += ((int) me->query("combat_exp") - 2000 )/1000;			
	if( random(factor) <= exp) {
		me->start_busy(3);
		return notify_fail("ĞÏ×Ü²¶Í·¶ÔÄãËµµÀ£º¡°Ğ¡ÈËÎŞÄÜ£¬ÈÃ"+target->query("name")+"ÌÓÍÑÁË£¡\n");
	}
	
	me->start_busy(2);
	call_out("gethim",5,target,me);
	return 1;
}

int gethim(object target,object me)
{
	if(!target || !me ) return 1;
	if (target->is_fighting()) {
		tell_object(me,"ĞÏ×Ü²¶Í·¶ÔÄãËµµÀ£º¡°Ğ¡ÈËÎŞÄÜ£¬ÈÃ"+target->query("name")+"ÌÓÍÑÁË£¡\n");
		return 1;
	}
	if(environment(me) == this_object())
	{
        message_vision("ºöÈ»Ò»Èº²¶¿ì³åÁË¹ıÀ´£¬¶ş»°²»Ëµ¾Í½«$Nîí×ßÁË¡£\n",target);
        target->move(this_object());
        message_vision("$N±»¹Ù±øÑºÁË½øÀ´¡£\n",target);
	if(me){
	me->kill_ob(target);
	target->kill_ob(me);
	target->start_busy(3);
		}
        return 1;
	}
	return 1;
}

valid_leave(object me,string dir)
{
	object xing;
	
	if((dir =="south" || dir == "west") && me->query("class")!="official"
		&&xing=present("xing rui",this_object()))
		return notify_fail("ĞÏÈñ¶ÔÄãºÈµÀ£º¡°²»µÃÉÃ´³»úÒªÖØµØ£¡£¡¡±\n");
	return 1;
}


void reset(){
	object *inv, *npc;
	int num, i;
	string id;
	inv = all_inventory(this_object());
	npc = filter_array(inv,(: living($1) && !userp($1):));
	num = sizeof(npc);
	for (i=0; i<num; i++) {
		id = npc[i]->query("id");
		if ( npc[i]->is_corpse() || id =="yayi"
			|| id=="chaiyi" ||  id == "xing rui"
			|| !npc[i]->query("startroom")) continue;
//		npc[i]->ccommand("say ÈøÓĞÄÉÀ­£¡£¡");
		npc[i]->return_home(npc[i]->query("startroom"));
	}
	:: reset();
}

*/		