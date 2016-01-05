// // Silencer @ FY4 workgroup. Oct.2004
#include <ansi.h>

int perform(object me, object target)
{
    	int skill,duration;
    	    	
    	if (me->query("class")!="knight")  
     		return notify_fail("Ψ�п���ֵ��Ӳ���ʹ�á�ʧ������\n");
     		    	
    	skill = me->query_skill("dream-herb", 1);
		if(skill < 180) 
		return notify_fail("��ʧ������������Ҫ180�������廨����\n");
	 
    	duration = me->query("timer/shimeng")-time()+ 300; // 5mins
        if (duration>0)
        	return notify_fail("��ʧ�������ķ����ܼ�����Ҫ��Ϣ"+(int)(duration/60+1)+"���ӡ�\n");
        	     		
     	write("������ʧ�����Ķ������֣�");
		input_to( (: call_other, __FILE__, "select_target", me :));
	
		me->perform_busy(2);
		return 1;
}

void select_target(object me, string name)
{
	mapping ob_list;
        object ob,new1;
	string msg, cname;
	object room;
	string *list;
	object *inv, corpse;
	int i,HERE = 0;
        if( !name || name=="" ) {
                write("ʧ����ֹͣ��\n");
                return;
        }

        ob = find_living(name);
		room = environment(me);

        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)|| ob->is_ghost()
        	|| ob->query("no_curse") || ob->query("boss")){
			tell_object(me,"���޷����ܵ����˵�������\n");
			return; 
		}
        
        inv = all_inventory(room);
        for (i=0;i<sizeof(inv);i++)
        {
        	if(!inv[i]->is_corpse()) continue;
        	if(inv[i]->query("victim_id")!= name) continue;
        	corpse = inv[i];
        }
        
        if (!corpse)
        {
        	tell_object(me, "����ʬ���޴棬�޷�ʹ��ʧ������\n");
        	return;
        }
        
        if( (int)me->query("force") < 400 ) {     
    		tell_object(me,"��ʧ��������Ҫ�ķ�400��������\n");
    		return;
    	}
    	if (userp(me))	me->add("force", -400);
        
        cname = corpse->query("name");
        
        msg = HIG "$N"HIG"˫�ּ��㣬�شطɳ��������̣���"+cname+"��Ҫ��֮���������ƣ����һ������ ��\n" ;
    	if( ob_list = room->query("objects"))	{
		list = keys(ob_list);
		for(i=0;i<sizeof(list);i++)
			if(list[i] == base_name(ob) || list[i] == base_name(ob)+".c")
				{	HERE=1;
					break;
				}
		}
		
	if(HERE && random(10) >0 
		&& ob->query("combat_exp")<= me->query("combat_exp")*12/10
		&& ob->query("combat_exp")>= me->query("combat_exp")* 8/10
	) 
	{
		seteuid(geteuid(me));
		new1 = new(base_name(ob));
		new1->be_ghost(1);
		new1->set("ghostcurse",1);
		new1->set("combat_exp", (new1->query("combat_exp"))*11/10);
		inv = all_inventory(new1);
		for(i=0;i<sizeof(inv);i++)
		{
			if (inv[i]->query("money_id"))	
			{
				destruct(inv[i]);
				continue;
			}
			inv[i]->set("ghostcurse_item",1);
		}
			
		new1->move(room);	
		new1->set("title",HIG "ҩ��"NOR);
		msg +=  WHT"\n"+cname+"��ʬ��鴤�˼��£���Ȼ�λ����Ƶ�վ��������\n" NOR;
		new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 300);
		me->set("timer/shimeng",time());
		destruct(corpse);
	}
	else
		msg += WHT"\n"+ cname+"��ʬ��鴤�˼��£��ֲ������ˡ�\n"NOR;
	message_vision(msg, me);
}


void melt(object ob)
{
	message_vision(WHT"$N��Ȼ��ϡ���̱���ڵ�,����һ̲Ѫˮ����\n"NOR,ob);
	destruct(ob);
}