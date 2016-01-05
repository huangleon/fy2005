#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
	string msg;
	int duration;
	
	if(me->query("class")!="yinshi")
		return notify_fail("ֻ�е����ȵ��Ӳ����¹���\n");
	
        if((int)me->query_skill("celecurse",1) < 150 )
                return notify_fail("����Ҫ150��ͨ�콵��\n");

	duration = me->query("timer/ghostcurse")-time()+ 300; // 5mins
        if (duration>0)
        	return notify_fail("���ķ����ܼ�����Ҫ��Ϣ"+(int)(duration/60+1)+"���ӡ�\n");
	
	if(me->query("kee") < 100 )
		return notify_fail("����Ҫ�ķ�100����Ѫ��\n");
		
	write("�����˭�Ļꣿ");
	input_to( (: call_other, __FILE__, "select_target", me :));
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
                write("��ֹ�лꡣ\n");
                return;
        }

        ob = find_living(name);
	room = environment(me);
	me->receive_wound("kee",100);
	me->set_temp("last_damage_from","�½�ͷ���������ˡ�\n");
        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)|| ob->is_ghost()
        	|| ob->query("no_curse") || ob->query("boss")){
		write("���޷����ܵ�����˵���ꡣ\n");
		return; 
	}
        
        msg = HIW "$N˫������һ�ӣ�һ��Ũ��ӵ��¾����������\n" ;
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
		new1->set("combat_exp", (new1->query("combat_exp"))*11/10);
		new1->set("chat_chance",0);
		new1->set("inquiry",0);
		new1->set("ghostcurse",1);
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
		new1->set("title",HIB "�л�"NOR);
		msg +=  "Ũ���ƺ���$N��߽�����Ũ����һ����Ӱ��������\n" NOR;
		new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 300);
		me->set("timer/ghostcurse",time());
	}
	else
		msg += "Ũ��������ʧ�ˡ�����\n"NOR;
	message_vision(msg, me);
}

void melt(object ob)
{
	message_vision(WHT"$N�������黯����ʧ�ˡ�����\n"NOR,ob);
	destruct(ob);
}

