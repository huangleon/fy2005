#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ϹϾ�", ({ "pumpkin gnome","gnome" }) );
        set("race", "Ұ��");
        set("age", 0);
        set("long", "һ��ԲԲ�ģ�Ӳ���Ĵ��Ϲ�\n");
        set("limbs", ({ "����", "���", "�Ҳ�" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 1000);
		set("combat_exp", 3000);
    	set("chat_chance",100);
    	set("chat_msg",({
		(: random_move() :),
    	}) );  
		set("arrive_msg", "ҡҡ�λεع��˹�����");
		set("leave_msg", "��µ��µ�ع����ˡ�");
        setup();
}


void die()
{
	object ob=new("/d/death/npc/obj/pumpkin");
	int n;
	object owner;
	
	owner = query("ol");
	
	if (owner)
	{
		owner->add_temp("annie_quest/halloween_done",1);
		if (owner->query_temp("annie_quest/halloween")
			-owner->query_temp("annie_quest/halloween_done")>0) {
			n = owner->query_temp("annie_quest/halloween")- owner->query_temp("annie_quest/halloween_done");			
			owner->set("quest/short", CYN"���������ϹϾ�����ʣ��"+ n +"��"NOR);
		
		}
		else {
			owner->set("quest/short", CYN"��ȥ������豨����(end)"NOR);
			owner->set("quest/duration",300);
			owner->set("quest_time",time());
		}
	}

	ob->set("value",0);
	ob->move(environment());
	message_vision(YEL"\n�ϹϾ�������һ��ֽУ�������˴��Ϲϡ�\n"NOR, this_object());
	destruct(this_object());
	return;
}