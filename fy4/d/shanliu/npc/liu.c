// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("�����", ({ "liu fenggu","liu" }) );
	set("gender", "����" );
	set("age", 35);
	set("title",HIC"���ϵ�һ����"NOR);
	set("long",
"һ�����졢Ӣ���������������ˣ������������������еĿ��������˱�Ȼ�ǽ��ϵ�һ��������ǡ�\n" );
        set("chat_chance", 1);
        set("chat_msg", ({
            "����Ǻ޺޵ص���ɽ�������˵�����˭��Ϊʲô�ҷѾ��Ļ�Ѱ���˴�����û��������\n",
    }) );
	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("per",1);
	set("str", 50);
	set("force",2000);
	set("max_force",2000);
	set("force_factor",50);
	set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        setup();
	carry_object("/obj/armor/cloth")->wear();

}

