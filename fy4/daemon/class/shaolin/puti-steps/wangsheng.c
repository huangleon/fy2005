// Silencer @ FY4 workgroup. Oct.2004
//	ghostcurse every 5min

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill,duration;
    	    	
    	if (me->query("class")!="shaolin")  
     		return notify_fail("Ψ�����ָ�ɮ����ʹ�á���;������\n");
     		    	
    	skill = me->query_skill("puti-steps", 1);
		if(skill < 150 || me->query_skill("zen",1)<140) 
			return notify_fail("����;������������Ҫ150��������ղ�����140��������\n");
	 
    	duration = me->query("timer/wangsheng")-time()+ 300; // 5mins
        if (duration>0)
        	return notify_fail("����;�������ķ����ܼ�����Ҫ��Ϣ"+(int)(duration/60+1)+"���ӡ�\n");
        	
        if( (int)me->query("force") < 400 )     
    		return notify_fail("����;��������Ҫ�ķ�400��������\n");
    	if (userp(me))	me->add("force", -400);
	      		
     	write("������������Ķ������֣�");
	input_to( (: call_other, __FILE__, "select_target", me :));
	
	me->perform_busy(2);
	return 1;
}

void select_target(object me, string name)
{
	mapping ob_list;
        object ob,new1;
	string msg;
	object room;
	string *list;
	object *inv;
	int i,HERE = 0;
        if( !name || name=="" ) {
                write("�о�ֹͣ��\n");
                return;
        }

        ob = find_living(name);
	room = environment(me);
	me->receive_wound("kee",100);
	me->set_temp("last_damage_from","������������ˡ�\n");

        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)|| ob->is_ghost()
        	|| ob->query("no_curse") || ob->query("boss")){
		write("���޷����ܵ�����˵�������\n");
		return; 
	}
        
        msg = HIW "$N˫Ŀ�ʹ�������ׯ�أ�����ǰ�����������˺���������ʮ�̳�����֮�䣺
����ǰ���� �����������ǡ� ���ʺ����¡� ����������  ��\n" ;
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
		new1->set("ghostcurse",1);
		new1->be_ghost(1);
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
		new1->set("title",HIB "���"NOR);
		msg +=  WHT"\n�����յ��ϰ������ƣ�����������һ����Ӱ��\n" NOR;
		new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 300);
		me->set("timer/wangsheng",time());
	}
	else
		msg += WHT"\n���ܾ����ĵģ�ʲôҲû�з�����\n"NOR;
	message_vision(msg, me);
}

void melt(object ob)
{
	message_vision(WHT"$N�������黯����ʧ�ˡ�����\n"NOR,ob);
	destruct(ob);
}