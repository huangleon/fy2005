// (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
int tell_him();
void create()
{
    	set_name("�׹���", ({ "mi gonggong","mi","gonggong" }) );
    	set("gender", "����" );
    	set("long","�׹�������͢��һ����̫�࣬����ϸƤ���⣬�����ü��á�\n");
    	set("age", 65);
    	set("combat_exp", 7000);
    	set("attitude", "friendly");
    	set("per",30);
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"�׹�����ü����Ԭ���ʱ���ѵ������ǿ������ɡ�\n",
        	"�׹���Ц���е�˵��һ�������ʮ�꣬С�ط����Ǿ�ģ����\n",
            }) );
    	set("NO_KILL","�׹����ǹ���ĺ��ˣ��㻹�ǲ�Ҫ�����ĺá�\n");
    	set("inquiry", ([
        	
        ]));

    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}
