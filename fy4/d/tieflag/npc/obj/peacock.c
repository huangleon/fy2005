#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name(GRN"��ȸ��"NOR, ({ "peacock tail","peacock" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����Ƶ�ԲͲ����������ƽ�������������������صİ�����\n");
                set("material", "gold");
                
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
	int dp;
	int damage;
	if (!arg) return notify_fail("��Ҫ��˭��\n");
    	if (query("used")) return notify_fail(this_object()->name()+"ֻ����һ�Ρ�\n");
	me=this_player();
    
    if (me->query_busy())
    	return notify_fail("��������æ��\n");
    	
   	if ( me->query("combat_exp") < 50000 )
		return notify_fail("�㾭��̫���ˣ�û�а취����" + this_object()->name()+"�ķ����ؾ���\n");
   
   	if( environment(me)->query("no_fight") ||
        	environment(me)->query("no_magic") ||
        	environment(me)->query("no_spells"))
			return notify_fail("���ⲻ��͵Ϯ��\n");
    	ob=present(arg,environment(me));
   
   	if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
    
   	if (ob==me)
		return notify_fail("���Լ���\n");
		
    if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
    
   	if (!me->is_fighting(ob)) 
    		message_vision("$N��Цһ�����ӻ�������һ����������\n",me);
    	message_vision("$N����$n���������е�"+this_object()->name()+"...\n",me,ob);
    	message_vision(HIC "��ԲͲ�зų�һƬ��â���ԻͲ��ã������������Ŀ�ȸ��ë...\n"NOR,me);
    	if (ob->query_skill("perception")/10>random(5) || ob->query("no_shot")) 
    		message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n",ob);
    	else {
		    message_vision("��â����$N���ϣ�һ������ʧ�ˡ�\n",ob);
		    ob->receive_damage("kee", 0, me);
			dp = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
		    damage=200000-dp;
		    damage/=100;
		    if (damage<0) damage=0;
		    ob->receive_wound("kee",damage,me);    
		    ob->receive_wound("gin",damage,me);    
		    ob->receive_wound("sen",damage,me);    
    	}
    	COMBAT_D->report_status(ob);                                         
    	ob->kill_ob(me); 
    	set("used",1);
    	me->start_busy(3);
    	return 1;
}
