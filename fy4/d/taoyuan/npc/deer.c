#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("С¹", ({ "little deer", "deer", "xiao lu"}) );
    set("race", "Ұ��");
    set("age", 5);
    set("long", "һͷǳǳ��ë���ϴ��Ű�ɫ�ߵ��С¹��\n");
    set("max_kee", 120);
    set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
    set("verbs", ({ "bite" }) );
	set("chat_chance", 5);
	set("chat_msg", ({
		"С¹��ͷ���ỹ����¶ˮ����ݡ�\n",
		"С¹�����㣬ë���׵�ͷ����Ĺ��˹��㣬�ƺ�������Ҫ�Ե����ӡ�\n",
		"С¹���е��������ǻ���\n",
		}) );
    set_skill("dodge", 100);
	set("combat_exp", 100);

    setup();
}


int accept_object(object who, object ob)
{
	object deer, me, obj;
	
	me = this_player();
	deer = this_object();
	
    if(ob->query("marks/deerfood"))
    {
		message("vision", deer->name() + "��ͷ���������е�" + ob->name() + "��ͷһ��Ͱ�"
				+ ob->name() + "��������\n", me);
		message("vision", deer->name() + "�߹�ȥ��ͷ����" + me-> name() + 
				"���е�" + ob->name() + "��ͷһ��Ͱ�\n"
				+ ob->name() + "��������\n", environment(), me);
		if(random(10)<3) {
			message_vision(YEL"$N��ͷ��$n�����ϲ��˲䣬һ����ë����������\n"NOR, 
					this_object(), me);
		    obj = new(__DIR__"obj/hair");
		    obj->move(environment());
		}
        return 1;
    }
    message("vision", deer->name() + "���˹�ȥ����ͷ������" + me->name() + "���е�" 
    		+ ob->name() + "��ת�����˿�ȥ��\n", environment(), me);
    return notify_fail(deer->name() + "���˹�������ͷ�����������е�" 
    		+ ob->name() + "��ת�����˿�ȥ��\n");
}