inherit NPC;
#include <ansi.h>

void create()
{
	set_name("����", ({ "a da"}) );
	set("gender", "����" );
	set("age", 35);
	
	set("long", @LONG
�����Գ��Ƕ�����۵����ˣ�Ҳ����Щ�湦��
LONG
);

	set("title",HIC"��һ��"NOR);
	set("attitude", "peaceful");
        set("combat_exp", 500000);

        set_skill("unarmed", 100);
        set_skill("yiqiforce", 30);
        set_skill("force", 100);
        set_skill("iron-cloth",200);
        
        map_skill("iron-cloth","yiqiforce");
	map_skill("unarmed", "yiqiforce");
    
        set("chat_chance", 1);
        set("chat_msg", ({
             "����˵�����˻�Ԫһ���������Ӿ������µ�һ�ˡ�\n",
        }) );

	setup();
        carry_object("/obj/armor/cloth")->wear();
 
}
