#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "zhang longzi", "zhang","longzi" }) );
        set("long","һ�����ո߳��Ĳ�ЬƤ����\n");
        set("attitude", "heroism");
        set("title", "��Ƥ��");

        set("combat_exp", 220000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("dagger", 150);
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 30);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"�������������Դ����������С��������ȥ�ˣ�\n",
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/skinblade")->wield();
}
