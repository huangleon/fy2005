inherit NPC;
#include <ansi.h>

void create()
{
	set_name("С����",({ "girl" }) );
	set("nickname", HIR"��С�ɰ�"NOR);
        set("gender", "Ů��" );
        set("age", 12);
        set("long", 
"������÷����С���ã���������С�裬һЦ��������ϱ�¶��������\n��С���ѣ����ڲ�ƺ���Ĵ��ı�����ץ�ź�����\n");        
	set("combat_exp", 5000);
        set("int", 15);
        set("chat_chance", 1);
        set("chat_msg", ({
                "С����˵������������ô�����йɾ�ζ�����Ķ��أ���ô�Ҳ����أ�\n",
        }) );

        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("force", 10);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/shoes")->wear();
}
