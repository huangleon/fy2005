// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����ڱ�", ({ "shaobing", "bing" }) );
        set("long",
                "�������ڵ��ڱ�������������С�ǵİ�ȫ��\n");
        set("attitude", "heroism");
	set("vendetta_mark", "authority");
        set("combat_exp", random(5000000));

        set_skill("unarmed", 200);
        set_skill("staff", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);

        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 30+random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
			"�����ڱ��૵����������Ǿ��ĳ��森����\n"
        }) );

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/yjing")->wield();
}


