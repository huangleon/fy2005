#include <ansi.h>

inherit NPC;
void create()
{
    set_name("�����", ({ "big monkey", "�����", "monkey" }) );
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "����ӵ�ë�Ѿ���ɻҰ�ɫ�����Ӹ����ƺ��������¡����һ�顣\n");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��" }) );
    set("chat_msg", ({
        "����������ڶ�����ץ��ץ��\n",
        "������������㿴����֪����Щʲ�����⡣\n",
    }) );
    set("chat_chance", 1);
    set("verbs", ({ "bite","claw" }) );
    setup();
}


        
