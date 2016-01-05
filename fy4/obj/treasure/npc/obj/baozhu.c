#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIR "����" NOR, ({ "bao zhu" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",YEL"��ʱ�ڽ��ջ�ϲ���գ��û����񣬱ϰ�������������ɽ��\n����ν֮������\n"NOR);
                //set("material", "silver");
                set("no_split", 1);
                set("desc_ext","ʹ��(use)");
                set("value",600);
        }
        ::init_item();
}

void init()
{
	add_action("do_shoot","use");
}

int do_shoot(string arg)
{
	object ob;
	object me;
	string where;
	//int dp;
	int damage;
	if (!arg) return notify_fail("����ըʲô��\n");
	if (query("used")) return notify_fail(this_object()->name()+"�Ѿ������ˡ�\n");
	me=this_player();
    	if ( me->query("combat_exp") < 100000 )
		return notify_fail("�㾭��̫���ˣ�û�а취����" + this_object()->name()+"���ؾ���\n");
    	if( environment(me)->query("no_fight") || environment(me)->query("no_magic") || environment(me)->query("no_spells"))
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
	
	if (arg != "monster nian")
		return notify_fail("ֻ�������Ը����ޡ�\n");
		
	if (ob->query("kee") < 8000000 || ob->query("gin") < 8000000 || ob->query("sen") < 8000000)
		return notify_fail("��ֻ�����Ѿ������ˡ�\n");
		
    	message_vision(HIW"$N��ȼ�����е�"+this_object()->name()+HIW"˳�Ƴ�Ŀ�����˹�ȥ������\n"NOR,me);
    	if (ob!=me)
    		message_vision(HIW"$N�����ӳ���"+this_object()->name()+HIW"�����Ѻ����һ����⡣��������\n",me,ob);
    	else {
    		message("vision",HIW""+me->name()+HIW"�����Լ��ӳ���"+this_object()->name()+HIW"�����Ѻ����һ����⡣��������\n"NOR,environment(me),me);
    		tell_object(me,HIW"������Լ��ӳ���"+this_object()->name()+HIW"�����Ѻ����һ����⡣��������\n"NOR);
    	}
    	    
    	where=file_name(environment(ob));
    	if (!userp(ob) && where[0..6]=="/d/cave") {
    		message_vision(YEL"$N��Ц��:�����С��Ҳ�������������������Ū,��ү���ö��ˣ�\n"NOR,ob);
    		message_vision(YEL"$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�����������Ҷ��\n\n"NOR,ob);
    	} else {		
    		if (ob->query_skill("perception")/10>random(22) || ob->query("no_shot")) {
    			if (me!=ob) message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�����������Ҷ��\n\n",ob);
    			else {
    				message("vision",me->name()+"������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�����������Ҷ��\n\n",environment(me),me);
    				tell_object(me,"��������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�����������Ҷ��\n\n");
    			}	
    		}else {
    			message_vision(HIR"���"HIW"��$N"HIW"����������\n\n"NOR,ob);
    			//dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    			damage=8975000;
    			//damage/=100;
    			if (damage<0) damage=0;
    			ob->receive_wound("kee",damage,me);    
    			ob->receive_wound("gin",damage,me);    
    			ob->receive_wound("sen",damage,me);    
		}	
    	}	
    	COMBAT_D->report_status(ob);                                         
    	if (ob!=me)	ob->kill_ob(me); 
    	set("used",1);
    	if (me->query_busy()<3) me->start_busy(3);
    	destruct(this_object());
    	return 1;
}