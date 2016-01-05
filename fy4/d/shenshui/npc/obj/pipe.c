#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIM "����" NOR, ({ "romance" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("no_drop",1);
				set("long", "
�ⶫ����ˮ�켧�ӻƽ���͵�����ģ�ԭ������ʴ�Ļ��ǽ��ú�ɥ�Ż�
ˮ�켧�����ֳ��ֲ��������͸ĸ����ε����ֽС����¡���Ů���ӵ����£�
ר�Ÿ������ž��鲻��ĵ��ӷ����ã�����������ÿͲ����ʹ�����Σ�
�����Ψ��ˮ�켧�������½����ظ�ԭ������ò�����ˣ����꽭����һ
������ֹ����Ͳ��ɥ���������ϡ�
�˰�����ɱ�������Ů����ء�
\n");
                set("material", "silver");
                set("ss_shui",1);
                set("ammo", 10);
        }
        ::init_item();
}

void init()
{
		add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
		object ob, target, me;
		string msg;	
		int damage;
		
		if (!arg) return notify_fail("��Ҫ��˭��\n");
		if (query("ammo")<1) 
				return notify_fail(this_object()->name()+"�Ѿ������ˡ�\n");
	
		me=this_player();
    	
    	if (me->query("timer/ss_heart") + 300 > time())
    			return notify_fail(this_object()->name()+"�ո�ʹ�ù����������ڻظ��С�\n");
    		
    	if( environment(me)->query("no_fight")
    		 || environment(me)->query("no_magic") 
    		 || environment(me)->query("no_spells"))
    		 return notify_fail("���ⲻ��͵Ϯ��\n");
    	
    	ob=present(arg,environment(me));
    	if (!objectp(ob) || !living(ob)) 
    		return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
    	
    	if (userp(me) && me!= ob)
		if (!COMBAT_D->legitimate_kill(me, ob)) {
			if (stringp(ob->query("NO_KILL")))
				return notify_fail(ob->query("NO_KILL"));
			if (stringp(ob->query("NO_PK")))
				return notify_fail(ob->query("NO_PK"));	
			else 
				return notify_fail("���޷��������ˡ�\n");
		}
		
		if (me->is_busy())
				return notify_fail("��������æ��\n");
	
		if (!me->is_fighting(ob))
				return notify_fail( this_object()->name()+ "����������ģ��ɲ���ȥ�������ˡ�\n");
			
    	if (ob == me)
    		return notify_fail("СС��;��Լ�������\n");
    	
    	damage = 100 + me->query_skill("nine-moon-spirit",1)* 5; 
    	if (damage > 600) damage = 600;	// ppl would de-level :D    	
    	
    	message_vision(HIW"\n$N"HIW"�����һЦ������ƮƮ�������ȴͻȻ��һ�����ߣ��������������\n"NOR,me,ob);
    	me->set("timer/ss_heart",time());
    	
    	target = ob;
    	
    	if (COMBAT_D->do_busy_attack(me, target, "nine-moon-claw/weiwoduzun","unarmed", 500, 10))
    	{
    	   	msg = WHT"$n⧲��������ҽ�һ�������˸����ţ�\n" NOR;
        	damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
        	target->receive_wound("kee", damage, me);
        	message_vision(msg, me, target);
        	COMBAT_D->report_status(target,0);
    	}
    	else {
    		msg = CYN"$n��ͷһ�������һ��΢�죬����ɫ�Ļ���ӷ���������\n";
			message_vision(msg, me, target);
		}
    		
    	ob->kill_ob(me); 
	   	add("ammo",-1-random(2));
    	me->perform_busy(3);
    	return 1;
}
