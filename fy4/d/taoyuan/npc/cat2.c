#include <ansi.h>

#define DROP_CMD "/cmds/std/drop"

inherit NPC;
void create()
{
    set_name("Сè��", ({ "kitten" }) );
    set("nickname",HIW"����ѩ��"NOR);
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "����ѩ�׵�Сè����һ��Сѩ���ڵ��Ϸ�����Ծ��׷����һ����ɫ��С��\n");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��" }) );
    set("redball", 1);
    set("chat_msg", ({
        "Сè���������˼�����\n",
        "Сè����˸�������\n",
        "Сè����צ���������㡣\n",
        (: random_move :)
            }) );
    set("chat_chance", 5);

    set("verbs", ({ "bite","claw" }) );
    set("arrive_msg", "������Ϣ�����˹�����");
    set("leave_msg", "����������һ�������˿�ȥ��");
    setup();
}

int kill_ob(object me)
{
    message_vision("�����$N����С��һ�ܾ�����������������Ӱ��\n",this_object());
    destruct(this_object());
}

int accept_object(object who, object ob)
{
 	object me;
 	
 	me = this_player();
 	
    if(ob->query("marks/catfood"))
    {
        object obj;
//        DROP_CMD->main(this_object(),obj->id());
		message_vision("Сѩ��һ����è�����˹�������ͷ��" + me->name() +
				"���Ϲ��˹�������" + me->name() + "����~~~\n"
				+ "���˼���������" + ob->name() + "\n",this_object());
  		if(ob->name() == "���С��" && query("redball")) {
  			obj = new(__DIR__"obj/redball");
  			if(!objectp(obj)){
  				obj = new(__DIR__"obj/redball1");
  			}
  			obj->move(environment());
  			message_vision("һ����ɫ��С���$N�������������\n", this_object());
     		set("long", "����ѩ�׵�Сè����һ��Сѩ���ڵ��Ϸ�����Ծ�š�\n");
     		set("redball", 0);
     	}
	    return 1;
    }
    return notify_fail(this_object()->name() + "��ͷ������" + ob->name() + "��ת�����˿�ȥ��\n");
}
        
