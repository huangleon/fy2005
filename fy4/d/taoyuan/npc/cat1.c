#include <ansi.h>

inherit NPC;
void create()
{
    set_name("Сè��", ({ "kitten" }) );
    set("nickname",YEL"��"HIW"��"NOR"���");
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "����һֻ�ư�����Сè�䣬�����ڲݴ�����Ū���۲ݡ�\n");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��" }) );
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
    message_vision("�����$Nһ�ܾ�����������������Ӱ��\n",this_object());
    destruct(this_object());
}

int accept_object(object who, object ob)
{
    if(ob->query("marks/catfood"))
    {
        message_vision(sprintf(
            "$N���˹�������������ְ�%s�����ˡ�\n", ob->name()),this_object());
        return 1;
    }
	return notify_fail("Сè��ͷ�����ᣬת�����˿�ȥ��\n");
}
        
