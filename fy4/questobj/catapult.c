#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( YEL "����" NOR, ({ "slingshot" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 0);
                set("long","һ������ľ����С������\n");
                set("material", "wood");                
        }
	::init_item();
}

void init()	{
	add_action("do_shoot","shoot");
}

int do_shoot(string arg)	{
	object ob;
	object me;
	int dp;
	int damage;
	int i;
	object *inv;
	
	if (this_object()->query("nouse"))  
		return notify_fail(this_object()->name()+"�Ѿ����ˣ�û������\n");
	me=this_player();
	if (!arg) return notify_fail("��Ҫ��˭��\n");
    
    if( environment(me)->query("no_fight") || environment(me)->query("no_magic") 
    	|| environment(me)->query("no_spells"))
		return notify_fail("���ⲻ��͵Ϯ��\n");
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if(inv[i]->query("stone")==1){
		    	ob=present(arg,environment(me));
		    	if (!objectp(ob) || !living(ob)) 
		    		return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ��\n");
	
	    		if (userp(me))
				if (!COMBAT_D->legitimate_kill(me, ob)) {
					if (stringp(ob->query("NO_KILL")))
						return notify_fail(ob->query("NO_KILL"));
					if (stringp(ob->query("NO_PK")))
						return notify_fail(ob->query("NO_PK"));	
					else 
						return notify_fail("���޷��������ˡ�\n");
				}
		    	
		    	this_object()->add("used",1);
		    	if (inv[i]->query_amount()==1){
		    		destruct(inv[i]);
		    	}
		    	else{
		    		inv[i]->add_amount(-1);
		    	}
		    	
	    		message_vision(CYN"\n$N����$n������׼�ǣ����������е�"+this_object()->name()+CYN"��һ��Сʯͷ��쬵�һ�����˳�ȥ��\n",me,ob);
	    		message_vision(HIR"Сʯͷ�Ӻݺݵش���$N���ϣ�ʹ��$N�������졣��\n"NOR,ob);
	    		
	            if (this_object()->query("used") > random(5)+3) {
	    			tell_object(this_player(),this_object()->query("name")+"ž��һ�����ˡ�\n");
	    			this_object()->set("nouse",1);
	    			this_object()->set("name",YEL"���˵ĵ���"NOR);
	    		}
	    		
		    	dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
	    		damage=50000-dp;
	            	damage/=100;
	    		if (damage<0) damage=0;
	    		ob->receive_wound("kee",damage,me);    
	    		ob->receive_wound("gin",damage,me);    
		    	ob->receive_wound("sen",damage,me);    
	    		COMBAT_D->report_status(ob);                                         
	    		ob->kill_ob(me); 
		    	me->perform_busy(2);
			return 1;
		}
	}
	return notify_fail("������û�к��õ�ʯ�ӡ�\n");
}
