#include <ansi.h>
inherit NPC;
object cart;

void create()
{
//	string *name = ({"��","��","ɽ","��"});
        set_name("����", ({"guard"}) );
        set("gender", "����" );
        set("title", "������");
        set("long", "����һλ���������������𸮰�ȫ�͸���Ѳ�ӵġ�\n");
 	set("attitude", "friendly");
	set("age", 25+random(5));
        set("gender", "����" );
	set("cor", 20);
	set("cps", 25);
        set("combat_exp", random(30000)+75000);
        set_skill("unarmed", 60+random(30));
        set_skill("parry", 60+random(30));
        set_skill("dodge", 60+random(30));
        set_skill("move", 60+random(30));
        set("chat_chance", 1);
        set("chat_msg", ({
           "�������������������˵��ÿ�����\n",
        }) );
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
		"�������󺰵����������ˣ����˽��������ˡ���\n",
    	}) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();       
}
