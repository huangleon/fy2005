#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
	set_name( RED "ɭ������" NOR, ({ "evil eye" }) );
	set_weight(80);
	if(clonep())
	   set_default_object(__FILE__);
	else{
	set("unit", "��");
	set("long", @LONG
һöѪ�����ʯ��ʯ������ڵ�ͫ�ʣ�������������һ�㡣
LONG);
	set("material", "silver");
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
	}
	::init_item();
}

void init()
{
	add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
	object ob;
	object me;
	string where;
	int dp;
	int damage;
	if (!arg) return notify_fail("��Ҫ��˭��\n");
	me=this_player();
	if( environment(me)->query("no_fight") || environment(me)->query("no_magic") || environment(me)->query("no_spells"))
	return notify_fail("���ⲻ��͵Ϯ��\n");
	ob=present(arg,environment(me));
	if (!objectp(ob) || !living(ob)) 
		return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
    	
    if (userp(me) && me!= ob)
	if (!COMBAT_D->legitimate_kill(me, ob))
	{
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}

	if (me->query("timer/annie_shoot") + 2 > time())
		return notify_fail("��ʧ���ˡ�\n");
	
	message_vision(RED"$N����ɭ�����ۣ�ɲʱ��ܳ�һ��Ѫ��ļ�â����$n��\n"NOR,me,ob);
	ob->receive_damage("kee",13,me); 
	if (ob!=me && !ob->is_fighting(me))	ob->kill_ob(me); 

	if (!random(10))
		me->set("timer/annie_shoot",time());

	return 1;
}


  

