#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIW"����"NOR, ({ "iceblade"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("long", "һ�ؾ�Ө��͸�ı��⣬ͨ���ף���Ե�����ƿɵ�������ʹ�á�\n");
		set("material", "ice");
		set("ice_blade",1);
	}
	::init_blade(20);
}

int check_status()
{
	object me;
	me=environment();
   	if(	objectp(me) && living(me))
	{	
		// 1~23|27 min
		if (userp(me))
			call_out("dissolve",60+me->query_skill("snowforce",1)*10);
		return 1;
	}
	call_out("dissolve",1);
	return 1;
}

int dissolve()
{
	object holder,room;
	
	if(!objectp(holder=environment())) {
		destruct(this_object());
	}
	
	if(userp(holder))
		room=environment(holder);
	else room=holder;
	message("vision",this_object()->query("name")+"�����Ļ�����һ̲��ˮ��\n",room);
	destruct(this_object());
	return 1;
}


void init()
{
	check_status();
}