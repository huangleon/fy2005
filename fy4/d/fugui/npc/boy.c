inherit NPC;
#include <ansi.h>

void create()
{
	set_name("С���",({ "boy" }) );
	set("nickname", HIG"��ͷ����"NOR);
        set("gender", "����" );
        set("age", 12);
        set("long", "������÷����С��ܣ���������С�裬һЦ�ұ������ϱ�¶��������\n��С���ѣ����ڲ�ƺ���Ĵ��ı�����ץ�ź�����\n\n");
	set("combat_exp", 5000);
	set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("force", 20);
        set("int", 15);
        set("chat_chance", 1);
        set("chat_msg", ({
                "С���˵������������ô�����йɾ�ζ�����Ķ��أ���ô�Ҳ����أ�\n\n",
        }) );
     
        set("attitude", "friendly");
        
        setup();
        carry_object(__DIR__"obj/underwear")->wear();
        carry_object(__DIR__"obj/tigershoes")->wear();
}
