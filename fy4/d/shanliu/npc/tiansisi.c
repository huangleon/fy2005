// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
		set_name("��˿˿", ({ "tian sisi","tian" }) );
		set("gender", "Ů��" );
		set("age", 18);
		set("title",GRN"��С��"NOR);
		set("long",
"��������Ϯ��Զ���ԭ�ϳ����ʯ���ү�Ķ���Ů����Ҳ��Ϊ��ʵ����
����˿˿���˶��������˳�����˵��Ҳ��Ц��������������κ��˴�
��Ը��Ҳ���ܾ̾����κε�Ҫ��\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "��˿˿���ٵü�ֱ���ԹҸ���ƿ�����Žŵ��������ӣ����ƹ�
��˽䡭��,�ֲ�֪��������ȥ�ˣ�\n",
    }) );
		set("combat_exp", 80000);
		set("attitude", "friendly");
		set("per",30);
		set_skill("dodge",100);
        set_skill("unarmed",50);
        set_skill("parry", 50);
		setup();
}

