#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("С��", ({ "fishgirl" }) );
        set("gender", "Ů��");
        set("age", 23);
        set("title", "���Ů��");
	set("long","����һ�����ں�̲�ϲ�����������ҹ��\n");
        set("chat_chance", 1);
        set("chat_msg", 
           ({
"С��ݸ��һЦ�����������ˣ�׼��������ඡ�\n ",
"С����ɳ̲�ϱı�������Ц�����ż񵽵�С���ǣ�С���ݡ���\n",
            }) );
    set("combat_exp", 5000);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
