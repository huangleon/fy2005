// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����", ({ "fang yufei", "fang" }) );
        set("long","�����ӷ�����������ķ����ϰ��С���ӣ��Ժ��ζ�������ͨ��\n");
        set("attitude", "heroism");
		set("title", HIW "������"NOR);
		set("per", 30);
        set("combat_exp", 300000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        
        set_temp("apply/move", 100);

        setup();
        carry_object(__DIR__"obj/yincloth")->wear();
}
