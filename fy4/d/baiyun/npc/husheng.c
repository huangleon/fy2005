#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "husheng" }) );
        set("long","һ���ֳ���������������ͣ¶���п��Ц�ݡ�\n");
        set("attitude", "heroism");
        set("per", 10);

        set("combat_exp", 20000);

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move", 100);

        set("chat_chance", 1);
        set("chat_msg", ({
        	"����ͻȻ�����һЦ��\n",
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
