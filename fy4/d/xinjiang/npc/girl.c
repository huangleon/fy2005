#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "��³����Ů", ({ "pretty girl", "girl" }) );
	set("long", 
"����һλ������Ů����С����������³�������ô���ݰף�ɷ�Ǻÿ���
\n");
	set("attitude", "friendly");
	set("age", 17);
        set("gender", "Ů��" );
	set("combat_exp", 50000);
        set("chat_chance", 15);
        set("chat_msg", ({
                "��³����Ů������������Ŷ����衣\n",
                "��³����Ů�����촽������ʮ��ľ��ķ��\n",
        }) );
	set_skill("unarmed", 1+random(100));
	setup();
        carry_object(__DIR__"obj/skirt")->wear();

}
