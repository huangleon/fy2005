#include <ansi.h>  
inherit ITEM;

void create()
{
set_name(HIY"�����ͺ�ɢ"NOR, ({ "hehesan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long","������������ӯ�Ĳɻ���������ӵĶ�����ҩ�������ã������磩�ڱ������ϡ�\n");
        }
        ::init_item();
}
void init()
{
	add_action("do_yong","yong");
}

int do_yong(string arg)
{
	object ob;
	object me;
	int dp,gs;
	int damage;
	me=this_player();
	
	if(me->is_busy()) return notify_fail("����æ���ء�\n");
	
	if (!arg) return notify_fail("��Ҫ����˭���ϣ�\n");
    
    if ( me->query("combat_exp") < 80000 )
		return notify_fail("�㾭��̫���ˣ�����"+this_object()->name()+"�����������˺��Լ��ġ�\n");
	
	ob=present(arg,environment(me));
	if (ob==me) return notify_fail("��Ҫ����?\n");
    
    if( environment(me)->query("no_fight"))	return notify_fail("�����ﲻ�������������\n");
    
    if (!objectp(ob) || !living(ob)) return notify_fail("ֻ�ܶԻ������ʹ�á�\n");
	
	if (userp(me) && me!= ob)
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ҩ��\n");
	}
	
	tell_object(me,"�����������ͺ�ɢ����"+ob->query("name")+"���ϡ�\n");
	if ( random(3*me->query("combat_exp")) > ob->query("combat_exp") 
			&& !ob->query("boss")) {
            if (ob->query_skill("perception")/10>random(15))
			{
				message_vision(HIR"$N��$n�������ͺ�ɢ����ͼ��������!$N��ͷһ�������ͺ�ɢ�������Լ����ϡ���\n"NOR,me,ob);
				message_vision(RED "$Nֻ��������ȣ�������Ѭ�������Ѷ���ȫ���ƺ���ֱҪը��һ����\n"NOR,me);
				if(!me->query_condition("hehe"))
					me->apply_condition("hehe",random(3)+3);
				destruct(this_object());

			}else
			{
				message_vision(RED "$Nֻ��������ȣ�������Ѭ�������Ѷ���ȫ���ƺ���ֱҪը��һ����\n"NOR,ob);
				if(!ob->query_condition("hehe"))
                    ob->apply_condition("hehe",random(5)+5);
				destruct(this_object());
			}
     }	else {
       	tell_object(me,"�㱻������!\n");
       	message_vision(HIR"$N��$n�������ͺ�ɢ����ͼ��������!"NOR,me,ob);
       	ob->kill_ob(me);
       	me->kill_ob(ob);
       	destruct(this_object());
    }
    
    me->start_busy(3);       
	return 1;
}
