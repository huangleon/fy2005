#include <ansi.h>
inherit NPC;

void create()
{
//	string *name = ({"һ","��"});
        set_name("���", ({"guard"}) );
        set("gender", "����" );
        set("title", "�𸮼Ҷ�");
        set("long", "����һλ�𸮼Ҷ����������𸮰�ȫ�͸���Ѳ�ӵġ�\n");
 	set("attitude", "friendly");
	set("age", 25+random(5));
        set("gender", "����" );
	set("cor", 20);
	set("cps", 25);
	set("force",100);
	set("max_force",100);
	set("force_factor",20);
        set("combat_exp", random(100000)+160000);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
           "�𸮼Ҷ�������˧���ҵ����˶�����ɽ�����Ǿ���ƴ����ҲҪ��������\n",
        }) );

        setup();

        carry_object(__DIR__"obj/cloth")->wear();       
}
