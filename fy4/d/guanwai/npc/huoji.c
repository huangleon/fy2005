#include <ansi.h>
inherit NPC;

void create()
{
        set_name("С���", ({ "huoji" }) );
        set("title", "��ʱ��æ��");
        set("gender", "����" );
        set("age", 16);
        set("long","����ӥ������̫�ã���ӥ����ר�Ű�æ�ġ�\n");

        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
